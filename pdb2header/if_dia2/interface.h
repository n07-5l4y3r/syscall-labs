#pragma once

#include <inc.h>

namespace dia2
{
	void FindChildren(
		IDiaSymbol* pParent,
		LPCOLESTR pName,
		void (*callback)(IDiaSymbol* pSymbol),
		enum SymTagEnum SymTag = SymTagEnum::SymTagNull);
	void EnumChildren(
		IDiaSymbol* pParent,
		void (*callback)(IDiaSymbol* pSymbol),
		enum SymTagEnum SymTag = SymTagEnum::SymTagNull);
}