#include <inc.hpp>

games::c_vector3 games::eft::c_player::get_pos()
{

    uint64_t PlayerBody = games::c_phys_util::Instance().phys_read<uint64_t>(this->base + 0xa8);
    if (!PlayerBody) return {};

    uint64_t SkeletonRootJoint = games::c_phys_util::Instance().phys_read<uint64_t>(PlayerBody + 0x28);
    if (!SkeletonRootJoint) return {};

    uint64_t Values = games::c_phys_util::Instance().phys_read<uint64_t>(SkeletonRootJoint + 0x28);
    if (!Values) return {};

    uint64_t Skeleton = games::c_phys_util::Instance().phys_read<uint64_t>(Values + 0x10);
    if (!Skeleton) return {};

    uint64_t BoneAddress = games::c_phys_util::Instance().phys_read<uint64_t>(Skeleton + 0x20 + 133 * 0x8);
    if (!BoneAddress) return {};
    
    c_transform Bone = BoneAddress;

    return Bone.get_position();
}

games::c_vector3 games::eft::c_player::get_pos_root()
{
    uint64_t TransformAddress = games::c_phys_util::Instance().phys_read<uint64_t>(this->base + 0x10);

    TransformAddress = games::c_phys_util::Instance().phys_read<uint64_t>(TransformAddress + 0x30);

    TransformAddress = games::c_phys_util::Instance().phys_read<uint64_t>(TransformAddress + 0x30);

    TransformAddress = games::c_phys_util::Instance().phys_read<uint64_t>(TransformAddress + 0x8);

    TransformAddress = games::c_phys_util::Instance().phys_read<uint64_t>(TransformAddress + 0x38);
    if (!TransformAddress)
    {
        return games::c_vector3(0, 0, 0);
    }

    return games::c_phys_util::Instance().phys_read<games::c_vector3>(TransformAddress + 0xb0);
}

games::c_vector3 games::eft::c_player::get_pos_head()
{
    //4d0 : PlayerBones (type: PlayerBones)
    /*
    22a43095970 : PlayerBones
			static fields
			fields
				18 : Player (type: EFT.Player)
				20 : Weapon_Root_Third (type: UnityEngine.Transform)
				28 : Weapon_Root_Anim (type: UnityEngine.Transform)
				30 : Neck (type: UnityEngine.Transform)
				38 : Weapon_reference_point (type: UnityEngine.Transform)
				190 : R_Neck (type: UnityEngine.Vector3)
				19c : R_Head (type: UnityEngine.Vector3)
				40 : Shoulders (type: UnityEngine.Transform[])
				48 : Shoulders_Anim (type: UnityEngine.Transform[])
				50 : Upperarms (type: UnityEngine.Transform[])
				58 : Forearms (type: UnityEngine.Transform[])
				60 : LeftPalm (type: UnityEngine.Transform)
				68 : RightPalm (type: UnityEngine.Transform)
				70 : LootRaycastOrigin (type: UnityEngine.Transform)
				78 : RootJoint (type: UnityEngine.Transform)
				80 : HolsterPrimary (type: UnityEngine.Transform)
				88 : HolsterPrimaryAlternative (type: UnityEngine.Transform)
				90 : HolsterSecondary (type: UnityEngine.Transform)
				98 : HolsterSecondaryAlternative (type: UnityEngine.Transform)
				a0 : HolsterPistol (type: UnityEngine.Transform)
				a8 : LeftLegHolsterPistol (type: UnityEngine.Transform)
				b0 : BendGoals (type: UnityEngine.Transform[])
				b8 : KickingFoot (type: UnityEngine.Transform)
				c0 : FovSpecialTransforms (type: UnityEngine.Transform[])
				c8 : WeaponRoot (type: EFT.BifacialTransform)
				d0 : Ribcage (type: EFT.BifacialTransform)
				d8 : Head (type: EFT.BifacialTransform)
				e0 : LeftShoulder (type: EFT.BifacialTransform)
				e8 : RightShoulder (type: EFT.BifacialTransform)
				f0 : LeftThigh2 (type: EFT.BifacialTransform)
				f8 : RightThigh2 (type: EFT.BifacialTransform)
				100 : BodyTransform (type: EFT.BifacialTransform)
				108 : AnimatedTransform (type: EFT.BifacialTransform)
				110 : Pelvis (type: EFT.BifacialTransform)
				118 : LeftThigh1 (type: EFT.BifacialTransform)
				120 : RightThigh1 (type: EFT.BifacialTransform)
				128 : Spine3 (type: EFT.BifacialTransform)
				1a8 : Offset (type: UnityEngine.Vector3)
				1b4 : DeltaRotation (type: UnityEngine.Quaternion)
				130 : LeftHandCollider (type: BodyPartCollider)
				138 : Fireport (type: EFT.BifacialTransform)
				140 : BifacialTransforms (type: System.Collections.Generic.Dictionary<PlayerBoneType,EFT.BifacialTransform>)
				148 : BodyPartColliders (type: BodyPartCollider[])
				150 : BodyPartCollidersDictionary (type: System.Collections.Generic.Dictionary<EBodyPartColliderType,BodyPartCollider>)
				158 : BodyPartCollidersHashSet (type: System.Collections.Generic.HashSet<UnityEngine.Collider>)
				1c4 : ThirdPersonAuthority (type: System.Single)
				160 : \uE000 (type: UnityEngine.AnimationCurve)
				1c8 : \uE001 (type: System.Single)
				1cc : \uE002 (type: System.Single)
				1d0 : \uE003 (type: PlayerBones.ETransitionType)
				168 : HeadRotationCurve (type: UnityEngine.AnimationCurve)
				170 : Spine1 (type: UnityEngine.Transform)
				178 : \uE004 (type: PlayerBones.)
				1d4 : HeadChain (type: System.Single)
				1d8 : NeckChain (type: System.Single)
    */
    uint64_t PlayerBones = games::c_phys_util::Instance().phys_read<uint64_t>(this->base + 0x4e8);
    if (!PlayerBones) return {};
    
    uint64_t Head = games::c_phys_util::Instance().phys_read<uint64_t>(PlayerBones + 0xe0);
    if (!Head) return {};
    
    uint64_t BoneAddress = games::c_phys_util::Instance().phys_read<uint64_t>(Head + 0x10);
    if (!BoneAddress) return {};

    c_transform Bone = BoneAddress;

    return Bone.get_position();
}

bool games::eft::c_player::exists()
{
    uint64_t TransformAddress = games::c_phys_util::Instance().phys_read<uint64_t>(this->base + 0x10);
    if (!TransformAddress)
    {
        return false;
    }
    TransformAddress = games::c_phys_util::Instance().phys_read<uint64_t>(TransformAddress + 0x30);
    if (!TransformAddress)
    {
        return false;
    }
    TransformAddress = games::c_phys_util::Instance().phys_read<uint64_t>(TransformAddress + 0x30);
    if (!TransformAddress)
    {
        return false;
    }
    TransformAddress = games::c_phys_util::Instance().phys_read<uint64_t>(TransformAddress + 0x8);
    if (!TransformAddress)
    {
        return false;
    }
    TransformAddress = games::c_phys_util::Instance().phys_read<uint64_t>(TransformAddress + 0x38);
    if (!TransformAddress)
    {
        return false;
    }

    auto Pos = games::c_phys_util::Instance().phys_read<games::c_vector3>(TransformAddress + 0xb0);

    return (Pos.x && Pos.y && Pos.z);
}

bool games::eft::c_player::has_bone(int id)
{
    uint64_t PlayerBody = games::c_phys_util::Instance().phys_read<uint64_t>(this->base + 0xa8);
    if (!PlayerBody)
        return false;

    uint64_t SkeletonRootJoint = games::c_phys_util::Instance().phys_read<uint64_t>(PlayerBody + 0x28);
    if (!SkeletonRootJoint)
        return false;

    uint64_t Values = games::c_phys_util::Instance().phys_read<uint64_t>(SkeletonRootJoint + 0x28);
    if (!Values)
        return false;

    uint64_t Skeleton = games::c_phys_util::Instance().phys_read<uint64_t>(Values + 0x10);
    if (!Skeleton)
        return false;

    uint64_t BoneAddress = games::c_phys_util::Instance().phys_read<uint64_t>(Skeleton + 0x20 + id * 0x8);
    if (!BoneAddress)
        return false;

    return true;
}

games::c_vector3 games::eft::c_player::get_bone(Bones bone)
{
    uint64_t PlayerBody = games::c_phys_util::Instance().phys_read<uint64_t>(this->base + 0xa8);
    if (!PlayerBody) return {};

    uint64_t SkeletonRootJoint = games::c_phys_util::Instance().phys_read<uint64_t>(PlayerBody + 0x28);
    if (!SkeletonRootJoint) return {};

    uint64_t Values = games::c_phys_util::Instance().phys_read<uint64_t>(SkeletonRootJoint + 0x28);
    if (!Values) return {};

    uint64_t Skeleton = games::c_phys_util::Instance().phys_read<uint64_t>(Values + 0x10);
    if (!Skeleton) return {};

    uint64_t BoneAddress = games::c_phys_util::Instance().phys_read<uint64_t>(Skeleton + 0x20 + bone * 0x8);
    if (!BoneAddress) return {};

    c_transform Bone = BoneAddress;

    return Bone.get_position();
}

games::c_vector3 games::eft::c_player::get_fireport()
{
    uint64_t PlayerBones = games::c_phys_util::Instance().phys_read<uint64_t>(this->base + 0x4e8);
    if (PlayerBones == 0)
    {
        return { 0.0, 0.0, 0.0 };
    }
    uint64_t Fireport = games::c_phys_util::Instance().phys_read<uint64_t>(PlayerBones + 0x140);
    uint64_t BoneAddress = games::c_phys_util::Instance().phys_read<uint64_t>(Fireport + 0x10);

    c_transform Bone = BoneAddress;
    return Bone.get_position();
}

UINT64 games::eft::c_player::get_profile()
{
    /*
    * -> : EFT.Profile\r\n
    * 
    22a42f94938 : EFT.Profile
			static fields
			fields
				10 : Id (type: System.String)
				18 : AccountId (type: System.String)
				20 : PetId (type: System.String)
				28 : Info (type: \uE51C)
				30 : Customization (type: \uE51A)
				38 : Encyclopedia (type: System.Collections.Generic.Dictionary<System.String,System.Boolean>)
				40 : Health (type: EFT.Profile.)
				48 : Inventory (type: \uE7F2)
				50 : QuestItems (type: \uE387)
				58 : InsuredItems (type: \uE38B)
				60 : Skills (type: \uE533)
				68 : Notes (type: \uE6EE)
				70 : Quests (type: \uE663)
				78 : ConditionCounters (type: EFT.Quests.ConditionCounterManager)
				80 : BackendCounters (type: System.Collections.Generic.Dictionary<System.String,>)
				88 : Bonuses (type: \uE3FE)
				90 : Hideout (type: EFT.HideoutInfo)
				98 : RagfairInfo (type: EFT.Profile.)
				a0 : <BonusController>k__BackingField (type: EFT.BonusController)
				a8 : <TraderStandings>k__BackingField (type: System.Collections.Generic.Dictionary<System.String,EFT.Loyalty>)
				b0 : WishList (type: System.String[])
				b8 : _emptyResourceCollection (type: EFT.ResourceKey[])
				c0 : OnItemZoneDropped (type: System.Action<System.String,System.String>)
				c8 : OnTraderStandingChanged (type: System.Action<System.String>)
				d0 : OnTraderLoyaltyChanged (type: System.Action<System.String>)
				d8 : Stats (type: \uE21F)
				e0 : CheckedMagazines (type: System.Collections.Generic.Dictionary<System.String,System.Int32>)
				e8 : CheckedChambers (type: System.Collections.Generic.List<System.String>)
    */
    return games::c_phys_util::Instance().phys_read<UINT64>(this->base + 0x458);
}

UINT64 games::eft::c_player::get_info()
{
    /*
    22a4345ab38 : \uE51C (get_info)
			static fields
			fields
				10 : Nickname (type: System.String)
				50 : Side (type: EFT.EPlayerSide)
				54 : RegistrationDate (type: System.Int32)
				58 : SavageLockTime (type: System.Double)
				18 : GroupId (type: System.String)
				20 : EntryPoint (type: System.String)
				28 : Voice (type: System.String)
				60 : NicknameChangeDate (type: System.Int32)
				30 : Bans (type: System.Collections.Generic.List<>)
				38 : Settings (type: \uE513)
				64 : MemberCategory (type: EMemberCategory)
				68 : \uE000 (type: System.Int32)
				40 : \uE001 (type: System.Action<System.Int32,System.Int32>)
				48 : \uE002 (type: System.Action<System.Int32,System.Int32>)
    */
    return games::c_phys_util::Instance().phys_read<UINT64>(this->get_profile() + 0x28);
}

bool games::eft::c_player::is_ai()
{
    //0x54 : RegistrationDate (type: System.Int32)
    if (games::c_phys_util::Instance().phys_read<uint32_t>(this->get_info() + 0x54) <= 0)  return true;
    else return false;
}

bool games::eft::c_player::is_aiming()
{
    auto weapon_animation = games::c_phys_util::Instance().phys_read<UINT64>(this->base + 0x190);//190 : \uE04A (type: EFT.Animations.ProceduralWeaponAnimation)
    auto breath = games::c_phys_util::Instance().phys_read<UINT64>(weapon_animation + 0x28);//28 : Breath (type: EFT.Animations.BreathEffector)
    return games::c_phys_util::Instance().phys_read<bool>(breath + 0xa0);//a0 : IsAiming (type: System.Boolean)
}

UINT64 games::eft::c_player::get_mp_camera()
{
    auto weapon_animation = games::c_phys_util::Instance().phys_read<UINT64>(this->base + 0x190);//190 : \uE04A (type: EFT.Animations.ProceduralWeaponAnimation)
    auto a4 = games::c_phys_util::Instance().phys_read<UINT64>(weapon_animation + 0x88);//88 : _currentAimingPlane (type: WeaponPrefab.AimPlane)
    return games::c_phys_util::Instance().phys_read<UINT64>(a4 + 0x20);
}

bool games::eft::c_player::get_visible(Bones bone)
{
    /*auto player_body = games::c_phys_util::Instance().phys_read<UINT64>(this->base + 0xa8);
    if (!player_body) return false;

    auto body_skins = games::c_phys_util::Instance().phys_read<std::map<int, UINT64>>(player_body + 0x38);
    if (!body_skins.size()) return false;

    for (auto a : body_skins)
    {
        if (a.first == Bones::HumanHead)
        {
            printf("found the head man\n");
            auto _lods = games::c_phys_util::Instance().phys_read<std::vector<UINT64>>(a.second + 0x18);

        }
    }*/
}
