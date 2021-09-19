#include <inc.h>

// PVOID exec_phys( PVOID adr, PVOID p1, PVOID p2, PVOID p3 );
unsigned char phys_mem::shellcode_exec_phys[] = { 0x55, 0x48, 0x89, 0xE5, 0x48, 0x83, 0xEC, 0x10, 0x44, 0x0F, 0x20, 0xC0, 0x48, 0x89, 0x45, 0x10, 0x48, 0x83, 0xF8, 0x02, 0x7D, 0x0B, 0x48, 0xC7, 0xC0, 0x02, 0x00, 0x00, 0x00, 0x44, 0x0F, 0x22, 0xC0, 0xFA, 0x0F, 0x20, 0xD8, 0x48, 0x89, 0x45, 0x18, 0x48, 0xB8, 0x88, 0x77, 0x66, 0x55, 0x44, 0x33, 0x22, 0x11, 0x0F, 0x22, 0xD8, 0x49, 0x89, 0xCA, 0x48, 0x89, 0xD1, 0x4C, 0x89, 0xC2, 0x4D, 0x89, 0xC8, 0x48, 0x83, 0xEC, 0x20, 0x41, 0xFF, 0xD2, 0x49, 0x89, 0xC2, 0x48, 0x8B, 0x45, 0x18, 0x0F, 0x22, 0xD8, 0xFB, 0x48, 0x8B, 0x45, 0x10, 0x44, 0x0F, 0x22, 0xC0, 0x4C, 0x89, 0xD0, 0x48, 0x89, 0xEC, 0x5D, 0xC3 };
/*
0:  55                      push   rbp
1:  48 89 e5                mov    rbp,rsp
4:  48 83 ec 10             sub    rsp,0x10
0000000000000008 <check_irql>:
8:  44 0f 20 c0             mov    rax,cr8
c:  48 89 45 10             mov    QWORD PTR [rbp+0x10],rax
10: 48 83 f8 02             cmp    rax,0x2
14: 7d 0b                   jge    21 <disable_int>
0000000000000016 <raise_irql>:
16: 48 c7 c0 02 00 00 00    mov    rax,0x2
1d: 44 0f 22 c0             mov    cr8,rax
0000000000000021 <disable_int>:
21: fa                      cli
0000000000000022 <raise_cr3>:
22: 0f 20 d8                mov    rax,cr3
25: 48 89 45 18             mov    QWORD PTR [rbp+0x18],rax
29: 48 b8 88 77 66 55 44    movabs rax,0x1122334455667788
30: 33 22 11
33: 0f 22 d8                mov    cr3,rax
0000000000000036 <physical>:
36: 49 89 ca                mov    r10,rcx
39: 48 89 d1                mov    rcx,rdx
3c: 4c 89 c2                mov    rdx,r8
3f: 4d 89 c8                mov    r8,r9
42: 48 83 ec 20             sub    rsp,0x20
46: 41 ff d2                call   r10
49: 49 89 c2                mov    r10,rax
000000000000004c <lower_cr3>:
4c: 48 8b 45 18             mov    rax,QWORD PTR [rbp+0x18]
50: 0f 22 d8                mov    cr3,rax
0000000000000053 <enable_int>:
53: fb                      sti
0000000000000054 <lower_irql>:
54: 48 8b 45 10             mov    rax,QWORD PTR [rbp+0x10]
58: 44 0f 22 c0             mov    cr8,rax
5c: 4c 89 d0                mov    rax,r10
5f: 48 89 ec                mov    rsp,rbp
62: 5d                      pop    rbp
63: c3                      ret
 */

// PVOID translate( PVOID cr3, PVOID va )
unsigned char phys_mem::shellcode_translate[] = { 0x55, 0x48, 0x89, 0xE5, 0x48, 0x83, 0xEC, 0x08, 0x48, 0x89, 0xD0, 0x48, 0xC1, 0xE0, 0x10, 0x48, 0xC1, 0xE8, 0x37, 0x48, 0x89, 0x45, 0x28, 0x48, 0x89, 0xD0, 0x48, 0xC1, 0xE0, 0x19, 0x48, 0xC1, 0xE8, 0x37, 0x48, 0x89, 0x45, 0x20, 0x48, 0x89, 0xD0, 0x48, 0xC1, 0xE0, 0x22, 0x48, 0xC1, 0xE8, 0x37, 0x48, 0x89, 0x45, 0x18, 0x48, 0x89, 0xD0, 0x48, 0xC1, 0xE0, 0x2B, 0x48, 0xC1, 0xE8, 0x37, 0x48, 0x89, 0x45, 0x10, 0x48, 0x89, 0xD0, 0x48, 0xC1, 0xE0, 0x37, 0x48, 0xC1, 0xE8, 0x34, 0x48, 0x89, 0x45, 0xF8, 0x49, 0xB8, 0x00, 0xF0, 0xFF, 0xFF, 0xFF, 0xFF, 0x00, 0x00, 0x4C, 0x21, 0xC1, 0x48, 0x8B, 0x45, 0x28, 0x48, 0x8B, 0x0C, 0xC1, 0x4C, 0x21, 0xC1, 0x48, 0x8B, 0x45, 0x20, 0x48, 0x8B, 0x0C, 0xC1, 0x4C, 0x21, 0xC1, 0x48, 0x8B, 0x45, 0x18, 0x48, 0x8B, 0x0C, 0xC1, 0x4C, 0x21, 0xC1, 0x48, 0x8B, 0x45, 0x10, 0x48, 0x8B, 0x0C, 0xC1, 0x4C, 0x21, 0xC1, 0x48, 0x03, 0x4D, 0xF8, 0x48, 0x89, 0xC8, 0x48, 0x89, 0xEC, 0x5D, 0xC3 };
/*
0:  55                      push   rbp
1:  48 89 e5                mov    rbp,rsp
4:  48 83 ec 08             sub    rsp,0x8
0000000000000008 <pml4_i>:
8:  48 89 d0                mov    rax,rdx
b:  48 c1 e0 10             shl    rax,0x10
f:  48 c1 e8 37             shr    rax,0x37
13: 48 89 45 28             mov    QWORD PTR [rbp+0x28],rax
0000000000000017 <pdp_i>:
17: 48 89 d0                mov    rax,rdx
1a: 48 c1 e0 19             shl    rax,0x19
1e: 48 c1 e8 37             shr    rax,0x37
22: 48 89 45 20             mov    QWORD PTR [rbp+0x20],rax
0000000000000026 <pdt_i>:
26: 48 89 d0                mov    rax,rdx
29: 48 c1 e0 22             shl    rax,0x22
2d: 48 c1 e8 37             shr    rax,0x37
31: 48 89 45 18             mov    QWORD PTR [rbp+0x18],rax
0000000000000035 <ptt_i>:
35: 48 89 d0                mov    rax,rdx
38: 48 c1 e0 2b             shl    rax,0x2b
3c: 48 c1 e8 37             shr    rax,0x37
40: 48 89 45 10             mov    QWORD PTR [rbp+0x10],rax
0000000000000044 <off>:
44: 48 89 d0                mov    rax,rdx
47: 48 c1 e0 37             shl    rax,0x37
4b: 48 c1 e8 34             shr    rax,0x34
4f: 48 89 45 f8             mov    QWORD PTR [rbp-0x8],rax
0000000000000053 <msk>:
53: 49 b8 00 f0 ff ff ff    movabs r8,0xfffffffff000
5a: ff 00 00
000000000000005d <pml4_e>:
5d: 4c 21 c1                and    rcx,r8
60: 48 8b 45 28             mov    rax,QWORD PTR [rbp+0x28]
64: 48 8b 0c c1             mov    rcx,QWORD PTR [rcx+rax*8]
0000000000000068 <pdp_e>:
68: 4c 21 c1                and    rcx,r8
6b: 48 8b 45 20             mov    rax,QWORD PTR [rbp+0x20]
6f: 48 8b 0c c1             mov    rcx,QWORD PTR [rcx+rax*8]
0000000000000073 <pdt_e>:
73: 4c 21 c1                and    rcx,r8
76: 48 8b 45 18             mov    rax,QWORD PTR [rbp+0x18]
7a: 48 8b 0c c1             mov    rcx,QWORD PTR [rcx+rax*8]
000000000000007e <ptt_e>:
7e: 4c 21 c1                and    rcx,r8
81: 48 8b 45 10             mov    rax,QWORD PTR [rbp+0x10]
85: 48 8b 0c c1             mov    rcx,QWORD PTR [rcx+rax*8]
0000000000000089 <pte_o>:
89: 4c 21 c1                and    rcx,r8
8c: 48 03 4d f8             add    rcx,QWORD PTR [rbp-0x8]
90: 48 89 c8                mov    rax,rcx
93: 48 89 ec                mov    rsp,rbp
96: 5d                      pop    rbp
97: c3                      ret
*/

// PVOID memcpy( PVOID dest, PVOID src, SIZE_T size )
unsigned char phys_mem::shellcode_memcpy[] = { 0x55, 0x48, 0x89, 0xE5, 0x57, 0x56, 0x49, 0x89, 0xC9, 0x48, 0x89, 0xCF, 0x48, 0x89, 0xD6, 0x4C, 0x89, 0xC1, 0xF3, 0xA4, 0x4C, 0x89, 0xC8, 0x5E, 0x5F, 0x48, 0x89, 0xEC, 0x5D, 0xC3 };
/*
0:  55                      push   rbp
1:  48 89 e5                mov    rbp,rsp
4:  57                      push   rdi
5:  56                      push   rsi
6:  49 89 c9                mov    r9,rcx
9:  48 89 cf                mov    rdi,rcx
c:  48 89 d6                mov    rsi,rdx
f:  4c 89 c1                mov    rcx,r8
12: f3 a4                   rep movs BYTE PTR es:[rdi],BYTE PTR ds:[rsi]
14: 4c 89 c8                mov    rax,r9
17: 5e                      pop    rsi
18: 5f                      pop    rdi
19: 48 89 ec                mov    rsp,rbp
1c: 5d                      pop    rbp
1d: c3                      ret
 */

ULONG64 phys_mem::GetCR3ByEprocess(const PVOID pEProc) const
{
	if (pEProc == nullptr)
		return 0;

	const auto r0_pKProc = offset::ptr_field(offset::_EPROCESS::Pcb, pEProc);
	PRINTVAR(r0_pKProc, "%p");
	const auto r0_pDirectoryTableBase = offset::ptr_field(offset::_KPROCESS::DirectoryTableBase, r0_pKProc);
	PRINTVAR(r0_pDirectoryTableBase, "%p");
	auto DirectoryTableBase = 0ui64;
	gate->R0_RtlCopyMemory(&DirectoryTableBase, r0_pDirectoryTableBase, sizeof(DirectoryTableBase));
	PRINTVAR(DirectoryTableBase, "%llx");
	
	return DirectoryTableBase;
}
PVOID phys_mem::GetEProcessByPID(const ULONG64 PID) const
{
	//check pid
	if (PID == 0) return nullptr;
	PRINTVAR(PID, "%llx");
	//get eprocess
	auto r0_ppEProc = gate->ExAllocatePool(static_cast<unsigned long long>(nt::POOL_TYPE::NonPagedPool), sizeof(PVOID));
	if (const auto r0_PsLookupProcessByProcessId = gate->GetKernelModuleExport(gate->R0_ntoskrnl, "PsLookupProcessByProcessId");
		!NT_SUCCESS(static_cast<NTSTATUS>(gate->ring0_call(
		r0_PsLookupProcessByProcessId,
		PID,
		reinterpret_cast<long long>(r0_ppEProc)))))
	{
		PRINTVAR(r0_ppEProc, "%p");
		gate->ExFreePool(r0_ppEProc);
		return nullptr;
	}
	PVOID pEProc = nullptr;
	gate->R0_RtlCopyMemory(&pEProc, r0_ppEProc, sizeof(PVOID));
	//dereference
	if (const auto r0_ObDereferenceObject = gate->GetKernelModuleExport(gate->R0_ntoskrnl, "ObDereferenceObject"); 
		pEProc != nullptr)
	{
		PRINTVAR(pEProc, "%p");
		gate->ring0_call(r0_ObDereferenceObject, reinterpret_cast<long long>(pEProc));
	}
	gate->ExFreePool(r0_ppEProc);
	return pEProc;
}
ULONG64 phys_mem::GetCR3ByPID(const ULONG64 PID) const
{
	return this->GetCR3ByEprocess(this->GetEProcessByPID(PID));
}

ULONG64 phys_mem::GetCR3Flag(const ULONG64 CR3)
{
	return (CR3 & 0xFFF0000000000FFF);
}
ULONG64 phys_mem::ClearCR3Flag(const ULONG64 CR3)
{
	return (CR3 & ~0xFFF0000000000FFF);
}

ULONG64 phys_mem::MmGetVirtualForPhysical(const ULONG64 PhysicalAddress) const
{
	const auto r0_MmGetVirtualForPhysical = gate->GetKernelModuleExport(gate->R0_ntoskrnl, "MmGetVirtualForPhysical");
	return gate->ring0_call(r0_MmGetVirtualForPhysical,PhysicalAddress);
}

ULONG64 phys_mem::EX_PHYS(const ULONG64 adr, const ULONG64 P1, const ULONG64 P2, const ULONG64 P3) const
{
	return gate->ring0_call(
		reinterpret_cast<ULONG64>(this->r0_SC_EXEC_PHYS),
		adr,
		P1,
		P2,
		P3);
}

ULONG64 phys_mem::VA_2_PA(const ULONG64 CR3, const ULONG64 VA) const
{
	return this->EX_PHYS(
		reinterpret_cast<ULONG64>(this->r0_SC_TRANSLATE),
		CR3,
		VA);
}

ULONG64 phys_mem::MEM_CPY(const ULONG64 PA_Dest, const ULONG64 PA_Src, const SIZE_T Size) const
{
	return this->EX_PHYS(reinterpret_cast<ULONG64>(this->r0_SC_MEMCPY), PA_Dest, PA_Src, Size);
}

ULONG64 phys_mem::MEM_CPY(const ULONG64 CR3_Dest, const PVOID VA_Dest, const ULONG64 CR3_Src, const PVOID VA_Src, const SIZE_T Size) const
{
	const auto PA_Dest = this->VA_2_PA(CR3_Dest, reinterpret_cast<ULONG64>(VA_Dest));
	const auto PA_Src = this->VA_2_PA(CR3_Src, reinterpret_cast<ULONG64>(VA_Src));
	return this->MEM_CPY(PA_Dest, PA_Src, Size);
}

phys_mem::phys_mem(ring0_exec* gate) : gate(gate)
{
	printf("[+] " __FUNCTION__"\n");
	
	//get CR3
	this->r0_CR3_System = GetCR3ByPID(4);
	PRINTVAR(this->r0_CR3_System, "%llx");

	//get PML4T
	this->r0_PA_System_PML4T = ClearCR3Flag(this->r0_CR3_System);
	PRINTVAR(this->r0_PA_System_PML4T, "%llx");
	this->r0_VA_System_PML4T = this->MmGetVirtualForPhysical(r0_PA_System_PML4T);
	PRINTVAR(this->r0_VA_System_PML4T, "%llx");

	const auto r0_MmAllocateNonCachedMemory = gate->GetKernelModuleExport(gate->R0_ntoskrnl, "MmAllocateNonCachedMemory");
	PRINTVAR(r0_MmAllocateNonCachedMemory, "%llx");
	const auto r0_MmGetPhysicalAddress = gate->GetKernelModuleExport(gate->R0_ntoskrnl, "MmGetPhysicalAddress");
	PRINTVAR(r0_MmGetPhysicalAddress, "%llx");

	//allocate PML4T
	this->r0_VA_PHYS_PML4T = gate->ring0_call(r0_MmAllocateNonCachedMemory, 0x1000);
	PRINTVAR(this->r0_VA_PHYS_PML4T, "%llx");
	this->r0_PA_PHYS_PML4T = gate->ring0_call(r0_MmGetPhysicalAddress, this->r0_VA_PHYS_PML4T);
	PRINTVAR(this->r0_PA_PHYS_PML4T, "%llx");

	//allocate PDPT
	this->r0_VA_PHYS_PDPT = gate->ring0_call(r0_MmAllocateNonCachedMemory, 0x1000);
	PRINTVAR(this->r0_VA_PHYS_PDPT, "%llx");
	this->r0_PA_PHYS_PDPT = gate->ring0_call(r0_MmGetPhysicalAddress, this->r0_VA_PHYS_PDPT);
	PRINTVAR(this->r0_PA_PHYS_PDPT, "%llx");
	
	//copy the system space map
	auto pSystemStart = reinterpret_cast<PVOID>(0xFFFF080000000000);
	PRINTVAR(pSystemStart, "%p");
	const auto SystemPML4TStart = reinterpret_cast<PMMVA>(&pSystemStart)->PML4T;
	gate->R0_RtlCopyMemory(
		reinterpret_cast<PVOID>(this->r0_VA_PHYS_PML4T + SystemPML4TStart * sizeof(ULONG64)),
		reinterpret_cast<PVOID>(this->r0_VA_System_PML4T + SystemPML4TStart * sizeof(ULONG64)),
		(512 - SystemPML4TStart) * sizeof(ULONG64)
	);
	
	//make the first address point to my PDPT table
	const auto PML4TE = this->r0_PA_PHYS_PDPT | 0x867; //1000 0110 0111
	gate->R0_RtlCopyMemory(reinterpret_cast<PULONG64>(this->r0_VA_PHYS_PML4T), &PML4TE, sizeof(ULONG64));
	PRINTVAR(PML4TE, "%llx");
	
	//fill the PDPT page table
	ULONG64 CurrentPDPTEntry = 0x9E7; //1001 1110 0111
	for (int i = 0; i < 512; i++)
	{
		reinterpret_cast<PMMPDPTE>(&CurrentPDPTEntry)->PageFrameNumber = i;
		const auto PDPTE = this->r0_VA_PHYS_PDPT + i * sizeof(ULONG64);
		gate->R0_RtlCopyMemory(reinterpret_cast<PULONG64>(PDPTE), &CurrentPDPTEntry, sizeof(ULONG64));
	}
	
	//generate CR3
	const auto SystemCR3Flag = GetCR3Flag(this->r0_CR3_System);
	this->r0_CR3_PHYS = this->r0_PA_PHYS_PML4T | SystemCR3Flag;
	PRINTVAR(r0_CR3_PHYS, "%llx");

	this->r0_SC_EXEC_PHYS = gate->ExAllocatePool(static_cast<unsigned long long>(nt::POOL_TYPE::NonPagedPool), sizeof(phys_mem::shellcode_exec_phys));
	*reinterpret_cast<unsigned long long*>(phys_mem::shellcode_exec_phys + phys_mem::shellcode_exec_phys_cr3) = this->r0_CR3_PHYS;
	gate->R0_RtlCopyMemory(this->r0_SC_EXEC_PHYS, phys_mem::shellcode_exec_phys, sizeof(phys_mem::shellcode_exec_phys));
	PRINTVAR(r0_SC_EXEC_PHYS, "%p");

	this->r0_SC_TRANSLATE = gate->ExAllocatePool(static_cast<unsigned long long>(nt::POOL_TYPE::NonPagedPool), sizeof(phys_mem::shellcode_translate));
	gate->R0_RtlCopyMemory(this->r0_SC_TRANSLATE, phys_mem::shellcode_translate, sizeof(phys_mem::shellcode_translate));
	PRINTVAR(r0_SC_TRANSLATE, "%p");

	this->r0_SC_MEMCPY = gate->ExAllocatePool(static_cast<unsigned long long>(nt::POOL_TYPE::NonPagedPool), sizeof(phys_mem::shellcode_memcpy));
	gate->R0_RtlCopyMemory(this->r0_SC_MEMCPY, phys_mem::shellcode_memcpy, sizeof(phys_mem::shellcode_memcpy));
	PRINTVAR(r0_SC_MEMCPY, "%p");
}

phys_mem::~phys_mem()
{
	printf("[-] " __FUNCTION__ "\n");
	
	const auto r0_MmFreeNonCachedMemory = gate->GetKernelModuleExport(gate->R0_ntoskrnl, "MmFreeNonCachedMemory");
	PRINTVAR(r0_MmFreeNonCachedMemory, "%llx");
	
	gate->ExFreePool(this->r0_SC_TRANSLATE);
	gate->ExFreePool(this->r0_SC_EXEC_PHYS);
	gate->ring0_call(r0_MmFreeNonCachedMemory, this->r0_VA_PHYS_PML4T, 0x1000);
	gate->ring0_call(r0_MmFreeNonCachedMemory, this->r0_VA_PHYS_PDPT, 0x1000);
}
