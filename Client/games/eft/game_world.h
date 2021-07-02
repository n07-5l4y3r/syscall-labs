#pragma once
#include <inc.hpp>
namespace games
{
	namespace eft
	{
		typedef std::vector<c_player>	t_players;
		struct c_game_world
		{
		public:
			UINT64						base = 0;
			c_game_world(UINT64 m)		{ base = m; };
			//
			UINT64		get_exfiltration_array();
			int			get_exfiltration_count();
			t_players	get_players();
			c_player	get_local();
		};
	}
}