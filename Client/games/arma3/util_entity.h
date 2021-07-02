#pragma once
#include <inc.hpp>
namespace games
{
	namespace arma3
	{
		struct s_matrix
		{
			D3DXVECTOR3 mtranslation;
			D3DXVECTOR3 up;
			D3DXVECTOR3 right;
			D3DXVECTOR3 forward;
			D3DXVECTOR3 matrice;
			D3DXVECTOR3 projection1;
			D3DXVECTOR3 projection2;
		};
		struct s_entity
		{
			s_entity(){}
			s_entity(uint64_t a, D3DXVECTOR3 head, D3DXVECTOR3 feet, std::string enttype)
			{
				address = a;
				head_pos = head;
				feet_pos = feet;
				type_name = enttype;
			}

			uint64_t		address;
			D3DXVECTOR3		head_pos;
			D3DXVECTOR3		feet_pos;
			std::string		type_name;
		};
		class c_a3 : public s<c_a3>
		{
		private:
			std::vector<UINT64>		get_pointers(UINT64 address, uint32_t size);
		public:
			std::mutex				entities_mutex;
			std::atomic<bool>		entities_write;

			std::vector<s_entity>	entities;

			std::atomic<int>		execution_time_ms = 0;

			void					update();
			D3DXVECTOR3				world_to_screen(D3DXVECTOR3 in, s_matrix mat);
			std::string				get_arma_string(UINT64 address);
		};
	}
}