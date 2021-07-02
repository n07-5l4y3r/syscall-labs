#include "traces.h"
//-----------------------------------------------------------------------------
// Query system information

typedef enum _SYSTEM_INFORMATION_CLASS
{
	SystemBasicInformation,                         // 0x00 SYSTEM_BASIC_INFORMATION
	SystemProcessorInformation,                     // 0x01 SYSTEM_PROCESSOR_INFORMATION
	SystemPerformanceInformation,                   // 0x02
	SystemTimeOfDayInformation,                     // 0x03
	SystemPathInformation,                          // 0x04
	SystemProcessInformation,                       // 0x05
	SystemCallCountInformation,                     // 0x06
	SystemDeviceInformation,                        // 0x07
	SystemProcessorPerformanceInformation,          // 0x08
	SystemFlagsInformation,                         // 0x09
	SystemCallTimeInformation,                      // 0x0A
	SystemModuleInformation,                        // 0x0B SYSTEM_MODULE_INFORMATION
	SystemLocksInformation,                         // 0x0C
	SystemStackTraceInformation,                    // 0x0D
	SystemPagedPoolInformation,                     // 0x0E
	SystemNonPagedPoolInformation,                  // 0x0F
	SystemHandleInformation,                        // 0x10
	SystemObjectInformation,                        // 0x11
	SystemPageFileInformation,                      // 0x12
	SystemVdmInstemulInformation,                   // 0x13
	SystemVdmBopInformation,                        // 0x14
	SystemFileCacheInformation,                     // 0x15
	SystemPoolTagInformation,                       // 0x16
	SystemInterruptInformation,                     // 0x17
	SystemDpcBehaviorInformation,                   // 0x18
	SystemFullMemoryInformation,                    // 0x19
	SystemLoadGdiDriverInformation,                 // 0x1A
	SystemUnloadGdiDriverInformation,               // 0x1B
	SystemTimeAdjustmentInformation,                // 0x1C
	SystemSummaryMemoryInformation,                 // 0x1D
	SystemMirrorMemoryInformation,                  // 0x1E
	SystemPerformanceTraceInformation,              // 0x1F
	SystemObsolete0,                                // 0x20
	SystemExceptionInformation,                     // 0x21
	SystemCrashDumpStateInformation,                // 0x22
	SystemKernelDebuggerInformation,                // 0x23
	SystemContextSwitchInformation,                 // 0x24
	SystemRegistryQuotaInformation,                 // 0x25
	SystemExtendServiceTableInformation,            // 0x26
	SystemPrioritySeperation,                       // 0x27
	SystemPlugPlayBusInformation,                   // 0x28
	SystemDockInformation,                          // 0x29
	SystemPowerInformationNative,                   // 0x2A
	SystemProcessorSpeedInformation,                // 0x2B
	SystemCurrentTimeZoneInformation,               // 0x2C
	SystemLookasideInformation,                     // 0x2D
	SystemTimeSlipNotification,                     // 0x2E
	SystemSessionCreate,                            // 0x2F
	SystemSessionDetach,                            // 0x30
	SystemSessionInformation,                       // 0x31
	SystemRangeStartInformation,                    // 0x32
	SystemVerifierInformation,                      // 0x33
	SystemAddVerifier,                              // 0x34
	SystemSessionProcessesInformation,              // 0x35
	SystemLoadGdiDriverInSystemSpaceInformation,    // 0x36
	SystemNumaProcessorMap,                         // 0x37
	SystemPrefetcherInformation,                    // 0x38
	SystemExtendedProcessInformation,               // 0x39
	SystemRecommendedSharedDataAlignment,           // 0x3A
	SystemComPlusPackage,                           // 0x3B
	SystemNumaAvailableMemory,                      // 0x3C
	SystemProcessorPowerInformation,                // 0x3D
	SystemEmulationBasicInformation,                // 0x3E
	SystemEmulationProcessorInformation,            // 0x3F
	SystemExtendedHanfleInformation,                // 0x40
	SystemLostDelayedWriteInformation,              // 0x41
	SystemBigPoolInformation,                       // 0x42
	SystemSessionPoolTagInformation,                // 0x43
	SystemSessionMappedViewInformation,             // 0x44
	SystemHotpatchInformation,                      // 0x45
	SystemObjectSecurityMode,                       // 0x46
	SystemWatchDogTimerHandler,                     // 0x47
	SystemWatchDogTimerInformation,                 // 0x48
	SystemLogicalProcessorInformation,              // 0x49
	SystemWo64SharedInformationObosolete,           // 0x4A
	SystemRegisterFirmwareTableInformationHandler,  // 0x4B
	SystemFirmwareTableInformation,                 // 0x4C
	SystemModuleInformationEx,                      // 0x4D
	SystemVerifierTriageInformation,                // 0x4E
	SystemSuperfetchInformation,                    // 0x4F
	SystemMemoryListInformation,                    // 0x50
	SystemFileCacheInformationEx,                   // 0x51
	SystemThreadPriorityClientIdInformation,        // 0x52
	SystemProcessorIdleCycleTimeInformation,        // 0x53
	SystemVerifierCancellationInformation,          // 0x54
	SystemProcessorPowerInformationEx,              // 0x55
	SystemRefTraceInformation,                      // 0x56
	SystemSpecialPoolInformation,                   // 0x57
	SystemProcessIdInformation,                     // 0x58
	SystemErrorPortInformation,                     // 0x59
	SystemBootEnvironmentInformation,               // 0x5A SYSTEM_BOOT_ENVIRONMENT_INFORMATION
	SystemHypervisorInformation,                    // 0x5B
	SystemVerifierInformationEx,                    // 0x5C
	SystemTimeZoneInformation,                      // 0x5D
	SystemImageFileExecutionOptionsInformation,     // 0x5E
	SystemCoverageInformation,                      // 0x5F
	SystemPrefetchPathInformation,                  // 0x60
	SystemVerifierFaultsInformation,                // 0x61
	MaxSystemInfoClass                              // 0x67

} SYSTEM_INFORMATION_CLASS, * PSYSTEM_INFORMATION_CLASS;

typedef struct _SYSTEM_MODULE   // Information Class 11
{
	ULONG_PTR Reserved[2];
	PVOID Base;
	ULONG Size;
	ULONG Flags;
	USHORT Index;
	USHORT Unknown;
	USHORT LoadCount;
	USHORT ModuleNameOffset;
	CHAR ImageName[256];
} SYSTEM_MODULE, * PSYSTEM_MODULE;

typedef struct _SYSTEM_MODULE_INFORMATION   // Information Class 11
{
	ULONG_PTR ulModuleCount;
	SYSTEM_MODULE Modules[1];
} SYSTEM_MODULE_INFORMATION, * PSYSTEM_MODULE_INFORMATION;
typedef struct PiDDBCacheEntry
{
	LIST_ENTRY		List;
	UNICODE_STRING	DriverName;
	ULONG			TimeDateStamp;
	NTSTATUS		LoadStatus;
	char			_0x0028[16];
}PIDCacheobj;

NTSTATUS ZwQuerySystemInformation(ULONG InfoClass, PVOID Buffer, ULONG Length, PULONG ReturnLength);

BOOLEAN bDataCompare(const BYTE* pData, const BYTE* bMask, const char* szMask)
{
	for (; *szMask; ++szMask, ++pData, ++bMask)
		if (*szMask == 'x' && *pData != *bMask)
			return 0;
	return (*szMask) == 0;
}
UINT64 findcodepat(UINT64 dwAddress, UINT64 dwLen, BYTE* bMask, const char* szMask)
{
	for (UINT64 i = 0; i < dwLen; i++)
		if (bDataCompare((BYTE*)(dwAddress + i), bMask, szMask))
			return (UINT64)(dwAddress + i);

	return 0;
}
#define MakePtr(cast, ptr, addValue) (cast)( (DWORD64)(ptr) + (DWORD64)(addValue))
uintptr_t dereference(uintptr_t address, unsigned int offset)
{
	if (address == 0)
		return 0;

	return address + (int)((*(int*)(address + offset) + offset) + sizeof(int));
}

bool func::c_func::wipe_unloaded_drivers_log_timestamp()
{
	PRTL_AVL_TABLE PiDDBCacheTable;
	PERESOURCE PiDDBLock;
	PiDDBCacheTable = (PRTL_AVL_TABLE)dereference(findcodepat(this->ntos_base, this->ntos_size, (BYTE*)"\x48\x8d\x0d\x00\x00\x00\x00\xe8\x00\x00\x00\x00\x3d\x00\x00\x00\x00\x0f\x83", "xxx????x????x????xx"), 3);
	PiDDBLock = (PERESOURCE)dereference(findcodepat(this->ntos_base, this->ntos_size, (BYTE*)"\x48\x8D\x0D\x00\x00\x00\x00\xE8\x00\x00\x00\x00\x48\x8B\x0D\x00\x00\x00\x00\x48\x85\xC9\x74\x58", "xxx????x????xxx????xxxxx"), 3);

	if (!PiDDBCacheTable || !PiDDBLock)
	{
		DbgPrint("can't get PiDDB info\n");
		return false;
	}

	uintptr_t entry_address = (uintptr_t)PiDDBCacheTable->BalancedRoot.RightChild + sizeof(RTL_BALANCED_LINKS);
	PIDCacheobj* entry = (PIDCacheobj*)(entry_address);

	UNICODE_STRING fltmgr;
	RtlInitUnicodeString(&fltmgr, L"fltmgr.sys");
	ExAcquireResourceExclusiveLite(PiDDBLock, TRUE);

	if (entry->TimeDateStamp == 0x4840B58D)
	{
		entry->TimeDateStamp = 0x8801E691;
		entry->DriverName = fltmgr;
	}

	ULONG count = 0;

	for (PLIST_ENTRY link = entry->List.Flink; link != entry->List.Blink; link = link->Flink, count++)
	{
		PIDCacheobj* cache_entry = (PIDCacheobj*)(link);

		if (cache_entry->TimeDateStamp == 0x4840B58D)
		{
			DbgPrint("%s) => found target\r\n", __FUNCTION__);

			cache_entry->TimeDateStamp = 0x8801E691 + count;
			cache_entry->DriverName = fltmgr;

			DbgPrint("%s) => target patched\r\n", __FUNCTION__);
		}
	}
	ExReleaseResourceLite(PiDDBLock);
	return true;
}

bool func::c_func::wípe_unloaded_drivers_log_last()//cred Noxius
{
	UINT64 mmUnloadedDriversPtr = findcodepat(this->ntos_base, this->ntos_size, (BYTE*)"\x4C\x8B\x00\x00\x00\x00\x00\x4C\x8B\xC9\x4D\x85\x00\x74", "xx?????xxxxx?x");

	DbgPrint("%s) => %p \r\n", __FUNCTION__, mmUnloadedDriversPtr);

	if (!mmUnloadedDriversPtr) return FALSE;

	UINT64 mmUnloadedDrivers = (UINT64)((PUCHAR)mmUnloadedDriversPtr + *(PULONG)((PUCHAR)mmUnloadedDriversPtr + 3) + 7);
	UINT64 bufferPtr = *(UINT64*)mmUnloadedDrivers;

	PVOID newBuffer = ExAllocatePoolWithTag(NonPagedPoolNx, 0x7D0, 'aSo');

	if (!newBuffer) return FALSE;

	memset(newBuffer, 0, 0x7D0);

	*(UINT64*)mmUnloadedDrivers = (UINT64)newBuffer;
	ExFreePoolWithTag((PVOID)bufferPtr, 'aSo');

	return true;
}

bool func::c_func::get_proc_name(const char* name, PEPROCESS* ppeprocess)
{
	const auto psysproc = PsInitialSystemProcess;
	const auto psyslist = static_cast<LIST_ENTRY*>(offset::ptr_field(offset::_EPROCESS::ActiveProcessLinks, psysproc));
	const auto off_list = reinterpret_cast<ULONG64>(psyslist) - reinterpret_cast<ULONG64>(psysproc);
	int skip = 0;
	if (LIST_ENTRY* pcurlist = psyslist; ppeprocess)
	{
		*ppeprocess = nullptr;
		do {
			const auto pcurproc = reinterpret_cast<const PEPROCESS>(reinterpret_cast<ULONG64>(pcurlist) - off_list);
			const auto pcurname = static_cast<const char*>(offset::ptr_field(offset::_EPROCESS::ImageFileName, pcurproc));

			if (strstr(name, "EscapeFromTa") && strstr(pcurname, "EscapeFromTa") && skip == 0)
			{
				skip = 1;
				continue;
			}

			if (strstr(name, pcurname))
			{
				*ppeprocess = pcurproc;
				skip = 0;
				return true;
			}
		} while ((pcurlist = pcurlist->Flink) != psyslist);
	}
	return false;
}

func::module_data func::c_func::get_module(const wchar_t* name, PEPROCESS peprocess)
{
	if (peprocess == NULL) return {};

	UNICODE_STRING ModuleName = { 0 };
	RtlInitUnicodeString(&ModuleName, name);

	//DbgPrint(" [ searching module ] \"%ls\"" "\n", ModuleName.Buffer);

	KeAttachProcess(peprocess);

	const auto pPeb = *static_cast<PPEB*>(offset::ptr_field(offset::_EPROCESS::Peb, peprocess));

	if (!pPeb)
	{
		KeDetachProcess();
		//DbgPrint(" [-] PEB not found!" "\n");
		//DbgPrint(" [-] Module not found!" "\n");
		return {};
	}

	const auto ldr = *static_cast<void**>(offset::ptr_field(offset::_PEB::Ldr, pPeb));
	
	if (!ldr)
	{
		KeDetachProcess();
		//DbgPrint(" [-] Loader was not initialized in time!" "\n");
		//DbgPrint(" [-] Module not found!" "\n");
		return {};
	}

	const auto inMemoryOrderLinks = static_cast<_LIST_ENTRY*>(offset::ptr_field(offset::_PEB_LDR_DATA::InMemoryOrderModuleList, ldr));

	for (PLIST_ENTRY pListEntry = inMemoryOrderLinks->Flink;
		pListEntry != inMemoryOrderLinks;
		pListEntry = pListEntry->Flink)
	{
		typedef struct
		{
			LIST_ENTRY inLoadOrderList;
		} LDR_DATA_TABLE_ENTRY, * PLDR_DATA_TABLE_ENTRY;

		const auto pEntry = CONTAINING_RECORD(pListEntry, LDR_DATA_TABLE_ENTRY, inLoadOrderList);
		if (pEntry)
		{
			const auto moduleinfo = (PLDR_DATA_TABLE_ENTRY)((unsigned long long)(pEntry) - offset::adr_field(offset::_LDR_DATA_TABLE_ENTRY::InMemoryOrderLinks, 0));

			//const auto FullDllName = static_cast<_UNICODE_STRING*>(offset::ptr_field(offset::_LDR_DATA_TABLE_ENTRY::FullDllName, pEntry));
			const auto BaseDllName = static_cast<_UNICODE_STRING*>(offset::ptr_field(offset::_LDR_DATA_TABLE_ENTRY::BaseDllName, moduleinfo));

			if (BaseDllName->Length)
			{
				//DbgPrint(" [ ] \"%ls\"" "\n", BaseDllName->Buffer);
				//DbgPrint(" [ ] \"%ls\"" "\n", FullDllName->Buffer);

				if (wcsstr(BaseDllName->Buffer, ModuleName.Buffer))
				{
					const auto DllBase = *static_cast<UINT64*>(offset::ptr_field(offset::_LDR_DATA_TABLE_ENTRY::DllBase, moduleinfo));
					const auto DllSize = *static_cast<UINT64*>(offset::ptr_field(offset::_LDR_DATA_TABLE_ENTRY::SizeOfImage, moduleinfo));
					KeDetachProcess();
					//DbgPrint(" [ ] %p" "\n", DllBase);
					return { DllBase, DllBase + DllSize };
				}
			}
		}

	}

	KeDetachProcess();
	//DbgPrint(" [-] Module not found!" "\n");
	return {};
}

void func::c_func::setup()
{
	
}

bool func::c_func::work()
{
	if (!this->wipe_unloaded_drivers_log_timestamp())    return false;
	if (!this->wípe_unloaded_drivers_log_last())         return false;
	return true;
}
