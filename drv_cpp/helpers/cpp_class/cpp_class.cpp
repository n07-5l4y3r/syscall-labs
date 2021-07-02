#include "cpp_class.h"

#pragma warning (disable:28252)
void* malloc(_In_ size_t _Size)
{
	DbgPrint(" [>] \"" __FUNCTION__ "\"" "\n");

	DbgPrint("     size = %#x ""\n", _Size);

	return ExAllocatePool(NonPagedPool, _Size);
}
#pragma warning (disable:28253)
void free(_In_ void* ptr)
{
	DbgPrint(" [>] \"" __FUNCTION__ "\"" "\n");

	DbgPrint("     ptr = %p ""\n", ptr);

	return ExFreePool(ptr);
}
void* realloc(_In_ void* old, _In_ size_t newsize)
{
	if (const auto n = malloc(newsize))
	{
		free(old);
		return n;
	}
	return 0;
}

void* operator new(unsigned __int64 s)
{
	DbgPrint(" [>] \"" __FUNCTION__ "\"" "\n");

	DbgPrint("     size = %#x ""\n", s);

	return malloc(s);
}

void operator delete(void* p, unsigned __int64 s)
{
	DbgPrint(" [>] \"" __FUNCTION__ "\"" "\n");

	DbgPrint("     ptr = %p ""\n", p);
	DbgPrint("     size = %#x ""\n", s);

	if (!p)
		return;
	if (!s)
		return;

	free(p);
}

void _delete(void* p, unsigned __int64 s)
{
	operator delete(p, s);
}