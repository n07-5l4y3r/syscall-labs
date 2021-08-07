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

	namespace _TEB
	{
		extern const s_field GdiBatchCount;
	}
	
	namespace _PUBLIC
	{
		extern const s_field NtGdiEngTransparentBlt;
	}

}