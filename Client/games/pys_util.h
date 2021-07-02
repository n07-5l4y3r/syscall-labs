#pragma once
#include <inc.hpp>
namespace games
{
	class c_phys_util : public s<c_phys_util>
	{
	public:
		UINT64		target;
		UINT64		max_address;
		UINT64		base;

		template<typename T>
		T phys_read(UINT64 address)
		{
			auto [req_readmem, ret_readmem] = ipc::master::alloc_packet<ipc::shared::internal::readmem>();
			req_readmem.data.obj.target = target;
			req_readmem.data.obj.address = address;
			req_readmem.data.obj.size = sizeof T;

			if (&ret_readmem == ipc::master::cmd<ipc::shared::internal::readmem>(&req_readmem))
			{
				//printf("[%s		%llu	ms] rcv size: %lu\n", __FUNCTION__, std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::microseconds(took_time)).count(), ret_readmem.data.obj.read);
				if (req_readmem.data.obj.size != ret_readmem.data.obj.read)
				{
					printf("[-] failed read operation\n");
					return {};
				}
				return *(T*)(ret_readmem.data.obj.buf);
			}
			else return {};
		}
		template<typename T>
		T phys_read_sized(UINT64 address, uint32_t s)
		{
			auto [req_readmem, ret_readmem] = ipc::master::alloc_packet<ipc::shared::internal::readmem>();
			req_readmem.data.obj.target = target;
			req_readmem.data.obj.address = address;
			req_readmem.data.obj.size = s;

			if (&ret_readmem == ipc::master::cmd<ipc::shared::internal::readmem>(&req_readmem))
			{
				//printf("[%s		%llu	ms] rcv size: %lu\n", __FUNCTION__, std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::microseconds(took_time)).count(), ret_readmem.data.obj.read);
				if (req_readmem.data.obj.size != ret_readmem.data.obj.read)
				{
					printf("[-] failed read operation\n");
					return {};
				}
				return *(T*)(ret_readmem.data.obj.buf);
			}
			else return {};
		}
		template<typename T>
		bool phys_write(UINT64 address, T buf)
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
}