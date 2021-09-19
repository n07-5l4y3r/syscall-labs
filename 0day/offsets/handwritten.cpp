#include "offset.h"
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