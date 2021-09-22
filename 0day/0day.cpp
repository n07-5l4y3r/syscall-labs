#include <inc.h>

int main(const int argc, char* argv[])
{
	if (argc >= 2)
		MessageBoxA(0, "I just force win32u", "Bye!", MB_OK);

	auto cheese_menu = new cheese::c_cheese();
	cheese_menu->setup();

	Sleep(1500);
	
	const auto hDev = intel_driver::Load();
	const auto exec = new ring0_exec(
		&GetModuleHandleA,
		&GetProcAddress,
		hDev,
		&utils::GetKernelModuleAddress,
		&intel_driver::GetKernelModuleExport,
		&intel_driver::ReadMemory,
		&intel_driver::WriteMemory,
		&intel_driver::AllocatePool);
	intel_driver::Unload(hDev);
	const auto phys = new phys_mem(exec);

	cheese_menu->install_toggle();
	
	/*const auto notepad = new cheese::gate(phys, "notepad.exe", "notepad.exe");
	std::cout << "Notepad-Base: " << std::hex << notepad->base() << std::endl;*/

	//const auto magic = "MZ";
	//auto i = 0;

	//const auto a = std::chrono::high_resolution_clock::now();
	/*for (; i < 2000000; i++)
	{
		const auto tmp = notepad->read<short>(reinterpret_cast<void*>(notepad->base()));
		if (tmp != *(short*)magic) {
			std::cout << tmp << std::endl;
			break;
		}
		}*/
	/*struct s_mz
	{
		char m[4];
	};
	const auto tmp = notepad->read<s_mz>((void*)notepad->base());
	const auto b = std::chrono::high_resolution_clock::now();
	std::cout << std::dec << std::chrono::duration_cast<std::chrono::nanoseconds>(std::chrono::nanoseconds(b - a)).count() << " ns" << std::endl;
	*/
	delete phys;
	delete exec;

	while (1) { std::this_thread::sleep_for(std::chrono::seconds(5)); }
}