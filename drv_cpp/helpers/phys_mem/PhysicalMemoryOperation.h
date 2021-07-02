#pragma once

#include <inc.h>

namespace helpers::phys_mem
{
	ULONG64 GetProcAddr(const PEPROCESS proc, const char* name);
	
	class __declspec(code_seg("$kerneltext$")) PhysMemOp
	{
		PHYSICAL_OP_CR3 PhysicalOpCR3;
		PhysMemOp();
		static PhysMemOp* that;
	public:
		static PhysMemOp* get();
		~PhysMemOp();
		static ULONG64 get_phys(_In_ PEPROCESS proc, _In_ ULONG64 virt);
		/**
		 * \brief Copy Physical Memory
		 * \param dest Physical Destination Address
		 * \param src  Physical Source Address
		 * \param size Size in Bytes
		 */
		void memcpy_physical(_In_ ULONG64 dest, _In_ ULONG64 src, _In_ SIZE_T size);
	};
}
