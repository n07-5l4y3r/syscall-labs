#pragma once
#include <inc.hpp>
namespace games
{
	namespace eft
	{
		class Vector2
		{
		public:
			Vector2() : x(0.f), y(0.f)
			{
			}

			Vector2(float _x, float _y) : x(_x), y(_y)
			{
			}
			~Vector2()
			{
			}

			float x;
			float y;

			inline float Distance(Vector2 v)
			{
				return float(sqrtf(powf(v.x - x, 2.0) + powf(v.y - y, 2.0)));
			}
		}; 
		struct s_mat { float m[4][4]; };

		class c_camera
		{
		public:
			UINT64					base = 0;
			c_camera(UINT64 m)		{ base = m; };
			//
			float					ViewMatrix[4][4];
			Vector2					ScreenSize{ 1920, 1080 };
			bool					update_matrix();
			games::c_vector3		get_pos();
			bool					w2s(games::c_vector3 wpos, games::c_vector3& spos, s_mat matrix);
		};
	}
}