#include <inc.hpp>
void games::eft::c_cheese::get_fps_object()
{
	auto result = std::async(std::launch::async, [this]()
	{
		fps_object.store(games::eft::c_game_objects::Instance().get_fps_object().base);
	});
	auto wait = result.wait_for(std::chrono::seconds(5));
	if (wait == std::future_status::timeout)
	{
		games::eft::c_game_objects::Instance().future_stop = 1;
		printf("%s timed out\n", __FUNCTION__);
		return;
	}
	printf("%s %p\n", __FUNCTION__, fps_object.load());
}
void games::eft::c_cheese::get_world_object()
{
	auto result = std::async(std::launch::async, [this]()
	{
		world_object.store(games::eft::c_game_objects::Instance().get_game_world().base);
	});
	auto wait = result.wait_for(std::chrono::seconds(5));
	if (wait == std::future_status::timeout)
	{
		games::eft::c_game_objects::Instance().future_stop = 1;
		printf("%s timed out\n", __FUNCTION__);
		return;
	}
	printf("%s %p\n", __FUNCTION__, this->world_object.load());
}
void games::eft::c_cheese::get_entities()
{
	if (!this->world_object.load()) return;
	auto world_object = (games::eft::c_game_world)(this->world_object.load());
	auto registered_players = world_object.get_players();
	auto local_player = UINT64(0);
	if (registered_players.size() <= 0)
	{
		this->player_ptrs.clear();
		this->local = 0;
		return;
	}
	auto tmp_list = decltype(this->player_ptrs)();
	for (auto&& a : registered_players)
	{
		if (!a.base) continue;
		/*get lcp, while iterating players*/
		if (!games::c_phys_util::Instance().phys_read<uint64_t>(a.base + 0x88)) continue;
		if (games::c_phys_util::Instance().phys_read<bool>(a.base + 0x5f1))
		{
			local_player = a.base;
			continue;
		}
		tmp_list.push_back(a.base);
	}
	players_writing.store(true);
	this->player_ptrs = tmp_list;
	this->local = local_player;
	players_writing.store(false);
}
void games::eft::c_cheese::fetch(t_player* player)
{
	/*shit we want for this ent to grab*/
	auto bone_task = [&, this](games::eft::Bones bone) -> void
	{
		player->bones[bone] = player->get_bone(bone);
	};

	std::async(std::launch::async, bone_task, games::eft::Bones::HumanHead);
	std::async(std::launch::async, bone_task, games::eft::Bones::HumanRFoot);

	//std::thread(bone_task, games::eft::Bones::HumanHead).detach();
	//std::thread(bone_task, games::eft::Bones::HumanRFoot).detach();
}
void games::eft::c_cheese::update_matrice()
{
	auto camera = c_phys_util::Instance().phys_read<UINT64>(this->fps_object.load() + 0x30);
	if (!camera)
	{
		this->matrice = {};
		return;
	}
	auto object = c_phys_util::Instance().phys_read<UINT64>(camera + 0x18);
	if (!object)
	{
		this->matrice = {};
		return;
	}
	auto v = c_phys_util::Instance().phys_read<s_mat>(object + 0xD8);
	this->matrice.m[0][0] = v.m[0][0];
	this->matrice.m[1][0] = v.m[0][1];
	this->matrice.m[2][0] = v.m[0][2];
	this->matrice.m[3][0] = v.m[0][3];
	this->matrice.m[0][1] = v.m[1][0];
	this->matrice.m[1][1] = v.m[1][1];
	this->matrice.m[2][1] = v.m[1][2];
	this->matrice.m[3][1] = v.m[1][3];
	this->matrice.m[0][2] = v.m[2][0];
	this->matrice.m[1][2] = v.m[2][1];
	this->matrice.m[2][2] = v.m[2][2];
	this->matrice.m[3][2] = v.m[2][3];
	this->matrice.m[0][3] = v.m[3][0];
	this->matrice.m[1][3] = v.m[3][1];
	this->matrice.m[2][3] = v.m[3][2];
	this->matrice.m[3][3] = v.m[3][3];
}
games::c_vector3 games::eft::c_cheese::calc_angle(games::c_vector3 EnemyPos, games::c_vector3 fireport)
{
	games::c_vector3 TempReturn;
	games::c_vector3 Relative;

	Relative = fireport;

	Relative.x -= EnemyPos.x;
	Relative.y -= EnemyPos.y;
	Relative.z -= EnemyPos.z;

	auto Magnitude = Relative.len(Relative);
	auto Pitch = asin(Relative.y / Magnitude);
	auto Yaw = -atan2(Relative.x, -Relative.z);
	Yaw = Yaw * 57.2957795130823209;
	Pitch = Pitch * 57.2957795130823209;
	TempReturn.x = Yaw;
	TempReturn.y = Pitch;
	return TempReturn;
}
bool games::eft::c_cheese::setup()
{
	auto updater_task = [this]() -> void
	{
		while (0xBEEF != 0xDEAD) this->update();
	};
	auto work_task = [this]() -> void
	{
		while (0xBEEF != 0xDEAD) this->work();
	};
	this->last_object_update = std::chrono::system_clock::now();
	std::thread(updater_task).detach();
	std::thread(work_task).detach();
	return true;
}
void games::eft::c_cheese::update()
{
	const auto systime = std::chrono::system_clock::now();
	const auto time_elapsed = std::chrono::duration_cast<std::chrono::seconds>(systime - this->last_object_update).count();

	if (time_elapsed >= 20)
	{
		this->last_object_update = systime;
		auto update_objects = [&, this]()
		{
			//std::async(std::launch::async, [this]() { this->get_fps_object(); });
			//std::async(std::launch::async, [this]() { this->get_world_object(); });
			std::thread([this]() { this->get_fps_object(); }).detach();
			std::thread([this]() { this->get_world_object(); }).detach();
		};
		update_objects();
	}
	this->get_entities();
	if (!this->local.base || this->player_ptrs.empty())
	{
		this->players.clear();
		this->local = 0;
		return;
	}
	auto tmp_list = decltype(this->players)();
	for (auto&& a : this->player_ptrs)
	{
		auto b = (t_player)a;
		tmp_list.push_back(b);
	}
	bool last_completed = false;
	auto get_pos = [&,this](games::eft::c_player* player, games::eft::Bones bone) -> void
	{
		player->bones[bone] = player->get_bone(bone);
		if (player == &tmp_list.back()) last_completed = true;
	};
	for (auto&& a : tmp_list)
	{		
		get_pos(&a, Bones::HumanHead);
		get_pos(&a, Bones::HumanRFoot);
	}

	players_writing.store(true);
	this->players = tmp_list;
	players_writing.store(false);
}

void games::eft::c_cheese::renderer()
{
	if (!this->fps_object.load() || !this->cheese_toggle || players_writing.load()) return;
	auto world = (games::eft::c_camera)(this->fps_object.load());
	auto rendered = 0;
	if (this->fps_object.load()) this->update_matrice();
	for (auto&& a : this->players)
	{
		if (!a.bones[Bones::HumanHead].valid() || !a.bones[Bones::HumanRFoot].valid()) continue;

		games::c_vector3	head, rfoot;
		if (!world.w2s(a.bones[Bones::HumanHead], head, this->matrice) ||
			!world.w2s(a.bones[Bones::HumanRFoot], rfoot, this->matrice))
			continue;

		float rapport = rfoot.y - head.y;
		sdk::render::render->DrawBorder(head.x - 25 - (rapport / 4), head.y, rapport / 2, rapport, 2, 0xff00ff00);

		auto dst_to_middle = head.dst({ 1920 / 2, 1080 / 2,0 });

		if (a.ai) sdk::render::render->RenderText(head.x, head.y - 25, 0xff00ff00, (char*)"AI - %f", dst_to_middle);
		else sdk::render::render->RenderText(head.x, head.y - 25, 0xff00ff00, (char*)"PLAYER - %f", dst_to_middle);

		rendered++;
	}
	sdk::render::render->RenderText(5, 55, 0xff00ff00,  (char*)"rendered %i", rendered);
	sdk::render::render->RenderText(5, 80, 0xff00ff00,  (char*)"ents     %i", this->players.size());
	sdk::render::render->RenderText(5, 100, 0xff00ff00, (char*)"local    %p", this->local.base);
}

void games::eft::c_cheese::norecoilsway()
{
	if (!this->local.base) return;

	auto ProceduralWeaponAnimation = games::c_phys_util::Instance().phys_read<UINT64>(local.base + 0x190);
	if (!ProceduralWeaponAnimation) return;

	auto Breath = games::c_phys_util::Instance().phys_read<UINT64>(ProceduralWeaponAnimation + 0x28);
	if (!Breath) return;

	uint64_t WalkEffector = games::c_phys_util::Instance().phys_read<uint64_t>(ProceduralWeaponAnimation + 0x30);
	if (!WalkEffector) return;

	uint64_t MotionEffector = games::c_phys_util::Instance().phys_read<uint64_t>(ProceduralWeaponAnimation + 0x38);
	if (!MotionEffector) return;

	uint64_t ForceEffector = games::c_phys_util::Instance().phys_read<uint64_t>(ProceduralWeaponAnimation + 0x40);
	if (!ForceEffector) return;

	uint64_t ShootingEffector = games::c_phys_util::Instance().phys_read<uint64_t>(ProceduralWeaponAnimation + 0x48);
	if (!ShootingEffector) return;		

	games::c_phys_util::Instance().phys_write<float>(Breath + 0xA4, 0.f);
	games::c_phys_util::Instance().phys_write<float>(Breath + 0xAC, 0.f);
	games::c_phys_util::Instance().phys_write<float>(Breath + 0xA8, 0.f);

	games::c_phys_util::Instance().phys_write<float>(Breath + 0xA4, 0.f);
	games::c_phys_util::Instance().phys_write<float>(Breath + 0xAc, 0.f);
	games::c_phys_util::Instance().phys_write<float>(Breath + 0xA8, 0.f);
	games::c_phys_util::Instance().phys_write<float>(WalkEffector + 0x44, 0.f);
	games::c_phys_util::Instance().phys_write<float>(MotionEffector + 0xd0, 0.f);
	games::c_phys_util::Instance().phys_write<float>(ForceEffector + 0x30, 0.f);
	games::c_phys_util::Instance().phys_write<float>(ShootingEffector + 0x68, 0.f);

	games::c_phys_util::Instance().phys_write<float>(ProceduralWeaponAnimation + 0x22C, 0.f);
	games::c_phys_util::Instance().phys_write<float>(ProceduralWeaponAnimation + 0x228, 0.f);
	games::c_phys_util::Instance().phys_write<float>(ProceduralWeaponAnimation + 0x100, 1.f);
	games::c_phys_util::Instance().phys_write<float>(ProceduralWeaponAnimation + 0x2f4, 0.f);
}

void games::eft::c_cheese::work()
{
	if (!this->cheese_toggle || !this->world_object.load() || !this->fps_object.load()) return;

	this->norecoilsway();
	this->aim();
}

void games::eft::c_cheese::aim()
{
	auto world = (games::eft::c_camera)(this->fps_object.load());
	if (GetAsyncKeyState(VK_XBUTTON1))
	{
		auto local_fireport = local.get_fireport();
		auto enemy_target = games::c_vector3();

		auto movectx = games::c_phys_util::Instance().phys_read<UINT64>(local.base + 0x40);

		float dst_to_last = 9999999.f;

		for (auto&& a : this->players)
		{
			a.bones[games::eft::Bones::HumanHead] = a.get_bone(games::eft::Bones::HumanHead);
			auto w2s_head = games::c_vector3();

			if (!world.w2s(a.bones[games::eft::Bones::HumanHead], w2s_head, this->matrice)) continue;

			float e = w2s_head.dst({ 1920 / 2, 1080 / 2,0 });
			if (e > 60.f) continue;

			if (e < dst_to_last)
			{
				dst_to_last = e;
				enemy_target = a.bones[games::eft::Bones::HumanHead];
			}
		}
		if (enemy_target.valid())
		{
			auto ang = this->calc_angle(enemy_target, local_fireport);
			games::c_phys_util::Instance().phys_write<D3DXVECTOR2>(movectx + 0x20C, { ang.x, ang.y });
		}
	}
}
games::eft::c_cheese* games::eft::p_cheese;