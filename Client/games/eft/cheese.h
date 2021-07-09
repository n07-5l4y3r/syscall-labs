#pragma once
#include <inc.hpp>
namespace games
{
	namespace eft
	{
		using namespace std::literals;//chorno lyfhax, 24h, 1s, 1m etc

		typedef	std::vector<UINT64>									t_ents;
		typedef games::eft::c_player								t_player;
		typedef std::vector<t_player>								t_players;
		typedef std::chrono::time_point<std::chrono::system_clock>	t_time;
		typedef games::eft::s_mat									t_matrice;

		class c_cheese
		{
		public:
			std::atomic<bool>	players_writing;
		public:
			c_cheese() {};
			void			get_fps_object();
			void			get_world_object();
		private:
			void			get_entities();
			void			fetch(t_player* player);
		public:
			void			update_matrice();
			t_matrice		matrice;
		private:
			t_ents			player_ptrs;
		public:
			t_player		local = 0;
			t_players		players = {};
			std::atomic<UINT64>			fps_object = 0;
			std::atomic<UINT64>			world_object = 0;
		private:
			t_time			last_object_update = {};
		public:
			games::c_vector3 calc_angle(games::c_vector3 EnemyPos, games::c_vector3 fireport);
		public:
			bool			cheese_toggle = false;
			void			work();
		public:
			bool			setup();
			void			update();
			void			renderer();
			void			norecoilsway();
			void			aim();
		};
		extern c_cheese* p_cheese;
	}
}