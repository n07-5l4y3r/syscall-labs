#include "ipc_slave.h"

typedef void (tThreadProc)(LPVOID lpParameter);
NTSTATUS CreateRemoteThread(const PEPROCESS proc, tThreadProc* pThreadProc, const LPVOID lpParameter, const bool bWait);


NTSTATUS ipc::slave::work
(
	const PEPROCESS proc,
	t_incoming_packet_handler* handler
)
{
	if (!proc) return STATUS_ACCESS_DENIED;

	static auto st_get_queue = reinterpret_cast<void(*)(int)>(helpers::phys_mem::GetProcAddr(proc, "st_get_queue"));
	//DbgPrint("st_get_queue: %p", st_get_queue);
	static auto kernel_buffer = reinterpret_cast<shared::tMultiPacket*>(helpers::phys_mem::GetProcAddr(proc, "kernel_buffer"));
	//DbgPrint("kernel_buffer: %p", kernel_buffer);
	static auto at_set_promise = reinterpret_cast<void(*)(int)>(helpers::phys_mem::GetProcAddr(proc, "at_set_promise"));
	//DbgPrint("at_set_promise: %p", at_set_promise);

	if (NTSTATUS s; !NT_SUCCESS(s = CreateRemoteThread(proc, reinterpret_cast<tThreadProc*>(st_get_queue), nullptr, true)))
	{
		DbgPrint("ouch!\n");
		return STATUS_ALREADY_COMPLETE;//skip shit but dont fukin die aight
	}

	KeAttachProcess(proc);
	const auto count = kernel_buffer->count;
	KeDetachProcess();

	if (!count)
		return STATUS_ALREADY_COMPLETE;

	bool shutdown = false;
	for (unsigned index = 0; (index < count) && !shutdown; index++)
	{
		KeAttachProcess(proc);
		const auto req_id = kernel_buffer->ahead[index].pdata->request_id;
		KeDetachProcess();
		switch (req_id)
		{
		case ipc::shared::internal::eRequestId::shutdown:
		{
			shared::tbuf<shared::internal::RET, shared::internal::shutdown> ret_data = { true };
			KeAttachProcess(proc);
			const auto req_packet = reinterpret_cast<shared::tPacket<shared::internal::REQ, shared::internal::shutdown>*>(kernel_buffer->ahead[index].pdata);
			const auto ret_packet = req_packet->brother;
			memcpy(&ret_packet->data.obj, &ret_data, sizeof(ret_data));
			KeDetachProcess();
			shutdown = true;
		}
		break;
		default:
		{
			KeAttachProcess(proc);
			const auto req_packet = kernel_buffer->ahead[index].pdata;
			KeDetachProcess();
			handler(proc, req_packet);
		}
		break;
		}
	}

	if (NTSTATUS s; !NT_SUCCESS(s = CreateRemoteThread(proc, reinterpret_cast<tThreadProc*>(at_set_promise), nullptr, true)))
	{
		DbgPrint("coochie!\n");
		return s;
	}

	if (shutdown)
		return STATUS_CANCELLED;

	return STATUS_SUCCESS;
}
typedef struct _THREAD_BASIC_INFORMATION {




	NTSTATUS                ExitStatus;
	PVOID                   TebBaseAddress;
	CLIENT_ID               ClientId;
	KAFFINITY               AffinityMask;
	KPRIORITY               Priority;
	KPRIORITY               BasePriority;



} THREAD_BASIC_INFORMATION, * PTHREAD_BASIC_INFORMATION;

// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

typedef NTSTATUS(NTAPI tRtlCreateUserThread)
(
	IN HANDLE               ProcessHandle,
	IN PSECURITY_DESCRIPTOR SecurityDescriptor OPTIONAL,
	IN BOOLEAN              CreateSuspended,
	IN ULONG                StackZeroBits,
	IN OUT PULONG           StackReserved,
	IN OUT PULONG           StackCommit,
	IN PVOID                StartAddress,
	IN PVOID                StartParameter OPTIONAL,
	OUT PHANDLE             ThreadHandle,
	OUT PCLIENT_ID          ClientID
	);

extern "C"
{
	NTSTATUS
	NTAPI
	NtQueryInformationThread(



		IN HANDLE               ThreadHandle,
		IN _THREADINFOCLASS		ThreadInformationClass,
		OUT PVOID               ThreadInformation,
		IN ULONG                ThreadInformationLength,
		OUT PULONG              ReturnLength OPTIONAL
	);
}

BOOL
WINAPI
GetExitCodeThread(IN HANDLE hThread,
	OUT LPDWORD lpExitCode)
{
	THREAD_BASIC_INFORMATION ThreadBasic;
	NTSTATUS Status;

	Status = NtQueryInformationThread(hThread,
		ThreadBasicInformation,
		&ThreadBasic,
		sizeof(THREAD_BASIC_INFORMATION),
		NULL);
	*lpExitCode = ThreadBasic.ExitStatus;
	return TRUE;
}

tRtlCreateUserThread* RtlCreateUserThread = nullptr;
inline NTSTATUS CreateThread(
	tThreadProc* pThreadProc,
	const LPVOID lpParameter,
	const bool bWait
)
{
	//DbgPrint(" [>] \"" __FUNCTION__ "\"");
	if (RtlCreateUserThread == nullptr)
	{
		const UNICODE_STRING RtlCreateUserThreadStr = RTL_CONSTANT_STRING(L"RtlCreateUserThread");
		if
			(
				const auto pRtlCreateUserThread = MmGetSystemRoutineAddress(const_cast<PUNICODE_STRING>(&RtlCreateUserThreadStr));
				!((RtlCreateUserThread = static_cast<tRtlCreateUserThread*>(pRtlCreateUserThread)))
				)
		{
			DbgPrint(" [-] RtlCreateUserThread not found!" "\n");
			DbgPrint(" [-] Thread not executed!" "\n");
			return STATUS_INTERNAL_ERROR;
		}
	}
	CLIENT_ID	ClientID = { nullptr, nullptr };
	HANDLE		hThread = nullptr;
	NTSTATUS	status;
	if (NT_SUCCESS(status = RtlCreateUserThread(NtCurrentProcess(), nullptr, FALSE, NULL, nullptr, nullptr, pThreadProc, lpParameter, &hThread, &ClientID)) && bWait)
	{
		LARGE_INTEGER timeout{}; timeout.QuadPart = -(60ll * 10 * 1000 * 1000);
		if (!NT_SUCCESS(status = ZwWaitForSingleObject(hThread, TRUE, &timeout)))
		{
			DbgPrint(" [-] ZwWaitForSingleObject failed with status 0x%X\n", status);
			return STATUS_INTERNAL_ERROR;
		}

		unsigned long ret = 0;
		auto exit_ret = GetExitCodeThread(hThread, &ret);
		
		if (ret != 0xDEAD)
		{
			DbgPrint("[error thread] returned %04x\n", ret);
			if (hThread) ZwClose(hThread);
			return STATUS_INTERNAL_ERROR;
		}
		
	}
	else
		if (bWait)
			DbgPrint(" [-] ZwCreateThreadEx failed with status 0x%X\n", status);
	if (hThread) ZwClose(hThread);
	return status;
}

NTSTATUS CreateRemoteThread(
	const PEPROCESS proc,
	tThreadProc* pThreadProc,
	const LPVOID lpParameter,
	const bool bWait)
{
	//DbgPrint(" [>] \"" __FUNCTION__ "\"");
	KeAttachProcess(proc);
	const auto st = CreateThread(pThreadProc, lpParameter, bWait);
	KeDetachProcess();
	return st;
}
