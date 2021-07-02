#include "main.h"

bool GetProcessByName(_In_ const char name[15], _Out_ PEPROCESS* ppeprocess);

extern "C" NTSTATUS DriverEntry(_In_opt_ PDRIVER_OBJECT pDriverObject, _In_opt_ PUNICODE_STRING pRegistryPath)
{
	UNREFERENCED_PARAMETER(pDriverObject);
	UNREFERENCED_PARAMETER(pRegistryPath);

	auto traces = new func::c_func();
	
	//DbgPrint(" [>] \"" __FUNCTION__ "\"" "\n");

	PEPROCESS peprocess = nullptr;
	const bool bRet = traces->get_proc_name("Client.exe", &peprocess);
	//DbgPrint(" > GetProcessByName = %u -> %p", bRet, peprocess);
	if (!bRet || !peprocess)
		return STATUS_SUCCESS;

	struct tTmp {
		const char ImageFileName[0xF];
	}*pTmp = static_cast<tTmp*>(offset::ptr_field(offset::_EPROCESS::ImageFileName, peprocess));
	//DbgPrint(" > ImageFileName: \"%s\"\n", pTmp->ImageFileName);

	if (const auto pparams = static_cast<worker_queue_entry_params*>(malloc(sizeof(worker_queue_entry_params))); pparams)
	{
		RtlZeroMemory(pparams, sizeof(worker_queue_entry_params));
		pparams->proc = peprocess;
		if (const auto pthread = new threads::worker::c_worker(worker_queue_entry, static_cast<PVOID>(pparams)); pthread)
			pthread->queue();
	}

	return STATUS_SUCCESS;
}