#pragma once
#include <inc.hpp>
namespace games
{
	namespace eft
	{
		struct c_4f
		{
			c_4f() {};
			c_4f(float a, float b, float c, float d)
			{
				f_1 = a; f_2 = b; f_3 = c; f_4 = d;
			}
			float f_1 = 0, f_2 = 0, f_3 = 0, f_4 = 0;
		};
		struct Matrix34
		{
			c_4f vec0;
			c_4f vec1;
			c_4f vec2;
		};

		class c_transform
		{
		public:
			UINT64						base = 0;
			c_transform(UINT64 m)		{ base = m; };
			//
			games::c_vector3	get_position();
		};
	}
}