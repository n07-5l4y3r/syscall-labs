#pragma once

#include <inc.h>

/*
 *
 *inline unsigned char HexNib(const char c)
	{
		if ('0' <= c && c <= '9')
			return static_cast<unsigned char>(c - '0');
		if ('A' <= c && c <= 'F')
			return static_cast<unsigned char>(c - 'A' + 10);
		if ('a' <= c && c <= 'f')
			return static_cast<unsigned char>(c - 'a' + 10);
		return static_cast<unsigned char>(-1);
	}
	inline unsigned char HexByte(const char c[2])
	{
		const auto nib1 = HexNib(c[0]);
		if (static_cast<signed>(nib1) < 0)
			return 0;
		
		const auto nib2 = HexNib(c[1]);
		if (static_cast<signed>(nib2) < 0)
			return 0;
		
		return static_cast<unsigned char>((nib1 << 4) + nib2);
	}
 * 
 */

namespace n_pattern
{
	union uPatternByte
	{
		unsigned char		byte;
		struct tPatternByte
		{
			unsigned char	byte;
			bool			mask;
		}					obj;
		signed short		sig;
	};
	constexpr uPatternByte MASK = { .obj={.mask=true} };
	const uPatternByte pat1[] = { {'\x13'}, {'\x37'}, MASK, MASK,  };
	
	unsigned long long find(
		const unsigned long long & min,
		const unsigned long long & max,
		const unsigned long long & len,
		const uPatternByte* & pat
	)
	{
		unsigned long long out = 0;
		auto ptr = reinterpret_cast<unsigned char*>(min);
		for (unsigned long long idx_pat = 0; idx_pat < len && reinterpret_cast<unsigned long long>(ptr) < max; ptr++)
		{
			if (pat[idx_pat].obj.mask || *ptr == pat[idx_pat].obj.byte)
				idx_pat++;
			else
				idx_pat = 0;
			if (idx_pat == len)
			{
				out = reinterpret_cast<unsigned long long>(ptr) - len + 1;
				break;
			}
		}
		return out;
	}
	
}