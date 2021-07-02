#include "PhysicalMemoryOperation.h"

extern NTSTATUS CreatePhysicalOpCR3BySystemCR3(ULONG64 SystemCR3, PPHYSICAL_OP_CR3 pPhysicalOpCR3);
extern NTSTATUS ContextVirtualToPhysical(PPHYSICAL_OP_CR3 pPhysicalOpCR3);
extern NTSTATUS ContextPhysicalToVirtual(PPHYSICAL_OP_CR3 pPhysicalOpCR3);
extern NTSTATUS FreePhysicalOpCR3(PPHYSICAL_OP_CR3 pPhysicalOpCR3);
extern ULONG64 GetCR3ByEprocess(PEPROCESS pEProc);

template <typename t>
auto is_same(t* X, t* Y)->bool
{
	while (*X && *Y)
	{
		if (*X != *Y)
			return false;
		X++;
		Y++;
	}
	return (*Y == L'\0');
}

ULONG64 helpers::phys_mem::GetProcAddr(const PEPROCESS proc, const char* name)
{
	//DbgPrint(__FUNCTION__);

	ULONG64 found = 0x0;
	if (!proc)
		return found;
	const auto ppeb = *static_cast<PPEB*>(offset::ptr_field(offset::_EPROCESS::Peb, proc));
	KeAttachProcess(proc);
	//DbgPrint("ppeb: %llx", ppeb);
	const auto BASE = *static_cast<ULONG64*>(offset::ptr_field(offset::_PEB::ImageBaseAddress, ppeb));
	const auto DOS = reinterpret_cast<PIMAGE_DOS_HEADER>(BASE);
	//DbgPrint("Dos: %llx", DOS);
	KeDetachProcess();
	if (!DOS) return found;
	KeAttachProcess(proc);
	const auto NT = reinterpret_cast<PIMAGE_NT_HEADERS64>(BASE + DOS->e_lfanew);
	//DbgPrint("NT: %p", NT);
	KeDetachProcess();
	if (!NT) return found;
	KeAttachProcess(proc);
	const auto Optional = &NT->OptionalHeader;
	//DbgPrint("Optional: %p", Optional);
	const auto ExportDirVA = Optional->DataDirectory[IMAGE_DIRECTORY_ENTRY_EXPORT].VirtualAddress;
	//DbgPrint("ExportDirVA: %lx", ExportDirVA);
	const auto ExportDirSize = Optional->DataDirectory[IMAGE_DIRECTORY_ENTRY_EXPORT].Size;
	//DbgPrint("ExportDirSize: %lx", ExportDirSize);
	const auto sections = IMAGE_FIRST_SECTION(NT);
	//DbgPrint("sections: %p", sections);
	//DbgPrint("NumberOfSections: %u", NT->FileHeader.NumberOfSections);
	for (unsigned short s = 0; s < NT->FileHeader.NumberOfSections; s++)
	{
		const auto sectionVA = sections[s].VirtualAddress;
		//DbgPrint("sectionVA: %lx", sectionVA);
		if (
			sectionVA <= ExportDirVA && sectionVA + sections[s].Misc.VirtualSize >= ExportDirVA + ExportDirSize)
		{
			const auto exports = reinterpret_cast<PIMAGE_EXPORT_DIRECTORY>(BASE + ExportDirVA);
			//DbgPrint("exports: %p", exports);
			//DbgPrint("NumberOfNames: %lx", exports->NumberOfNames);
			const auto pAddressOfNames = reinterpret_cast<PULONG>(BASE + exports->AddressOfNames);
			const auto pAddressOfNameOrdinals = reinterpret_cast<PWORD>(BASE + exports->AddressOfNameOrdinals);
			const auto pAddressOfFunctions = reinterpret_cast<PULONG>(BASE + exports->AddressOfFunctions);
			//DbgPrint("pAddressOfNames: %p", pAddressOfNames);
			//DbgPrint("pAddressOfNameOrdinals: %p", pAddressOfNameOrdinals);
			//DbgPrint("pAddressOfFunctions: %p", pAddressOfFunctions);
			for (auto n = 0ul; n < exports->NumberOfNames && !found; n++)
			{
				const auto pname = reinterpret_cast<char*>(BASE + pAddressOfNames[n]);
				//DbgPrint("pname: %p '%s'", pname, pname);
				if (is_same(pname, const_cast<char*>(name))) {
					const auto Ordinal = pAddressOfNameOrdinals[n];
					//DbgPrint("Ordinal: %u", Ordinal);
					const auto Offset = pAddressOfFunctions[Ordinal];
					//DbgPrint("Offset: %lx", Offset);
					const auto Address = BASE + Offset;
					//DbgPrint("Address: %llx", Address);
					found = Address;
				}
			}
			break;
		}
	}
	KeDetachProcess();
	return found;
}


helpers::phys_mem::PhysMemOp::PhysMemOp() : PhysicalOpCR3()
{
	//DbgPrint(" > " __FUNCTION__);

	RtlSecureZeroMemory(&this->PhysicalOpCR3, sizeof(this->PhysicalOpCR3));
}
helpers::phys_mem::PhysMemOp* helpers::phys_mem::PhysMemOp::that = nullptr;
helpers::phys_mem::PhysMemOp* helpers::phys_mem::PhysMemOp::get()
{
	if (that == nullptr) {
		if (NTSTATUS status = STATUS_SUCCESS; !NT_SUCCESS(status = CreatePhysicalOpCR3BySystemCR3(GetCR3ByEprocess(PsInitialSystemProcess), &(that = new helpers::phys_mem::PhysMemOp())->PhysicalOpCR3))) {
			//DbgPrint(" ! [ERROR] CreatePhysicalOpCR3BySystemCR3 %#lx", status);
			that = nullptr;
		}
	}
	return that;
}
helpers::phys_mem::PhysMemOp::~PhysMemOp()
{
	//DbgPrint(" > " __FUNCTION__);

	if (that != nullptr && that == this)
		that = nullptr;
	if (NTSTATUS status = STATUS_SUCCESS; !NT_SUCCESS(status = FreePhysicalOpCR3(&this->PhysicalOpCR3))) {
		//DbgPrint(" ! [ERROR] FreePhysicalOpCR3 %#lx", status);
	}
	RtlSecureZeroMemory(&this->PhysicalOpCR3, sizeof(this->PhysicalOpCR3));
	//_cpp_class_delete_helper(this, sizeof(PhysMemOp), 2);
}

ULONG64 helpers::phys_mem::PhysMemOp::get_phys(PEPROCESS proc, ULONG64 virt)
{
	//DbgPrint(" > " __FUNCTION__);
	KeAttachProcess(proc);

	const ULONG64 ret = MmGetPhysicalAddress(reinterpret_cast<PVOID>(virt)).QuadPart;

	KeDetachProcess();

	//DbgPrint("%p(%p) == %#llx\n", proc, virt, ret);

	return ret;
}

void helpers::phys_mem::PhysMemOp::memcpy_physical(_In_ ULONG64 dest, _In_ ULONG64 src, _In_ SIZE_T size)
{
	if (NT_SUCCESS(ContextVirtualToPhysical(&PhysicalOpCR3)))
	{
		//DbgPrint(" > " __FUNCTION__);
		//if (size != 2) DbgPrint("%# llx -> [%# llx] -> %# llx\n", src, size, dest);

		//for (SIZE_T i = 0; i < size; i++)
		//	*(static_cast<UCHAR*>(reinterpret_cast<void*>(dest)) + i) = *(static_cast<UCHAR*>(reinterpret_cast<void*>(src)) + i);

		memcpy(reinterpret_cast<void*>(dest), reinterpret_cast<void*>(src), size);

		ContextPhysicalToVirtual(&PhysicalOpCR3);
	}
}