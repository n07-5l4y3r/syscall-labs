#include <inc.h>

int main(const int argc, char* argv[])
{
	if (argc >= 2)
		MessageBoxA(0, "I just force win32u", "Bye!", MB_OK);
	
	const auto hDev = intel_driver::Load();
	const auto gate = new ring0_exec(
		&GetModuleHandleA,
		&GetProcAddress,
		hDev,
		&utils::GetKernelModuleAddress,
		&intel_driver::GetKernelModuleExport,
		&intel_driver::ReadMemory,
		&intel_driver::WriteMemory,
		&intel_driver::AllocatePool);
	intel_driver::Unload(hDev);
	const auto phys = new phys_mem(gate);
	
	const auto this_cr3 = phys->GetCR3ByPID(GetCurrentProcessId());
	PRINTVAR(this_cr3, "%llx");
	
	const auto VA_1337 = VirtualAlloc(NULL, 0x1000, MEM_COMMIT | MEM_RESERVE, PAGE_READWRITE);
	memcpy(VA_1337, "1337\0", 5);
	const auto VA_420 = VirtualAlloc(NULL, 0x1000, MEM_COMMIT | MEM_RESERVE, PAGE_READWRITE);
	memcpy(VA_420, "420\0", 4);

	auto begin = std::chrono::high_resolution_clock::now();
	const auto PA_1337 = phys->VA_2_PA(this_cr3, reinterpret_cast<ULONG64>(VA_1337));
	auto end = std::chrono::high_resolution_clock::now();
	std::cout << "Translate took: " << std::chrono::nanoseconds(end - begin).count() << " ns" << std::endl;

	begin = std::chrono::high_resolution_clock::now();
	const auto PA_420 = phys->VA_2_PA(this_cr3, reinterpret_cast<ULONG64>(VA_420));
	end = std::chrono::high_resolution_clock::now();
	std::cout << "Translate took: " << std::chrono::nanoseconds(end - begin).count() << " ns" << std::endl;
	
	PRINTVAR(VA_1337, "%s");
	PRINTVAR(VA_420, "%s");

	begin = std::chrono::high_resolution_clock::now();
	phys->MEM_CPY(PA_1337, PA_420, 4);
	end = std::chrono::high_resolution_clock::now();
	std::cout << "Copy took: " << std::chrono::nanoseconds(end - begin).count() << " ns" << std::endl;
	
	PRINTVAR(VA_1337, "%s");
	PRINTVAR(VA_420, "%s");
	
	delete phys;
	delete gate;
}