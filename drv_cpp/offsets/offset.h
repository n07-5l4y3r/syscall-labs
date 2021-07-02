#pragma once

namespace offset {

	typedef struct {
		unsigned long byte;
		unsigned long bytes;
		unsigned char bit;
		unsigned char bits;
	} s_field;

	inline bool is_bitfield(const s_field field_info)
	{
		return field_info.bits;
	}

	inline unsigned long long adr_field(const s_field field_info, void* pBase) {
		if (is_bitfield(field_info))
			return 0;
		return reinterpret_cast<unsigned long long>(pBase) + field_info.byte;
	}

	inline void* ptr_field(const s_field field_info, void* pBase) {
		if (is_bitfield(field_info))
			return nullptr;
		return reinterpret_cast<void*>(reinterpret_cast<unsigned long long>(pBase) + field_info.byte);
	}

	template <typename tRet>
	bool copy_field(const s_field field_info, void* pBase, tRet* pRet) {
		if (!pRet)
			return false;
		if (sizeof(tRet) == -1)
			return false;
		if (!memcpy(pRet, static_cast<char*>(pBase) + field_info.byte, field_info.bytes))
			return false;
		if (is_bitfield(field_info))
		{
			const auto a_mask_bits = field_info.bytes * 8;			// all  bits
			auto l_mask_bits = a_mask_bits - field_info.bits;	// left bits to be yeeted 
			auto r_mask_bits = field_info.bit;
			tRet& rRet = *pRet;
			//rRet <<= l_mask_bits;
			//rRet >>= l_mask_bits;
			rRet >>= r_mask_bits;
		}
		return true;
	}

	namespace _LDR_DATA_TABLE_ENTRY
	{
		extern const s_field DllBase;
		extern const s_field EntryPoint;
		extern const s_field SizeOfImage;
		extern const s_field FullDllName;
		extern const s_field BaseDllName;
		extern const s_field InMemoryOrderLinks;
	}

	namespace _PEB_LDR_DATA
	{
		extern const s_field InMemoryOrderModuleList;
	}

	namespace _PEB
	{
		extern const s_field ImageBaseAddress;
		extern const s_field Ldr;
	}

	namespace _EPROCESS {
		extern const s_field Pcb;
		extern const s_field UniqueProcessId;
		extern const s_field ActiveProcessLinks;
		extern const s_field ObjectTable;
		extern const s_field ImageFileName;
		extern const s_field Peb;
	}

	namespace _KPROCESS {
		extern const s_field DirectoryTableBase;
	}

	namespace _HANDLE_TABLE {
		extern const s_field HandleTableList;
		extern const s_field ActualEntry;
	}

	namespace _HANDLE_TABLE_ENTRY {
		extern const s_field ObjectPointerBits;
		extern const s_field GrantedAccessBits;
		extern const s_field NextFreeHandleEntry;
	}

	namespace _OBJECT_HEADER {
		extern const s_field TypeIndex;
		extern const s_field Body;
	}

	namespace _OBJECT_TYPE {
		extern const s_field Name;
	}

	namespace _PUBLIC {
		extern const s_field ObTypeIndexTable;
		extern const s_field ObHeaderCookie;
	}
}