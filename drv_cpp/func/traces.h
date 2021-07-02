#pragma once
#include <inc.h>

namespace func
{
	struct module_data
	{
		UINT64		base;
		UINT64		max;
	};
	class __declspec(code_seg("$kerneltext$")) c_func
	{
	private:
		UINT64		ntos_base = 0x0;
		UINT64		ntos_size = 0x0;
	private:
		bool		wipe_unloaded_drivers_log_timestamp();
		bool		wípe_unloaded_drivers_log_last();
	public:
		bool	    get_proc_name(const char* name, PEPROCESS* ppeprocess);
		module_data	get_module(const wchar_t* name, PEPROCESS peprocess);
	public:
		void		setup();
		bool		work();
	};
}