#pragma once

#include "..\\..\\Client\ipc\ipc_shared.h"

#include <inc.h>

namespace ipc::slave
{
	typedef void t_incoming_packet_handler(const PEPROCESS proc, shared::tPacketHeader* header);
	NTSTATUS work
	(
		const PEPROCESS proc,
		t_incoming_packet_handler* handler
	);
	
}