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

ULONG64 cheese::gate::gmod(const std::string& name)
{
	printf("[>] " __FUNCTION__ "\n");
	
	const auto ppPeb = offset::ptr_field(offset::_EPROCESS::Peb, this->target_peproc);
	void* pPeb = nullptr;
	this->r0->_RtlCopyMemory(&pPeb, ppPeb, sizeof(void*));
	if (!pPeb) return 0;

	std::cout << "    "; PRINTVAR(pPeb, "%p");

	const auto ppLdr = offset::ptr_field(offset::_PEB::Ldr, pPeb);
	const auto pLdr = this->read_sc<PVOID>(ppLdr);
	if (!pLdr) return 0;

	std::cout << "    "; PRINTVAR(pLdr, "%p");

	const auto pInMemoryOrderModuleList = static_cast<PLIST_ENTRY>(offset::ptr_field(offset::_PEB_LDR_DATA::InMemoryOrderModuleList, pLdr));
	for (auto pListEntry = this->read_sc<PLIST_ENTRY>(&pInMemoryOrderModuleList->Flink);
	     pListEntry != pInMemoryOrderModuleList;
	     pListEntry = this->read_sc<PLIST_ENTRY>(&pListEntry->Flink))
	{
		const auto uLdrDataTableEntryOffset = offset::adr_field(offset::_LDR_DATA_TABLE_ENTRY::InMemoryOrderLinks, nullptr);
		const auto pLdrDataTableEntry = reinterpret_cast<PVOID>(reinterpret_cast<ULONG64>(pListEntry) - uLdrDataTableEntryOffset);
		const auto pBaseDllName = static_cast<_UNICODE_STRING*>(offset::ptr_field(offset::_LDR_DATA_TABLE_ENTRY::BaseDllName, pLdrDataTableEntry));
		if (const auto ulength = this->read_sc<USHORT>(&pBaseDllName->Length); ulength)
		{
			std::wstring wbuf(ulength / sizeof(wchar_t), L'\0');
		
			this->target_mgr->copy_safe(this->self_mgr, wbuf.data(), this->read_sc<void*>(&pBaseDllName->Buffer), ulength);
			
			std::ranges::transform(wbuf, wbuf.begin(), [](const wchar_t & c) -> wchar_t { return std::towlower(c); });
			std::wcout << L"    " << wbuf << std::endl;
			if (std::string(wbuf.begin(), wbuf.end()).find(name) != std::string::npos)
			{
				std::wcout << L"[>] " << wbuf << " == "; std::cout << name << std::endl;
				const auto pDllBase = offset::ptr_field(offset::_LDR_DATA_TABLE_ENTRY::DllBase, pLdrDataTableEntry);
				const auto DllBase = this->read_sc<ULONG64>(pDllBase);
				std::cout << "    "; PRINTVAR(DllBase, "%llx");
				return DllBase;
			}
		}
	}
	return 0;
}

cheese::gate::gate(ring0_exec* r0, phys_mem* phys, const std::string t, const std::string p) : r0(r0), phys(phys)
{
	printf("[+] " __FUNCTION__ "\n");

	this->target_pid = this->pid(p);
	if (!this->target_pid) { printf("obamna sehr kapoot\n"); return; }
	this->target_peproc = this->r0->GetEProcessByPID(this->target_pid);
	if (!this->target_peproc) { printf("obama aeusserst kapoot\n"); return; }

	this->self_mgr = new mem_mgr(this->r0, this->phys, this->r0->GetCR3ByPID(GetCurrentProcessId()));
	this->target_mgr = new mem_mgr(this->r0, this->phys, this->r0->GetCR3ByEprocess(this->target_peproc));
	this->target_base = this->gmod(this->target_name = t);
	
	if (!this->target_base) { printf("obamna kapoot\n"); return; }
}

cheese::gate::~gate()
{
	printf("[-] " __FUNCTION__ "\n");

	delete this->self_mgr;
	delete this->target_mgr;
}

uint64_t cheese::gate::base() const
{
	return this->target_base;
}
