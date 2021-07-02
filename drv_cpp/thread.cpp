#include "main.h"
void incoming_packet_handler(const PEPROCESS proc, ipc::shared::tPacketHeader* header)
{
	using namespace ipc;

	KeAttachProcess(proc);
	const auto req_id = header->request_id;
	KeDetachProcess();

	static char kebuffer[0x100] = "";
	static UINT64 kebuffer_physical_address = 0;

	if (!kebuffer_physical_address)
	{
		kebuffer_physical_address = helpers::phys_mem::PhysMemOp::get()->get_phys(PsInitialSystemProcess, (ULONG64)kebuffer);
	}

	switch (req_id)
	{
	case shared::internal::eRequestId::ping:
	{
		shared::tbuf<shared::internal::REQ, shared::internal::ping> req_data = {};
		shared::tbuf<shared::internal::RET, shared::internal::ping> ret_data = {};

		KeAttachProcess(proc);
		const auto req_packet = reinterpret_cast<shared::tPacket<shared::internal::REQ, shared::internal::ping>*>(header);
		memcpy(&req_data, &req_packet->data.obj, sizeof(req_data));
		KeDetachProcess();

		[](const decltype(req_data)& req, decltype(ret_data)& ret) -> void
		{
			ret = { "pong" };
		}(req_data, ret_data);

		KeAttachProcess(proc);
		const auto ret_packet = req_packet->brother;
		memcpy(&ret_packet->data.obj, &ret_data, sizeof(ret_data));
		KeDetachProcess();
	}
	break;
	case shared::internal::eRequestId::getmodulebase:
	{
		shared::tbuf<shared::internal::REQ, shared::internal::getmodulebase> req_data = {};
		shared::tbuf<shared::internal::RET, shared::internal::getmodulebase> ret_data = {};

		KeAttachProcess(proc);
		const auto req_packet = reinterpret_cast<shared::tPacket<shared::internal::REQ, shared::internal::getmodulebase>*>(header);
		memcpy(&req_data, &req_packet->data.obj, sizeof(req_data));
		KeDetachProcess();

		auto utils = new func::c_func();

		PEPROCESS peprocess = nullptr;
		const bool bRet = utils->get_proc_name(req_data.target, &peprocess);

		if (peprocess != NULL && bRet)
		{
			ret_data.target = (ULONG64)peprocess;
			auto ret = utils->get_module(req_data.mem_target, peprocess);
			ret_data.max_address = ret.max;
			ret_data.address = ret.base;
		}

		delete utils;

		KeAttachProcess(proc);
		const auto ret_packet = req_packet->brother;
		memcpy(&ret_packet->data.obj, &ret_data, sizeof(ret_data));
		KeDetachProcess();

	}
	break;
	case shared::internal::eRequestId::readmem:
	{
		shared::tbuf<shared::internal::REQ, shared::internal::readmem> req_data = {};
		shared::tbuf<shared::internal::RET, shared::internal::readmem> ret_data = {};

		KeAttachProcess(proc);
		const auto req_packet = reinterpret_cast<shared::tPacket<shared::internal::REQ, shared::internal::readmem>*>(header);
		memcpy(&req_data, &req_packet->data.obj, sizeof(req_data));
		KeDetachProcess();

		if (req_data.size && (req_data.size <= sizeof(decltype(ret_data.buf))))
		{
			/*helpers::phys_mem::PhysMemOp::get()->memcpy_physical(
				helpers::phys_mem::PhysMemOp::get()->get_phys(PsInitialSystemProcess, (ULONG64)ret_data.buf),
				helpers::phys_mem::PhysMemOp::get()->get_phys((PEPROCESS)req_data.target, req_data.address),
				req_data.size
			);*/

			/*ret_data.buf[0] = 'M';
			ret_data.buf[1] = 'Z';*/

			KeEnterGuardedRegion();

			auto b = helpers::phys_mem::PhysMemOp::get()->get_phys((PEPROCESS)req_data.target, req_data.address);

			if (b) helpers::phys_mem::PhysMemOp::get()->memcpy_physical(kebuffer_physical_address, b, req_data.size);

			/*ret_data.read = 2;
			ret_data.buf[0] = 'M';
			ret_data.buf[1] = 'Z';*/

			memcpy(ret_data.buf, kebuffer, req_data.size);
			ret_data.read = req_data.size;

			KeLeaveGuardedRegion();
		}
		else
		{
			//DbgPrint("[FAILED handling] proc: %p, adr: %p, size: %i\n", req_data.target, req_data.address, req_data.size);
			ret_data.read = 0;
		}

		KeAttachProcess(proc);
		const auto ret_packet = req_packet->brother;
		memcpy(&ret_packet->data.obj, &ret_data, sizeof(ret_data));
		KeDetachProcess();

	}
	break;
	case shared::internal::eRequestId::writemem:
	{
		shared::tbuf<shared::internal::REQ, shared::internal::writemem> req_data = {};
		shared::tbuf<shared::internal::RET, shared::internal::writemem> ret_data = {};

		KeAttachProcess(proc);
		const auto req_packet = reinterpret_cast<shared::tPacket<shared::internal::REQ, shared::internal::writemem>*>(header);
		memcpy(&req_data, &req_packet->data.obj, sizeof(req_data));
		KeDetachProcess();

		if (req_data.size && (req_data.size <= sizeof(decltype(req_data.buf))))
		{
			helpers::phys_mem::PhysMemOp::get()->memcpy_physical(
				helpers::phys_mem::PhysMemOp::get()->get_phys((PEPROCESS)req_data.target, req_data.address),
				helpers::phys_mem::PhysMemOp::get()->get_phys(PsInitialSystemProcess, (ULONG64)req_data.buf),
				req_data.size
			);
			ret_data.written = req_data.size;
		}
		else
			ret_data.written = 0;

		KeAttachProcess(proc);
		const auto ret_packet = req_packet->brother;
		memcpy(&ret_packet->data.obj, &ret_data, sizeof(ret_data));
		KeDetachProcess();
	}
	break;
	default:
		break;
	}
}

NTSTATUS worker_queue_entry(_In_ threads::worker::c_worker* that)
{
	const auto memory = static_cast<worker_queue_entry_params*>(that->g_param());
	if (!memory)
		return STATUS_INVALID_PARAMETER;

	if (const auto status = ipc::slave::work(memory->proc, incoming_packet_handler); (status != STATUS_SUCCESS) && (status != STATUS_ALREADY_COMPLETE))
	{
		DbgPrint(" [>] stop""\n");
		delete helpers::phys_mem::PhysMemOp::get();
		free(memory);
		return STATUS_ABANDONED;
	}

	return STATUS_SUCCESS;
}