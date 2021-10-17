_TEXT SEGMENT

PUBLIC syscall_entry

syscall_entry PROC
	mov r10, rcx
	mov eax, 1005h
	int 3h
	syscall
	ret
syscall_entry ENDP

_TEXT ENDS
END