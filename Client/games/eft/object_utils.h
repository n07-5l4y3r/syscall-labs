#pragma once
#include <inc.hpp>
namespace games
{
	namespace eft
	{
		struct GameObjectManager
		{
			uint64_t lastTaggedObject; //0x0000
			uint64_t taggedObjects; //0x0008
			uint64_t lastActiveObject; //0x0010
			uint64_t activeObjects; //0x0018
		}; //Size: 0x0010

		//48 89 05 ? ? ? ? 48 83 C4 ? C3 48 C7 05 ? ? ? ? ? ? ? ? 48 83 C4 ? C3 ? ? ? ? ? 48 89 4C 24 ?
		//C:\Battlestate Games\EFT\UnityPlayer.dll

		typedef std::vector<std::pair<UINT64, std::string>> t_objects;
		class c_game_objects : public s<c_game_objects>
		{
		public:
			bool						future_stop = false;
			void						dump_objects();
			c_game_world				get_game_world();
			c_camera					get_fps_object();
			UINT64						get_optic_object();
			//
			bool						check_matrix(UINT64 optic_object);
			//
		};
	}
}