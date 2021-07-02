#pragma once

#include <future>
#include <mutex>
#include <queue>

#include "ipc_shared.h"

namespace ipc::master
{
	// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
	// RING3 Synchronization
	// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
	extern std::queue<
		// decltype(queue)::value_type
		std::pair<
			shared::tPacketHeader*,
			std::promise<void>
		>*
	> queue;
	extern std::mutex queue_mtx;
	//
	/*constexpr unsigned _multipacket_count = 10;
	struct tMultiPacket
	{
		unsigned						count = 0;
		const unsigned					count_max = _multipacket_count;
		struct tMultiPacketHeader
		{
			unsigned long long			handle = 0;
			shared::tPacketHeader*		pdata = nullptr;
		}								ahead[_multipacket_count];
	};
	*/
	// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
	// RING0 Exports (Async-Callbacks)
	// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
	extern std::atomic<unsigned long long> queued;
	extern std::atomic<unsigned long long> done;
	extern std::atomic<unsigned long long> calls;
	namespace gate {
		extern "C" __declspec(dllexport) shared::tMultiPacket kernel_buffer;
		// sync (wait for completion)
		// fill kernel_buffer
		extern "C" __declspec(dllexport) int st_get_queue();
		// async (just create thread)
		// copy tMultiPacket
		// free tMultiPacket
		// set promises
		extern "C" __declspec(dllexport) int at_set_promise();
	}
	// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
	// SYNC RING3 -> RING0 -> RING3 CMD
	// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
	template <
		shared::internal::eRequestId id,
		typename req = ipc::shared::tPacket<ipc::shared::internal::eDirection::REQ, id >,
		typename ret = ipc::shared::tPacket<ipc::shared::internal::eDirection::RET, id >
	>
	auto cmd(
		req* _req) ->
		ret*
	{
		//printf(__FUNCTION__"\n");
		queue_mtx.lock();
		
		auto pair = std::make_pair(
			reinterpret_cast<shared::tPacketHeader*>(_req),
			std::promise<void>());
		const auto future = pair.second.get_future();		
		queue.push(&pair);
		//printf("queue_size: %llu\n", queue.size());
		queue_mtx.unlock();
		future.wait();
		return _req->brother;
	}
	template<shared::internal::eRequestId req>
	std::pair
	<
		ipc::shared::tPacket<ipc::shared::internal::REQ, req>,
		ipc::shared::tPacket<ipc::shared::internal::RET, req>
	> alloc_packet()
	{
		auto ret = std::make_pair
		(
			ipc::shared::tPacket<ipc::shared::internal::REQ, req>(),
			ipc::shared::tPacket<ipc::shared::internal::RET, req>()
		);
		ret.first.brother = &ret.second;
		ret.second.brother = &ret.first;
		return ret;
	}
}