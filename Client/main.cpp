// DirectDrawFun.cpp

#include <inc.hpp>

class c_phys_helper
{
public:
	template<typename T>
	static T phys_read(UINT64 address, UINT64 target)
	{
		auto [req_readmem, ret_readmem] = ipc::master::alloc_packet<ipc::shared::internal::readmem>();
		req_readmem.data.obj.target = target;
		req_readmem.data.obj.address = address;
		req_readmem.data.obj.size = sizeof T;

		if (&ret_readmem == ipc::master::cmd<ipc::shared::internal::readmem>(&req_readmem))
		{
			//printf("[%s		%llu	ms] rcv size: %lu\n", __FUNCTION__, std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::microseconds(took_time)).count(), ret_readmem.data.obj.read);
			return *(T*)(ret_readmem.data.obj.buf);
		}
		return {};
	}
	template<typename T>
	static bool phys_write(UINT64 address, UINT64 target, T buf)
	{
		auto [req_writemem, ret_writemem] = ipc::master::alloc_packet<ipc::shared::internal::writemem>();
		req_writemem.data.obj.target = target;
		req_writemem.data.obj.address = address;
		req_writemem.data.obj.size = sizeof T;

		memcpy(req_writemem.data.obj.buf, (void*)&buf, sizeof(buf));

		if (&ret_writemem == ipc::master::cmd<ipc::shared::internal::writemem>(&req_writemem))
		{
			return true;
		}
		return false;
	}
};

int thread(std::promise<void>* shutdown_promise, std::future<void> shutdown)
{

	//example ping
	//auto [ping, pong] = ipc::master::alloc_packet<ipc::shared::internal::ping>();
	//strcpy_s(ping.data.obj.data, "PING");
	//if (&pong == ipc::master::cmd<ipc::shared::internal::ping>(&ping))
	//{
	//	std::cout << "ping.first: " << ping.data.obj.data << " == " << pong.brother->data.obj.data << std::endl;
	//	std::cout << "ping.second: " << pong.data.obj.data << " == " << ping.brother->data.obj.data << std::endl;
	//}
	////get module of explorer.exe
	//auto [req_getmodule, ret_getmodule] = ipc::master::alloc_packet<ipc::shared::internal::getmodulebase>();
	//strcpy_s(req_getmodule.data.obj.target, "explorer.exe");
	//wcscpy_s(reinterpret_cast<wchar_t*>(req_getmodule.data.obj.mem_target), 0xF, L"mlang.dll");
	//if (&ret_getmodule == ipc::master::cmd<ipc::shared::internal::getmodulebase>(&req_getmodule))
	//{
	//	printf("[rcv getmodule] base of target is: %llx\n", ret_getmodule.data.obj.address);
	//	printf("                target base is:    %llx\n", ret_getmodule.data.obj.target);
	//}
	////
	//{
	//	auto [req_readmem, ret_readmem] = ipc::master::alloc_packet<ipc::shared::internal::readmem>();
	//	req_readmem.data.obj.target = ret_getmodule.data.obj.target;
	//	req_readmem.data.obj.address = ret_getmodule.data.obj.address;
	//	req_readmem.data.obj.size = 2;
	//	if (&ret_readmem == ipc::master::cmd<ipc::shared::internal::readmem>(&req_readmem))
	//	{
	//		printf("[rcv readmem] buffer length is: %lu\n", ret_readmem.data.obj.read);
	//		printf("              \"%c%c\"\n", ret_readmem.data.obj.buf[0], ret_readmem.data.obj.buf[1]);
	//	}
	//}
	////
	//{
	//	auto [req_writemem, ret_writemem] = ipc::master::alloc_packet<ipc::shared::internal::writemem>();
	//	req_writemem.data.obj.target = ret_getmodule.data.obj.target;
	//	req_writemem.data.obj.address = ret_getmodule.data.obj.address;
	//	req_writemem.data.obj.size = 2;
	//	req_writemem.data.obj.buf[0] = 'Z';
	//	req_writemem.data.obj.buf[1] = 'M';
	//	if (&ret_writemem == ipc::master::cmd<ipc::shared::internal::writemem>(&req_writemem))
	//	{
	//		printf("[rcv writemem] written: %lu\n", ret_writemem.data.obj.written);
	//	}
	//}
	////
	//{
	//	auto [req_readmem, ret_readmem] = ipc::master::alloc_packet<ipc::shared::internal::readmem>();
	//	req_readmem.data.obj.target = ret_getmodule.data.obj.target;
	//	req_readmem.data.obj.address = ret_getmodule.data.obj.address;
	//	req_readmem.data.obj.size = 2;
	//	if (&ret_readmem == ipc::master::cmd<ipc::shared::internal::readmem>(&req_readmem))
	//	{
	//		printf("[rcv readmem] buffer length is: %lu\n", ret_readmem.data.obj.read);
	//		printf("              \"%c%c\"\n", ret_readmem.data.obj.buf[0], ret_readmem.data.obj.buf[1]);
	//	}
	//}
	////
	//auto [req_shutdown, ret_shutdown] = ipc::master::alloc_packet<ipc::shared::internal::shutdown>();
	//req_shutdown.data.obj.done = false;
	//if (&ret_shutdown == ipc::master::cmd<ipc::shared::internal::shutdown>(&req_shutdown))
	//{
	//	std::cout << "req_shutdown: " << req_shutdown.data.obj.done << " == " << ret_shutdown.brother->data.obj.done << std::endl;
	//	std::cout << "ret_shutdown: " << ret_shutdown.data.obj.done << " == " << req_shutdown.brother->data.obj.done << std::endl;
	//}
	//shutdown_promise->set_value();

	return 0;
}

int main()
{
	printf(" > Init...\n");

	auto shutdown = std::promise<void>();

	auto future = std::async(std::launch::async, thread, &shutdown, shutdown.get_future());

	future.get();

	printf("\n");
	printf(" > Quitting...\n");

	shutdown.set_value();

	system("pause");

	return 0;
}