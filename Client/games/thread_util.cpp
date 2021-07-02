#include <inc.hpp>

void arma3_slave()
{
	while (0xDEADBEEF != 0xF00D)
	{
		try
		{
			games::arma3::c_a3::Instance().update();
		}
		catch (...) { continue; }
	}
}

void games::s_thread::setup(u_game game)
{
	switch (game)
	{
	case u_game::u_arma3:
	{
		auto task = []() -> const void
		{
			std::thread e(arma3_slave);
			e.detach();
		};
		this->updater_task = std::thread(task);
		this->updater_task.detach();
	}
	break;
	default: break;
	}
}
