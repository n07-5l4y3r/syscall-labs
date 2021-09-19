#pragma once

#include <inc.h>

class phys_mem
{
	static unsigned char shellcode_exec_phys[];
	static constexpr unsigned shellcode_exec_phys_cr3 = 0x2B;
	static unsigned char shellcode_translate[];
	static unsigned char shellcode_memcpy[];

public:
	ring0_exec* gate;

public:
	ULONG64 GetCR3ByEprocess(const PVOID pEProc) const;
	PVOID GetEProcessByPID(const ULONG64 PID) const;
	ULONG64 GetCR3ByPID(const ULONG64 PID) const;

private:
	static ULONG64 GetCR3Flag(const ULONG64 CR3);
	static ULONG64 ClearCR3Flag(const ULONG64 CR3);
	ULONG64 MmGetVirtualForPhysical(const ULONG64 PhysicalAddress) const;

	ULONG64 r0_CR3_System;
	ULONG64 r0_CR3_PHYS;
	
	ULONG64 r0_PA_System_PML4T;
	ULONG64 r0_VA_System_PML4T;

	ULONG64 r0_VA_PHYS_PML4T;
	ULONG64 r0_PA_PHYS_PML4T;

	ULONG64 r0_VA_PHYS_PDPT;
	ULONG64 r0_PA_PHYS_PDPT;

	PVOID r0_SC_EXEC_PHYS;
	PVOID r0_SC_TRANSLATE;
	PVOID r0_SC_MEMCPY;

	typedef struct _MMVA
	{
		struct /* bitfield */
		{
			/* 0x0000 */ unsigned __int64 Offset : 12;
			/* 0x0000 */ unsigned __int64 PT : 9;
			/* 0x0000 */ unsigned __int64 PDT : 9;
			/* 0x0000 */ unsigned __int64 PDPT : 9;
			/* 0x0000 */ unsigned __int64 PML4T : 9;
			/* 0x0000 */ unsigned __int64 Partition : 16; //User:0x0000 System:0xFFFF
		}; /* bitfield */
	} MMVA, * PMMVA; /* size: 0x0008 */

	typedef struct _MMPDPTE
	{
		struct /* bitfield */
		{
			/* 0x0000 */ unsigned __int64 Valid : 1; /* bit position: 0 */
			/* 0x0000 */ unsigned __int64 Dirty1 : 1; /* bit position: 1 */
			/* 0x0000 */ unsigned __int64 Owner : 1; /* bit position: 2 */
			/* 0x0000 */ unsigned __int64 WriteThrough : 1; /* bit position: 3 */
			/* 0x0000 */ unsigned __int64 CacheDisable : 1; /* bit position: 4 */
			/* 0x0000 */ unsigned __int64 Accessed : 1; /* bit position: 5 */
			/* 0x0000 */ unsigned __int64 Dirty : 1; /* bit position: 6 */
			/* 0x0000 */ unsigned __int64 LargePage : 1; /* bit position: 7 */
			/* 0x0000 */ unsigned __int64 Global : 1; /* bit position: 8 */
			/* 0x0000 */ unsigned __int64 CopyOnWrite : 1; /* bit position: 9 */
			/* 0x0000 */ unsigned __int64 Unused : 1; /* bit position: 10 */
			/* 0x0000 */ unsigned __int64 Write : 1; /* bit position: 11 */
			/* 0x0000 */ unsigned __int64 reserved0 : 18; /* bit position: 12 */
			/* 0x0000 */ unsigned __int64 PageFrameNumber : 18; /* bit position: 30 */
			/* 0x0000 */ unsigned __int64 reserved1 : 4; /* bit position: 48 */
			/* 0x0000 */ unsigned __int64 SoftwareWsIndex : 11; /* bit position: 52 */
			/* 0x0000 */ unsigned __int64 NoExecute : 1; /* bit position: 63 */
		}; /* bitfield */
	} MMPDPTE, * PMMPDPTE; /* size: 0x0008 */

public:

	ULONG64 EX_PHYS(const ULONG64 adr, const ULONG64 P1 = NULL, const ULONG64 P2 = NULL, const ULONG64 P3 = NULL) const;
	ULONG64 VA_2_PA(const ULONG64 CR3, const ULONG64 VA) const;
	ULONG64 MEM_CPY(const ULONG64 PA_Dest, const ULONG64 PA_Src, const SIZE_T Size) const;
	ULONG64 MEM_CPY(const ULONG64 CR3_Dest, const PVOID VA_Dest, const ULONG64 CR3_Src, const PVOID VA_Src, const SIZE_T Size) const;
	
	phys_mem(ring0_exec* gate);
	~phys_mem();
};