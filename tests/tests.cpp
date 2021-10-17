#include <Windows.h>
#include <iostream>

extern "C" void* syscall_entry(
	void* rcx = nullptr,
	void* rdx = nullptr,
	void* r8 = nullptr//,
	//void* r9 = nullptr,
	//void* p5 = nullptr,
	//void* p6 = nullptr
);

int main(int argc, char* argv[])
{
	if (argc >= 2)
		MessageBox(0, L"", L"", MB_OK);
	auto ret = syscall_entry(
		reinterpret_cast<void*>(0x1111111111111111),
		reinterpret_cast<void*>(0x2222222222222222),
		reinterpret_cast<void*>(0x3333333333333333)//,
		//reinterpret_cast<void*>(0x4444444444444444),
		//reinterpret_cast<void*>(0x5555555555555555),
		//reinterpret_cast<void*>(0x6666666666666666)
	);
	std::cout << ret << std::endl;
	return 0;
}