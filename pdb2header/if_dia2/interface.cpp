#include "stdafx.h"

#include "interface.h"

void dia2::FindChildren(IDiaSymbol* pParent, LPCOLESTR pName, void(*callback)(IDiaSymbol* pSymbol), enum SymTagEnum SymTag)
{
	IDiaEnumSymbols* pEnumSymbols = NULL;
	IDiaSymbol* pSymbol = NULL;
	ULONG celt = 1;
	if (SUCCEEDED(pParent->findChildren(SymTag, pName, nsNone, &pEnumSymbols)))
		while (SUCCEEDED(pEnumSymbols->Next(1, &pSymbol, &celt)) && (celt == 1))
			callback(pSymbol);
}

void dia2::EnumChildren(IDiaSymbol* pParent, void(*callback)(IDiaSymbol* pSymbol), enum SymTagEnum SymTag)
{
	FindChildren(pParent, NULL, callback, SymTag);
}
