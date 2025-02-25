#pragma once

#include <inc.h>

class ring0_exec
{
	static unsigned char shellcode_get_qword[];
	static unsigned char shellcode_set_qword[];
	static unsigned char shellcode[];
	static constexpr unsigned R0_Callgate_Mag = 0 + 2;
	static constexpr unsigned R0_Callgate_Org = 15 + 2;
	static constexpr unsigned R0_Callgate_Ptr = 96 + 2;
	static constexpr unsigned R0_P_ExFreePool = 113 + 2;
	static constexpr unsigned R0_O_unhookself = 81;

public:
	PVOID r0_SC_GET_QWORD;
	PVOID r0_SC_SET_QWORD;

private:
	static constexpr uint64_t magic = 0x1337133713371337;

	uintptr_t R3_syscall = 0;
	uintptr_t R0_NtBlt_RIP_GATE_OFFSET = 0;
	uintptr_t R0_NtBlt_RIP_GATE_PTR = 0;
	uintptr_t R0_NtBlt_RIP_GATE = 0;
	uintptr_t R0_CallG_RIP_GATE = 0;
	uintptr_t R0_Fnc_UnhookSelf = 0;

	inline static bool is_hooked = false;

	// winapi
	HMODULE(*R3_GetModuleHandleA)(LPCSTR lpModuleName);
	FARPROC(*R3_GetProcAddress)(HMODULE hModule, LPCSTR lpProcName);

	// intel_driver
	HANDLE hDevIntel = nullptr;
public:
	uint64_t(*R3_GetKernelModuleAddress)(const std::string& module_name) = nullptr;
private:
	uint64_t(*DRV_GetKernelModuleExport)(HANDLE device_handle, uint64_t kernel_module_base, const std::string& function_name);
	bool (*DRV_ReadMemory)(HANDLE device_handle, uint64_t address, void* buffer, uint64_t size);
	bool (*DRV_WriteMemory)(HANDLE device_handle, uint64_t address, void* buffer, uint64_t size);
	uint64_t(*DRV_AllocatePool)(HANDLE device_handle, nt::POOL_TYPE pool_type, uint64_t size);

	//ntoskrnl
public:
	uint64_t R0_ntoskrnl = 0;
private:
	uint64_t R0_ExFreePool = 0;
	uint64_t R0_RtlCopyMemory = 0;
	uint64_t R0_ExAllocatePool = 0;
	uint64_t r0_ObDereferenceObject;
	uint64_t r0_PsLookupProcessByProcessId;

public:
	long long call(
		const long long ptr,
		const long long rcx = 0, const long long rdx = 0,
		const long long r8 = 0, const long long r9 = 0,
		const long p5 = 0, const long p6 = 0) const;
	PVOID _RtlCopyMemory(void* Dest, const void* Src, const size_t Size) const;
	unsigned long long _GetKernelModuleExport(unsigned long long kernel_module_base, const std::string& function_name) const;
	PVOID _ExAllocatePool(const unsigned long long PoolType, const SIZE_T NumberOfBytes) const;
	void _ExFreePool(PVOID P) const;

public:
	ULONG64 G_R0_QWORD(const ULONG64 VA) const;
	void    S_R0_QWORD(const ULONG64 VA, const ULONG64 var) const;

public:
	ULONG64 GetCR3ByEprocess(const PVOID pEProc) const;
	PVOID GetEProcessByPID(const ULONG64 PID) const;
	ULONG64 GetCR3ByPID(const ULONG64 PID) const;

public:
	ring0_exec(
		HMODULE(*get_module_handle_a)(const char*),
		FARPROC(*get_proc_address)(HINSTANCE__*, const char*),
		HANDLE handle,
		uint64_t(*get_kernel_module_address)(const std::string&),
		uint64_t(*get_kernel_module_export)(void*, uint64_t, const std::string&),
		bool(*read_memory)(void*, unsigned long long, void*, unsigned long long),
		bool(*write_memory)(void*, unsigned long long, void*, unsigned long long),
		uint64_t(*allocate_pool)(void*, nt::_POOL_TYPE, uint64_t)
	);
	~ring0_exec();
};