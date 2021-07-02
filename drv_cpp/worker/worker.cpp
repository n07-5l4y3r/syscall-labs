#include "worker.h"

namespace threads
{
	namespace worker
	{

		void c_worker::WORKER_THREAD_ROUTINE(_In_ PVOID pparam) {
			//DbgPrint(" [>] \"" __FUNCTION__ "\"" "\n");

			//DbgPrint("     pparam = %p ""\n", pparam);
			if (!pparam)
				return;
			auto pinst = static_cast<c_worker*>(pparam);

			//DbgPrint("     pcallback = %p ""\n", pinst->pcallback);
			if (pinst->pcallback)
			{
				if (const auto ret = pinst->pcallback(pinst); ret == STATUS_SUCCESS)
				{
					//DbgPrint("     ret = %#lx ""\n", ret);
					//DbgPrint("     pworker = %p ""\n", pinst->pworker);
					if (pinst->pworker)
					{
						pinst->queue();
						return;
					}
				}
			}

			pinst->~c_worker();
		}

		void c_worker::queue() const
		{
			//DbgPrint(" [>] \"" __FUNCTION__ "\"" "\n");

			if (this->pworker)
				ExQueueWorkItem(this->pworker, DelayedWorkQueue);
		}

		PVOID c_worker::g_param() const
		{
			//DbgPrint(" [>] \"" __FUNCTION__ "\"" "\n");

			//DbgPrint("     pparam = %p ""\n", this->pparam);

			return this->pparam;
		}

		PVOID c_worker::s_param(PVOID p)
		{
			//DbgPrint(" [>] \"" __FUNCTION__ "\"" "\n");

			this->pparam = p;

			//DbgPrint("     pparam = %p ""\n", this->pparam);

			return this->pparam;
		}

		c_worker::c_worker(const tcallback pcb, const PVOID ppar) :
			pcallback( pcb ), pparam( ppar )
		{
			//DbgPrint(" [>] \"" __FUNCTION__ "\"" "\n");

			this->pworker = new WORK_QUEUE_ITEM();

			//DbgPrint("     pworker = %p ""\n", this->pworker);

			if (this->pworker)
				ExInitializeWorkItem(this->pworker, c_worker::WORKER_THREAD_ROUTINE, this);
		}

		c_worker::~c_worker()
		{
			//DbgPrint(" [>] \"" __FUNCTION__ "\"" "\n");

			//DbgPrint("     pworker = %p ""\n", this->pworker);
			//DbgPrint("     pinst = %p ""\n", this);

			delete this->pworker;

			_cpp_class_delete_helper(this, sizeof(c_worker), 2);
		}

	}
}