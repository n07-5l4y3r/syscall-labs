#include <inc.h>

int main(const int argc, char* argv[])
{
	if (argc >= 2)
		MessageBoxA(0, "I just force win32u", "Bye!", MB_OK);

	//auto cheese_menu = new cheese::c_cheese();
	//cheese_menu->setup();

	Sleep(1500);
	
	const auto hDev = intel_driver::Load();
	const auto r0 = new ring0_exec(
		&GetModuleHandleA,
		&GetProcAddress,
		hDev,
		&utils::GetKernelModuleAddress,
		&intel_driver::GetKernelModuleExport,
		&intel_driver::ReadMemory,
		&intel_driver::WriteMemory,
		&intel_driver::AllocatePool);
	intel_driver::Unload(hDev);
	
	//const auto mgr_local = new mem_mgr(r0, r0->GetCR3ByPID(GetCurrentProcessId()));
	//char buf_A[] = "test";
	//char buf_B[] = "1337";
	//char buf_C[] = "test";
	//PRINTVAR(buf_A, "%s");
	//PRINTVAR(buf_B, "%s");
	//PRINTVAR(buf_C, "%s");
	//
	//if (mgr_local->copy(mgr_local, buf_A, buf_B, 5))
	//	std::cout << " > Read  Completed!" << " buf_A: '" << buf_A << "'" << std::endl;
	//
	//if (mgr_local->copy(mgr_local, buf_C, buf_B, 5, true))
	//	std::cout << " > Write Completed!" << " buf_B: '" << buf_B << "'" << std::endl;
	//
	//PRINTVAR(buf_A, "%s");
	//PRINTVAR(buf_B, "%s");
	//PRINTVAR(buf_C, "%s");
	//delete mgr_local;

	const auto phys = new phys_mem(r0);
	
	const auto phys_cr3 = phys->r0_CR3_PHYS;
	PRINTVAR(phys_cr3, "%llx");
	
	const auto explorer = new cheese::gate(r0, phys, "0day.exe", "0day.exe");
	PRINTVAR(explorer->base(), "%llx");
	
	system("pause");

	//unsigned long long reads = 0;
	//unsigned long long all_ns = 0;
	const auto p_end = explorer->base() + 0x2000;
	//const auto s_block = sizeof(uint64_t);
	//std::cout << "Read-Module in " << s_block << " bytes steps: " << std::endl;
	//for (auto p = explorer->base(); (p + s_block) < p_end; p += s_block)
	//{
	//	const auto b = std::chrono::high_resolution_clock::now();
	//	const auto t = explorer->read_sc<uint64_t>(reinterpret_cast<void*>(p));
	//	const auto e = std::chrono::high_resolution_clock::now();
	//	all_ns += std::chrono::duration_cast<std::chrono::nanoseconds>(e - b).count();
	//	reads++;
	//}
	//std::cout << "DONE!" << std::endl;
	//std::cout << "  Took: " << all_ns << " ns in " << reads << " steps == [ " << all_ns / reads << " ns / step ]" << std::endl;

	auto tmp = VirtualAlloc(0, 0x2000 + 1, MEM_COMMIT | MEM_RESERVE, PAGE_READWRITE);
	if (tmp)
	{
		memset(tmp, 0, 0x2000);
		PRINTVAR(tmp, "%p");
		PRINTVAR(0x2000, "%lc");
		system("pause");
		const auto b = std::chrono::high_resolution_clock::now();
		const auto r = explorer->target_mgr->copy_via_shellcod(explorer->self_mgr, tmp, reinterpret_cast<void*>(explorer->base()), 0x2000, false);
		const auto e = std::chrono::high_resolution_clock::now();
		const auto ns = std::chrono::duration_cast<std::chrono::nanoseconds>(e - b).count();
		PRINTVAR(r, "%hhd");
		PRINTVAR(ns, "%llu");
		char magic[] = "\0\0\0";
		memcpy(magic, tmp, 0x2);
		PRINTVAR(magic, "%s");
	}

	system("pause");
	VirtualFree(tmp, 0, MEM_DECOMMIT | MEM_RELEASE);
	
	delete explorer;
	
	delete phys;
	delete r0;
}