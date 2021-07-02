#pragma once

#include <inc.h>

typedef struct _PHYSICAL_OP_CR3
{
	PVOID	pAllocVA_PML4T;
	PVOID	pAllocPA_PML4T;

	PVOID	pAllocVA_PDPT;
	PVOID	pAllocPA_PDPT;

	PVOID	pSystemPML4TMap;

	ULONG64	CR3Generated;
	ULONG64 CR3System;

	ULONG64 CR3BeforeSwitch;
	BOOL	IsContextSwitched;
	BOOL	IsIrqlChanged;
	KIRQL	OriginalIrql;//available if the IsIrqlChanged is true
}PHYSICAL_OP_CR3, * PPHYSICAL_OP_CR3;

#include "PhysicalMemoryOperation.h"