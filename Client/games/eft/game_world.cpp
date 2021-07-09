#include <inc.hpp>

UINT64 games::eft::c_game_world::get_exfiltration_array()
{
    uint64_t PlayerExfiltrationPoints = games::c_phys_util::Instance().phys_read<uint64_t>(this->base + 0x18);
    uint64_t ExfiltrationArray = games::c_phys_util::Instance().phys_read<uint64_t>(PlayerExfiltrationPoints + 0x20);
    return ExfiltrationArray;
}

int games::eft::c_game_world::get_exfiltration_count()
{
    uint64_t PlayerExfiltrationPoints = games::c_phys_util::Instance().phys_read<uint64_t>(this->base + 0x18);
    uint64_t ExfiltrationArray = games::c_phys_util::Instance().phys_read<uint64_t>(PlayerExfiltrationPoints + 0x20);
    return games::c_phys_util::Instance().phys_read<int32_t>(ExfiltrationArray + 0x18);
}

games::eft::t_players games::eft::c_game_world::get_players()
{
    if (!base) return {};

    auto ret = games::eft::t_players();

    uint64_t RegisteredPlayers = games::c_phys_util::Instance().phys_read<uint64_t>(this->base + 0x80);
    if (!RegisteredPlayers) return ret;

    uint64_t PlayerArray = games::c_phys_util::Instance().phys_read<uint64_t>(RegisteredPlayers + 0x10);
    if (!PlayerArray) return ret;
   
    uint32_t PlayerCount = games::c_phys_util::Instance().phys_read<uint32_t>(RegisteredPlayers + 0x18);
    if (!PlayerCount  || PlayerCount > 60) return ret;

    for (int i = 0; i < PlayerCount && i < 50; i++)
    {
        games::eft::c_player CurrentPlayer = games::c_phys_util::Instance().phys_read<uint64_t>(PlayerArray + 0x20 + (i * 0x8));
        if (!CurrentPlayer.base) continue;
        ret.push_back(CurrentPlayer);
    }

    return ret;
}

games::eft::c_player games::eft::c_game_world::get_local()
{
    if (!base) return 0;
    
    uint64_t RegisteredPlayers = games::c_phys_util::Instance().phys_read<uint64_t>(this->base + 0x80);
    uint64_t PlayerArray = games::c_phys_util::Instance().phys_read<uint64_t>(RegisteredPlayers + 0x10);
    uint32_t PlayerCount = games::c_phys_util::Instance().phys_read<uint32_t>(RegisteredPlayers + 0x18);

    if (PlayerCount > 100)
        return 0;

    for (int i = 0; i < PlayerCount; i++)
    {
        uint64_t CurrentPlayer = games::c_phys_util::Instance().phys_read<uint64_t>(PlayerArray + 0x20 + (i * 0x8));
        if (games::c_phys_util::Instance().phys_read<bool>(CurrentPlayer + 0x5f1))
            return CurrentPlayer;
    }

    return 0;
}
