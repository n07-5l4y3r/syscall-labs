#include "ipc_master.h"

std::queue<
	std::pair<
	ipc::shared::tPacketHeader*,
	std::promise<void>
	>*
> ipc::master::queue = {};
std::mutex ipc::master::queue_mtx = std::mutex();
std::atomic<unsigned long long> ipc::master::calls;
std::atomic<unsigned long long> ipc::master::queued;
std::atomic<unsigned long long> ipc::master::done;
ipc::shared::tMultiPacket ipc::master::gate::kernel_buffer;
std::mutex kernel_buffer_mtx = std::mutex();
int ipc::master::gate::st_get_queue()
{
	//printf(" [>] \"" __FUNCTION__ "\"""\n");

	//calls.store(calls + 1);

	if (!kernel_buffer_mtx.try_lock())
	{
		printf("[st_get_queue fail]\n");
		//ExitThread(0xdead);
		return 1;
	}

	if (!kernel_buffer.count)
	{
		if (!queue_mtx.try_lock())
		{
			kernel_buffer_mtx.unlock();
			printf("[queue_mtx fail]\n");
			//ExitThread(0xdead);
			return 2;
		}

		for
			(
				kernel_buffer.count = 0;
				kernel_buffer.count < kernel_buffer.count_max &&
				!queue.empty();
				kernel_buffer.count++)
		{
			//queued.store(queued + 1);
			const auto entry = queue.front();
			queue.pop();
			kernel_buffer.ahead[kernel_buffer.count].handle = reinterpret_cast<unsigned long long>(entry);
			kernel_buffer.ahead[kernel_buffer.count].pdata = entry->first;
		}
		queue_mtx.unlock();
	}
	kernel_buffer_mtx.unlock();

	return 0xDEAD;

	//ExitThread(0x1337);
}

int ipc::master::gate::at_set_promise()
{
	//printf(" [>] \"" __FUNCTION__ "\"""\n");

	//calls.store(calls + 1);
	
	if (!kernel_buffer_mtx.try_lock())
	{
		printf("[kernel_buffer_mtx	at_set_promise fail]\n");
		return 1;
	}

	for
		(
			int index = static_cast<int>(kernel_buffer.count < kernel_buffer.count_max ? kernel_buffer.count : kernel_buffer.count_max) - 1;
			(index = static_cast<int>(kernel_buffer.count) - 1) >= 0;
			kernel_buffer.count--)
	{
		//done.store(done + 1);
		reinterpret_cast<decltype(queue)::value_type>(kernel_buffer.ahead[index].handle)->second.set_value();
		kernel_buffer.ahead[index].handle = 0;
	}
	kernel_buffer.count = 0;

	kernel_buffer_mtx.unlock();

	return 0xDEAD;
}
