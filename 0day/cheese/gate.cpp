#include <inc.h>
DWORD cheese::gate::pid(std::string exe)
{
	PROCESSENTRY32 entry;
	entry.dwSize = sizeof(PROCESSENTRY32);

	HANDLE snapshot = CreateToolhelp32Snapshot(TH32CS_SNAPPROCESS, NULL);

	if (Process32First(snapshot, &entry) == TRUE)
	{
		while (Process32Next(snapshot, &entry) == TRUE)
		{
			auto as = std::wstring(exe.begin(), exe.end());
			if (StrCmpIW(entry.szExeFile, as.c_str()) == 0)
			{
				return entry.th32ProcessID;
			}
		}
	}

	CloseHandle(snapshot);
	return 0;
}

uint64_t cheese::gate::gmod(const std::string& name)
{
	const auto ppPeb = offset::ptr_field(offset::_EPROCESS::Peb, this->target_peproc);
	const auto pPeb = this->read<PVOID>(ppPeb);
	//PVOID pPeb = nullptr;
	//this->phys->gate->R0_RtlCopyMemory(&pPeb, ppPeb, sizeof(PVOID));
	if (!pPeb) return 0;

	const auto ppLdr = offset::ptr_field(offset::_PEB::Ldr, pPeb);
	const auto pLdr = this->read<PVOID>(ppLdr);
	if (!pLdr) return 0;

	const auto pInMemoryOrderModuleList = static_cast<PLIST_ENTRY>(offset::ptr_field(offset::_PEB_LDR_DATA::InMemoryOrderModuleList, pLdr));
	for (auto pListEntry = this->read<PLIST_ENTRY>(&pInMemoryOrderModuleList->Flink);
	     pListEntry != pInMemoryOrderModuleList;
	     pListEntry = this->read<PLIST_ENTRY>(&pListEntry->Flink))
	{
		const auto uLdrDataTableEntryOffset = offset::adr_field(offset::_LDR_DATA_TABLE_ENTRY::InMemoryOrderLinks, nullptr);
		const auto pLdrDataTableEntry = reinterpret_cast<PVOID>(reinterpret_cast<ULONG64>(pListEntry) - uLdrDataTableEntryOffset);
		const auto pBaseDllName = static_cast<_UNICODE_STRING*>(offset::ptr_field(offset::_LDR_DATA_TABLE_ENTRY::BaseDllName, pLdrDataTableEntry));
		if (const auto ulength = this->read<USHORT>(&pBaseDllName->Length); ulength)
		{
			std::wstring wbuf(ulength / sizeof(wchar_t), L'\0');
			phys->MEM_CPY(
				this->self_cr3, wbuf.data(),
				this->target_cr3, this->read<PVOID>(&pBaseDllName->Buffer),
				ulength);
			std::ranges::transform(wbuf, wbuf.begin(), [](const wchar_t & c) -> wchar_t { return std::towlower(c); });
			if (std::string(wbuf.begin(), wbuf.end()).find(name) != std::string::npos)
			{
				const auto pDllBase = offset::ptr_field(offset::_LDR_DATA_TABLE_ENTRY::DllBase, pLdrDataTableEntry);
				const auto DllBase = this->read<PVOID>(pDllBase);
				return reinterpret_cast<uint64_t>(DllBase);
			}
		}
	}
	return 0;
}

cheese::gate::gate(phys_mem* ph, const std::string t, const std::string p)
{
	this->phys = ph;

	this->target_pid = this->pid(p);
	if (!this->target_pid) { printf("obamna sehr kapoot\n"); return; }
	this->target_peproc = this->phys->GetEProcessByPID(this->target_pid);
	if (!this->target_peproc) { printf("obama äusserst kapoot\n"); return; }
	this->self_cr3 = this->phys->GetCR3ByPID(GetCurrentProcessId());
	if (!this->self_cr3) { printf("obamna sprechlessless\n"); return; }
	this->target_cr3 = this->phys->GetCR3ByEprocess(this->target_peproc);
	if (!this->target_cr3) { printf("obamna seems totally wrong\n"); return; }
	this->target_base = this->gmod(this->target_name = t);
	if (!this->target_base) { printf("obamna kapoot\n"); return; }
}

uint64_t cheese::gate::base()
{
	return this->target_base;
}
