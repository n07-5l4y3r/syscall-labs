#pragma once
#include <inc.h>

namespace cheese
{
	class gate
	{
	private:
		phys_mem*		phys = nullptr;
		DWORD			target_pid = 0;
		PVOID			target_peproc = nullptr;
		std::string     target_name;
		uint64_t		target_base = 0;
		uint64_t		target_cr3 = 0;
		uint64_t		self_cr3 = 0;
	private:
		DWORD			pid(std::string exe);
		uint64_t		gmod(const std::string& name);
	public:
		gate(phys_mem* ph, const std::string t, const std::string p);
		uint64_t		base();
	public:
		template<typename T>
		T				read(void* t)
		{
			char buf[sizeof(T)] = {};
			const auto PA_Dest = phys->MEM_CPY(this->self_cr3, buf, this->target_cr3, static_cast<PVOID>(t), sizeof(T));
			return *reinterpret_cast<T*>(buf);
		}
		template<typename T>
		void			write(void* t, T o)
		{
			phys->MEM_CPY(this->target_cr3, t, this->self_cr3, &o, sizeof(T));
		}
	};
}