#include <inc.hpp>

void games::eft::c_game_objects::dump_objects()
{
    auto game_object_manager = games::c_phys_util::Instance().phys_read<UINT64>(games::c_phys_util::Instance().base + 0x156C698);

    if (!game_object_manager) return;
    std::ofstream Out("ObjectDump.txt");
    Out.clear();

    for (uint64_t CurrentObject = games::c_phys_util::Instance().phys_read<uint64_t>(game_object_manager + 0x18);
        CurrentObject != games::c_phys_util::Instance().phys_read<uint64_t>(game_object_manager + 0x10);
        CurrentObject = games::c_phys_util::Instance().phys_read<uint64_t>(CurrentObject + 0x8))
    {
        uint64_t CurrentGameObject = games::c_phys_util::Instance().phys_read<uint64_t>(CurrentObject + 0x10);
        if (!CurrentGameObject)
            break;
        uint64_t pCurrentObjectName = games::c_phys_util::Instance().phys_read<uint64_t>(CurrentGameObject + 0x60);
        
        struct s_block { char mem[100]; };
        auto a = games::c_phys_util::Instance().phys_read<s_block>(pCurrentObjectName);

        Out << "Object: " << std::string(a.mem).c_str() << " | Address: " << std::hex << CurrentGameObject << "\n";
    }

    Out << "Type Switch!\n";

    for (uint64_t CurrentObject = games::c_phys_util::Instance().phys_read<uint64_t>(game_object_manager + 0x8);;
        CurrentObject = games::c_phys_util::Instance().phys_read<uint64_t>(CurrentObject + 0x8))
    {
        uint64_t CurrentGameObject = games::c_phys_util::Instance().phys_read<uint64_t>(CurrentObject + 0x10);
        if (!CurrentGameObject)
            break;
        uint64_t pCurrentObjectName = games::c_phys_util::Instance().phys_read<uint64_t>(CurrentGameObject + 0x60);

        struct s_block { char mem[100]; };
        auto a = games::c_phys_util::Instance().phys_read<s_block>(pCurrentObjectName);

        Out << "Object: " << std::string(a.mem).c_str() << " | Address: " << std::hex << CurrentGameObject << "\n";
        if (CurrentObject == games::c_phys_util::Instance().phys_read<uint64_t>(game_object_manager))
            break;
    }
    Out.close();
    printf("Done looping objects!\n");
}

games::eft::c_game_world games::eft::c_game_objects::get_game_world()
{
    auto game_object_manager = games::c_phys_util::Instance().phys_read<UINT64>(games::c_phys_util::Instance().base + 0x156C698);
    if (!game_object_manager) return 0;

    auto cur = games::c_phys_util::Instance().phys_read<uint64_t>(game_object_manager);

    for (uint64_t CurrentObject = games::c_phys_util::Instance().phys_read<uint64_t>(game_object_manager + 0x18); CurrentObject != games::c_phys_util::Instance().phys_read<uint64_t>(game_object_manager + 0x10); CurrentObject = games::c_phys_util::Instance().phys_read<uint64_t>(CurrentObject + 0x8))
    {
        uint64_t CurrentGameObject = games::c_phys_util::Instance().phys_read<uint64_t>(CurrentObject + 0x10);
       
        if (!CurrentGameObject) continue;

        if (CurrentObject == cur) break;

        uint64_t pCurrentObjectName = games::c_phys_util::Instance().phys_read<uint64_t>(CurrentGameObject + 0x60);
        
        struct s_block { char mem[100]; };
        auto a = games::c_phys_util::Instance().phys_read<s_block>(pCurrentObjectName);

        if (strstr(a.mem, "GameWorld") != nullptr)
        {
            uint64_t ObjectClass = games::c_phys_util::Instance().phys_read<uint64_t>(CurrentGameObject + 0x30);
            if (!ObjectClass) continue;

            uint64_t Entity = games::c_phys_util::Instance().phys_read<uint64_t>(ObjectClass + 0x18);
            if (!Entity) continue;

            uint64_t BaseEntity = games::c_phys_util::Instance().phys_read<uint64_t>(Entity + 0x28);
            if (!BaseEntity) continue;

            UINT64 World = BaseEntity;

            uint64_t PlayerExfiltrationPoints = games::c_phys_util::Instance().phys_read<uint64_t>(World + 0x18);
            if (!PlayerExfiltrationPoints) continue;
           
            uint64_t ExfiltrationArray = games::c_phys_util::Instance().phys_read<uint64_t>(PlayerExfiltrationPoints + 0x20);
            if (!ExfiltrationArray) continue;
            
            if (games::c_phys_util::Instance().phys_read<int32_t>(ExfiltrationArray + 0x18) > 0) return World;
        }
    }
    return 0;
}

games::eft::c_camera games::eft::c_game_objects::get_fps_object()
{
    auto game_object_manager = games::c_phys_util::Instance().phys_read<UINT64>(games::c_phys_util::Instance().base + 0x156C698);
    if (!game_object_manager) return 0;
    auto cur = games::c_phys_util::Instance().phys_read<uint64_t>(game_object_manager);

    for (uint64_t CurrentObject = games::c_phys_util::Instance().phys_read<uint64_t>(game_object_manager + 0x8);;
        CurrentObject = games::c_phys_util::Instance().phys_read<uint64_t>(CurrentObject + 0x8))
    {
        uint64_t CurrentGameObject = games::c_phys_util::Instance().phys_read<uint64_t>(CurrentObject + 0x10);
        if (!CurrentGameObject) continue;

        uint64_t pCurrentObjectName = games::c_phys_util::Instance().phys_read<uint64_t>(CurrentGameObject + 0x60);
        if (!pCurrentObjectName) continue;

        std::string GameObjectName;

        struct s_block { char mem[100]; };
        auto a = games::c_phys_util::Instance().phys_read<s_block>(pCurrentObjectName);

        if (strstr(a.mem, "FPS Camera") != nullptr) return CurrentGameObject;

        if (CurrentObject == games::c_phys_util::Instance().phys_read<uint64_t>(game_object_manager))
            break;
    }
    return 0;
}

UINT64 games::eft::c_game_objects::get_optic_object()
{
    auto game_object_manager = games::c_phys_util::Instance().phys_read<UINT64>(games::c_phys_util::Instance().base + 0x156C698);
    if (!game_object_manager) return 0;

    for (uint64_t CurrentObject = games::c_phys_util::Instance().phys_read<uint64_t>(game_object_manager + 0x8);;
        CurrentObject = games::c_phys_util::Instance().phys_read<uint64_t>(CurrentObject + 0x8))
    {
        uint64_t CurrentGameObject = games::c_phys_util::Instance().phys_read<uint64_t>(CurrentObject + 0x10);

        if (!CurrentGameObject)
            continue;

        uint64_t pCurrentObjectName = games::c_phys_util::Instance().phys_read<uint64_t>(CurrentGameObject + 0x60);

        struct s_block { char mem[100]; };
        auto a = games::c_phys_util::Instance().phys_read<s_block>(pCurrentObjectName);

        if (strstr(a.mem, "aim_camera") != nullptr)
        {
            if (this->check_matrix(CurrentGameObject)) return CurrentGameObject;
            break;
        }

        std::this_thread::sleep_for(std::chrono::milliseconds(1));
       
        if (CurrentObject == games::c_phys_util::Instance().phys_read<uint64_t>(game_object_manager))
            break;
    }
    return 0;
}

bool games::eft::c_game_objects::check_matrix(UINT64 optic_object)
{
    uint64_t Camera = games::c_phys_util::Instance().phys_read<uint64_t>(optic_object + 0x30);
    uint64_t CameraObject = games::c_phys_util::Instance().phys_read<uint64_t>(optic_object + 0x18);

    float FMatrix = games::c_phys_util::Instance().phys_read<float>(CameraObject + 0x90);
    float SMatrix = games::c_phys_util::Instance().phys_read<float>(CameraObject + 0x114);
    float FMatrix2 = games::c_phys_util::Instance().phys_read<float>(CameraObject + 0x60);
    float SMatrix2 = games::c_phys_util::Instance().phys_read<float>(CameraObject + 0xE0);

    float SMatrixInverse = SMatrix * -1.0;
    float SMatrix2Inverse = SMatrix2 * -1.0;

    if (FMatrix == SMatrixInverse && FMatrix2 == SMatrix2Inverse)
    {
        return true;
    }

    return false;
}
