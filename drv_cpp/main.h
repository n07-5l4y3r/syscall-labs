#pragma once

#include <inc.h>

typedef struct worker_queue_entry_params
{
	PHYSICAL_OP_CR3 PhysicalOpCR3;
	PEPROCESS proc;
} worker_queue_entry_params;

NTSTATUS worker_queue_entry(_In_ threads::worker::c_worker* that);