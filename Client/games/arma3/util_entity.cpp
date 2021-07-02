#include <inc.hpp>
std::vector<UINT64> games::arma3::c_a3::get_pointers(UINT64 address, uint32_t size)
{
	auto ret = std::vector<UINT64>();

	if (!address || !size) return ret;

	struct s_block { char mem[0x100]; };

	if (size * 8 < 0x100)
	{
		auto chunk = games::c_phys_util::Instance().phys_read<s_block>(address);
		for (auto a = 0; a < 0x100; a += 0x8)
		{
			auto p = *(UINT64*)(chunk.mem + a);
			if (!p) break;
			ret.push_back(p);
		}
		return ret;
	}

	auto steps = (size * 8) / 0x100;
	steps = std::round(steps);

	int i = 0;
	while (i != steps)
	{
		auto chunk = games::c_phys_util::Instance().phys_read<s_block>(address + (i * 0x100));
		for (auto a = 0; a < 0x100; a += 0x8)
		{
			auto p = *(UINT64*)(chunk.mem + a);
			if (!p) break;
			ret.push_back(p);
		}
		i++;
	}

	return ret;
}
void games::arma3::c_a3::update()
{
	while (0xDEADBEEF != 0xF00D)
	{
		auto t1 = std::chrono::high_resolution_clock::now();

		auto world = games::c_phys_util::Instance().phys_read<UINT64>(games::c_phys_util::Instance().base + 0x26535F0);
		if (!world)
		{
			entities_write.store(true);
			this->entities.clear();
			entities_write.store(false);
			continue;
		}
		auto Camera = games::c_phys_util::Instance().phys_read<uintptr_t>(world + 0x918);
		if (!Camera)
		{
			entities_write.store(true);
			this->entities.clear();
			entities_write.store(false);
			continue;
		}

		auto v = std::vector<games::arma3::s_entity>();

		auto close_actors = this->get_pointers(games::c_phys_util::Instance().phys_read<UINT64>(world + 0x17F8), games::c_phys_util::Instance().phys_read<uint32_t>(world + 0x1800));
		if (close_actors.size())
		{			
			for (auto a : close_actors)
			{
				auto man_type = games::c_phys_util::Instance().phys_read<UINT64>(a + 0x150);
				if (!man_type) continue;

				auto man_visual_state = games::c_phys_util::Instance().phys_read<UINT64>(a + 0x190);
				if (!man_visual_state) continue;

				auto type_string = this->get_arma_string(man_type + 0xd0);
				if (type_string.empty()) continue;

				if (type_string.find("Soldier") == std::string::npos && type_string.find("soldier") == std::string::npos) continue;

				auto feet_pos = games::c_phys_util::Instance().phys_read<D3DXVECTOR3>(man_visual_state + 0x2c);
				auto head_pos = games::c_phys_util::Instance().phys_read<D3DXVECTOR3>(man_visual_state + 0x168);

				v.push_back({ a, head_pos, feet_pos, type_string });
			}
		}
		else
		{
			entities_write.store(true);
			this->entities.clear();
			entities_write.store(false);
		}
		auto far_actors = this->get_pointers(games::c_phys_util::Instance().phys_read<UINT64>(world + 0x18C0), games::c_phys_util::Instance().phys_read<uint32_t>(world + 0x18D0));
		if (far_actors.size())
		{			
			for (auto a : far_actors)
			{
				auto man_type = games::c_phys_util::Instance().phys_read<UINT64>(a + 0x150);
				if (!man_type) continue;

				auto man_visual_state = games::c_phys_util::Instance().phys_read<UINT64>(a + 0x190);
				if (!man_visual_state) continue;

				auto type_string = this->get_arma_string(man_type + 0xd0);
				if (type_string.empty()) continue;

				if (type_string.find("Soldier") == std::string::npos && type_string.find("soldier") == std::string::npos) continue;

				auto feet_pos = games::c_phys_util::Instance().phys_read<D3DXVECTOR3>(man_visual_state + 0x2c);
				auto head_pos = games::c_phys_util::Instance().phys_read<D3DXVECTOR3>(man_visual_state + 0x168);

				v.push_back({ a, head_pos, feet_pos, type_string });
			}
		}
		//

		entities_write.store(true);
		this->entities = v;
		printf("%i entities\n", v.size());
		entities_write.store(false);

		auto t2 = std::chrono::high_resolution_clock::now();
		auto ms_int = std::chrono::duration_cast<std::chrono::milliseconds>(t2 - t1);

		this->execution_time_ms.store(ms_int.count());
	}
}

D3DXVECTOR3 games::arma3::c_a3::world_to_screen(D3DXVECTOR3 in, s_matrix mat)
{
	D3DXVECTOR3 out, temp;
	float x = 0, y = 0, z = 0;

	D3DXVec3Subtract(&temp, &in, &mat.mtranslation);
	x = D3DXVec3Dot(&temp, &mat.right);
	y = D3DXVec3Dot(&temp, &mat.up);
	z = D3DXVec3Dot(&temp, &mat.forward);

	if (z < 0.0001f) return { 0,0,0 };

	out.x = (mat.matrice.x * (1 + (x / mat.projection1.x / z)));
	out.y = (mat.matrice.y * (1 - (y / mat.projection2.y / z)));
	out.z = z;

	return out;
}

std::string games::arma3::c_a3::get_arma_string(UINT64 address)
{
	class AString
	{
	public:
		char pad_0000[0x08]; //0x0000
		int32_t Lenght; //0x0008
		char pad_000C[0x04]; //0x000C
		char string[0x40]; //0x0010
	}; //Size: 0x0080

	auto base = games::c_phys_util::Instance().phys_read<UINT64>(address);
	if (!base) return "";

	auto astring = games::c_phys_util::Instance().phys_read<AString>(base);
	if (!astring.Lenght) return "";

	return astring.string;

}
