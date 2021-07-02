#pragma once
#include <inc.hpp>
namespace games
{
	enum u_game
	{
		u_none = 0,
		u_arma3 = 1
	};
	class s_thread : public s<s_thread>
	{
	private:
		std::thread updater_task;
	public:
		void	setup(u_game game);
	};
}