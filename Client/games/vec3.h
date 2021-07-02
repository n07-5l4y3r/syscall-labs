#pragma once
#include <inc.hpp>
namespace games
{
	class c_vector3
	{
	public:
		c_vector3() {};
		c_vector3(float a, float b, float c) { x = a; y = b; z = c; }
		bool cmp(c_vector3 a)
		{
			if ((int)a.x == (int)x &&
				(int)a.y == (int)y &&
				(int)a.z == (int)z) return true;
			return false;
		}
		bool cmpf(c_vector3 a)
		{
			if (a.x == x &&
				a.y == y &&
				a.z == z) return true;
			return false;
		}
		bool valid()
		{
			if (isnan(x) || isnan(y) || isnan(z)) return false;
			if (x == 0.f && y == 0.f) return false;
			return true;
		}
		void clear()
		{
			x = 0; y = 0; z = 0;
		}
		c_vector3 mult()
		{
			return c_vector3(x * 100.f, y * 100.f, z * 100.f);
		}
		bool hasZero()
		{
			if (x == 0 || y == 0 || z == 0) return true;
			return false;
		}
		inline float Dot(c_vector3 v)
		{
			return x * v.x + y * v.y + z * v.z;
		}
		float x = 0, y = 0, z = 0;
		float pause = 0;
	};
#define M_PI       3.14159265358979323846   // pi
	

}