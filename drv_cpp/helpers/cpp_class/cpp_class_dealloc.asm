_TEXT SEGMENT

EXTERN _delete: PROC
PUBLIC _cpp_class_delete_helper

_cpp_class_delete_helper PROC PUBLIC
	; rcx	= (void*)		void_to_free
	; rdx	= (uint64_t)	size_to_free
	; r8	= (uint64_t)	mod_ret_time
	push rbp
    mov  rbp, rsp
	;
	; rcx, rdx
	call _delete
	;
	mov r9, _return_address
	mov [rbp+8h], r9
	;
	mov rsp, rbp
	pop rbp
	ret
_return_address:
	dec r8
	cmp r8, 0
	jz _done
	;
	mov r9, _return_address
	mov [rbp+8h], r9
_done:
	; cleanup stack
	add rsp, 20h
	pop rbx
	;
	ret
_cpp_class_delete_helper ENDP

_TEXT ENDS
END