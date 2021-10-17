#pragma once
#include <inc.h>

namespace cheese
{
	class gate
	{
	private:
		ring0_exec*		r0 = nullptr;
		phys_mem*		phys = nullptr;
	public:
		mem_mgr*		self_mgr = nullptr;
		mem_mgr*		target_mgr = nullptr;
	private:
		DWORD			target_pid = 0;
		PVOID			target_peproc = nullptr;
		std::string     target_name;
		uint64_t		target_base = 0;
	private:
		DWORD			pid(std::string exe);

		ULONG64			gmod(const std::string& name);
	public:
		gate			(ring0_exec* r0, phys_mem* phys, const std::string t, const std::string p);
		~gate();
		uint64_t		base() const;
	public:
		// read unsafe shellcode
		template<typename T>
		T                read_sc(void* t)
		{
			char buf[sizeof(T)] = {};
			this->target_mgr->copy_via_shellcod(this->self_mgr, buf, t, sizeof(T), false);
			return *reinterpret_cast<T*>(buf);
		}
		// write unsafe shellcode
		template<typename T>
		void			write_sc(void* t, T o)
		{
			this->target_mgr->copy_via_shellcod(this->self_mgr, &o, t, sizeof(T), true);
		}
		// read safe virtual
		template<typename T>
		T                read_va(void* t)
		{
			char buf[sizeof(T)] = {};
			this->target_mgr->copy_safe(this->self_mgr, buf, t, sizeof(T), false);
			return *reinterpret_cast<T*>(buf);
		}
		// write safe virtual
		template<typename T>
		void			write_va(void* t, T o)
		{
			this->target_mgr->copy_safe(this->self_mgr, &o, t, sizeof(T), true);
		}
		// read unsafe physical
		template<typename T>
		T                read_pa(void* t)
		{
			char buf[sizeof(T)] = {};
			this->target_mgr->copy_unsafe(this->self_mgr, buf, t, sizeof(T), false);
			return *reinterpret_cast<T*>(buf);
		}
		// write unsafe
		template<typename T>
		void			write_pa(void* t, T o)
		{
			this->target_mgr->copy_unsafe(this->self_mgr, &o, t, sizeof(T), true);
		}
		
	};
}