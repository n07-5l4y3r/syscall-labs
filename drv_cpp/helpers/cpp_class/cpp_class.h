#pragma once

#include <inc.h>

#pragma warning (disable:28252)
void* __cdecl malloc(_In_ size_t _Size);
#pragma warning (disable:28253)
void  free(_In_ void* ptr);
void* realloc(_In_ void* old, _In_ size_t newsize);

void* operator new (unsigned __int64 s);
void operator delete(void* p, unsigned __int64 s);

extern "C" void _delete(void* p, unsigned __int64 s);
extern "C" void _cpp_class_delete_helper(void* p, unsigned __int64 s, unsigned __int64 skip);