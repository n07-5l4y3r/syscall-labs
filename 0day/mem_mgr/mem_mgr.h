#pragma once

#include <inc.h>

class mem_mgr
{
	
private:
	const ring0_exec* r0 = nullptr;
	const phys_mem* phys = nullptr;
	const uint64_t cr3 = 0;

private:
	static const unsigned char SC_copy_size_pre[];
	PVOID r0_SC_copy_size_pre;
	static const UINT64 r0_SC_copy_page_offset = 0x5e;
	PVOID r0_SC_copy_page;
	static const UINT64 r0_SC_get_pte_offset = 0x1ee;
	PVOID r0_SC_get_pte;

private:
	ULONG64 r0_MmGetVirtualForPhysical;
	ULONG64 r0_MmIsAddressValid;
	ULONG64 r0_KeFlushCurrentTbImmediately;
	ULONG64 r0_MmAllocateContiguousMemory;
	ULONG64 r0_MmFreeContiguousMemory;

public:
	ULONG64 _MmGetVirtualForPhysical(const ULONG64 PA) const;
	BOOLEAN _MmIsAddressValid(const ULONG64 VA) const;
	__int64 _KeFlushCurrentTbImmediately() const;
	ULONG64 _MmAllocateContiguousMemory(SIZE_T NumberOfBytes, ULONG64 HighestAcceptableAddress = MAXULONG64) const;
	void    _MmFreeContiguousMemory(PVOID BaseAddress) const;

private:
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
	typedef uint64_t _MMPTE, _MMPTE_HARDWARE, _MMPTE_SOFTWARE, _MMPTE_TRANSITION, _MMPTE_PROTOTYPE;

private:
	template <typename tRet>
	static tRet bit_field(const offset::s_field& field, void* p)
	{
		unsigned char mask_buf[sizeof(tRet)] = {};
		auto &mask = *reinterpret_cast<tRet*>(mask_buf);
		mask = ~mask;			// set all bits == 1
		mask <<= field.bits;	// set used bits == 0
		mask = ~mask;			// invert bits
		auto rval = *reinterpret_cast<tRet*>(reinterpret_cast<unsigned long long>(p) + field.byte);
		rval >>= field.bit;		// shift used bits to the right
		rval &= mask;			// set unused bits == 0
		return rval;
	}

public:
	void	set_pfn_PA(const ULONG64 PA_PTE, const ULONG64 Orig, const ULONG64 PFN) const;

public:
	struct  EXTENDED_INFO
	{
		_MMPTE  PTE_QWORD;
		ULONG64 PFN;
		ULONG64 PA_PTE;
		ULONG64 VA_PTE;
	};
	struct PAGE_INFO
	{
		PVOID	base;
		UINT64	offset;
		SIZE_T	size;
		EXTENDED_INFO extended_info;
	};
private:
	static void print_errorcode(const ULONG64 error);

public:
	// aquire page info safe
	PAGE_INFO page_info_virtual(PVOID VA) const;
	// aquire page info unsafe
	PAGE_INFO page_info_physical(PVOID VA) const;
	// aquire page info via shellcode
	PAGE_INFO page_info_shellcode(PVOID VA) const;

public:
	// copy physical memory safe
	bool copy_safe(mem_mgr* mgr_local, PVOID VA_local, PVOID VA_far, SIZE_T bytes, bool write = false) const;
	// copy physical memory unsafe
	bool copy_unsafe(mem_mgr* mgr_local, PVOID VA_local, PVOID VA_far, SIZE_T bytes, bool write = false) const;
	// copy physical memory (unsafe) shellcode
	bool copy_via_shellcod(mem_mgr* mgr_local, PVOID VA_local, PVOID VA_far, SIZE_T bytes, bool write = false) const;

public:
	mem_mgr(ring0_exec* r0, phys_mem* phys, uint64_t cr3);
	~mem_mgr();
	
};
