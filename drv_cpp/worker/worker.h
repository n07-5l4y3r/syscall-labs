#pragma once

#include <inc.h>

namespace threads::worker
{
	class __declspec(code_seg("$kerneltext$")) c_worker
	{

	public:
		typedef NTSTATUS(*tcallback)(c_worker* pinst);
	private:
		tcallback pcallback = nullptr;
		PWORK_QUEUE_ITEM pworker = nullptr;

	private:
		static void WORKER_THREAD_ROUTINE(_In_ PVOID pparam);
	public:
		void queue() const;

	private:
		PVOID pparam = nullptr;
	public:
		[[nodiscard]] PVOID g_param(void) const;
		PVOID s_param(PVOID p);

	public:
		c_worker(tcallback pcb, PVOID pparam);
		~c_worker();

	};

}