#pragma once
#include <inc.hpp>
namespace games
{
	namespace eft
	{
		extern void world_object_routine();
		extern void fps_object_routine();
		extern void player_routine();

		class c_updater : public s<c_updater>
		{
		public:
			std::atomic<bool>		writing;
			eft::t_players			players;
			UINT64					fps_object;
			UINT64					world_object;
			UINT64					localplayer;
			void			update_players();
			void			update_fps_object();
			void			update_world_object();
			void			setup();
		};
	}
}