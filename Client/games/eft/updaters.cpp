#include <inc.hpp>

void games::eft::c_updater::update_players()
{
	if (!this->world_object) return;

	auto w = (games::eft::c_game_world)this->world_object;

	auto a = w.get_players();
	auto list = decltype(this->players)();

	if (!list.size()) localplayer = 0;
	else
	{
		if (!localplayer) localplayer = w.get_local().base;
	}

	for (auto&& m : a)
	{
		if (m.base == localplayer) continue;
		if (!m.has_bone(133)) continue;

		m.bones[Bones::HumanHead] = m.get_bone(Bones::HumanHead);
		m.bones[Bones::HumanRFoot] = m.get_bone(Bones::HumanRFoot);

		/*m.bones[Bones::HumanHead] = m.get_bone(Bones::HumanHead);
		m.bones[Bones::HumanNeck] = m.get_bone(Bones::HumanNeck);

		m.bones[Bones::HumanSpine1] = m.get_bone(Bones::HumanSpine1);
		m.bones[Bones::HumanSpine2] = m.get_bone(Bones::HumanSpine2);
		m.bones[Bones::HumanSpine3] = m.get_bone(Bones::HumanSpine3);

		m.bones[Bones::HumanPelvis] = m.get_bone(Bones::HumanPelvis);

		m.bones[Bones::HumanRCalf] = m.get_bone(Bones::HumanRCalf);
		m.bones[Bones::HumanLCalf] = m.get_bone(Bones::HumanLCalf);

		m.bones[Bones::HumanRFoot] = m.get_bone(Bones::HumanRFoot);
		m.bones[Bones::HumanLFoot] = m.get_bone(Bones::HumanLFoot);

		m.bones[Bones::HumanLForearm2] = m.get_bone(Bones::HumanLForearm2);
		m.bones[Bones::HumanRForearm2] = m.get_bone(Bones::HumanRForearm2);

		m.bones[Bones::HumanLUpperarm] = m.get_bone(Bones::HumanLUpperarm);
		m.bones[Bones::HumanRUpperarm] = m.get_bone(Bones::HumanRUpperarm);

		m.bones[Bones::HumanLElbow] = m.get_bone(Bones::HumanLElbow);
		m.bones[Bones::HumanRElbow] = m.get_bone(Bones::HumanRElbow)*/;

		/*auto r = m.get_pos_root();
		m.root_pos = r;
		if (!m.root_pos.valid()) continue;*/

		//printf("%p - %f %f %f , %f %f %f\n", m.base, m.head_pos.x, m.head_pos.y, m.head_pos.z, m.root_pos.x, m.root_pos.y, m.root_pos.z);
		list.push_back(m);
	}

	Instance().players = list;
}

void games::eft::c_updater::update_fps_object()
{
	Instance().fps_object = games::eft::c_game_objects::Instance().get_fps_object().base;
}

void games::eft::c_updater::update_world_object()
{
	Instance().world_object = games::eft::c_game_objects::Instance().get_game_world().base;
}

void games::eft::c_updater::setup()
{
	//CreateThread(0, 0, (LPTHREAD_START_ROUTINE)games::eft::fps_object_routine, 0, 0, 0);
	CreateThread(0, 0, (LPTHREAD_START_ROUTINE)games::eft::player_routine, 0, 0, 0);
}

void games::eft::world_object_routine()
{
	while (0xDEAD != 0xF00D)
	{
		games::eft::c_updater::Instance().update_world_object();
		printf("[%04x] %p - world\n", GetTickCount(), games::eft::c_updater::Instance().world_object);

		std::this_thread::sleep_for(std::chrono::seconds(1));
	}
}

void games::eft::fps_object_routine()
{
	while (0xDEAD != 0xF00D)
	{
		games::eft::c_updater::Instance().update_fps_object();
		games::eft::c_updater::Instance().update_world_object();
		
		printf("[%04x] %p - world\n", GetTickCount(), games::eft::c_updater::Instance().world_object);
		printf("[%04x] %p - fps\n\n", GetTickCount(), games::eft::c_updater::Instance().fps_object);

		std::this_thread::sleep_for(std::chrono::seconds(1));
	}
}

void games::eft::player_routine()
{
	while (0xDEAD != 0xF00D)
	{
		games::eft::c_updater::Instance().update_players();
	}
}
