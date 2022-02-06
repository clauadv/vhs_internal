#include "bones.h"

std::array<std::vector < std::pair < int, int > >, 4> bone_array;

void bones::initialize() {
	{
		//werewolf bones
		auto& bone = bone_array[0];

		bone.emplace_back(std::make_pair(killer::werewolf::Head_M, killer::werewolf::Neck_M));
		bone.emplace_back(std::make_pair(killer::werewolf::Neck_M, killer::werewolf::Chest_M));
		bone.emplace_back(std::make_pair(killer::werewolf::Chest_M, killer::werewolf::pelvis));

		// left
		{
			bone.emplace_back(std::make_pair(killer::werewolf::Neck_M, killer::werewolf::Shoulder_L));
			bone.emplace_back(std::make_pair(killer::werewolf::Shoulder_L, killer::werewolf::Elbow_L));
			bone.emplace_back(std::make_pair(killer::werewolf::Elbow_L, killer::werewolf::Wrist_L));

			bone.emplace_back(std::make_pair(killer::werewolf::Wrist_L, killer::werewolf::ThumbFinger1_L));
			bone.emplace_back(std::make_pair(killer::werewolf::ThumbFinger1_L, killer::werewolf::ThumbFinger2_L));
			bone.emplace_back(std::make_pair(killer::werewolf::ThumbFinger2_L, killer::werewolf::ThumbFinger3_L));
			bone.emplace_back(std::make_pair(killer::werewolf::ThumbFinger3_L, killer::werewolf::ThumbFinger4_L));

			bone.emplace_back(std::make_pair(killer::werewolf::Wrist_L, killer::werewolf::IndexFinger1_L));
			bone.emplace_back(std::make_pair(killer::werewolf::IndexFinger1_L, killer::werewolf::IndexFinger2_L));
			bone.emplace_back(std::make_pair(killer::werewolf::IndexFinger2_L, killer::werewolf::IndexFinger3_L));
			bone.emplace_back(std::make_pair(killer::werewolf::IndexFinger3_L, killer::werewolf::IndexFinger4_L));

			bone.emplace_back(std::make_pair(killer::werewolf::Wrist_L, killer::werewolf::MiddleFinger1_L));
			bone.emplace_back(std::make_pair(killer::werewolf::MiddleFinger1_L, killer::werewolf::MiddleFinger2_L));
			bone.emplace_back(std::make_pair(killer::werewolf::MiddleFinger2_L, killer::werewolf::MiddleFinger3_L));
			bone.emplace_back(std::make_pair(killer::werewolf::MiddleFinger3_L, killer::werewolf::MiddleFinger4_L));

			bone.emplace_back(std::make_pair(killer::werewolf::Wrist_L, killer::werewolf::RingFinger1_L));
			bone.emplace_back(std::make_pair(killer::werewolf::RingFinger1_L, killer::werewolf::RingFinger2_L));
			bone.emplace_back(std::make_pair(killer::werewolf::RingFinger2_L, killer::werewolf::RingFinger3_L));
			bone.emplace_back(std::make_pair(killer::werewolf::RingFinger3_L, killer::werewolf::RingFinger4_L));

			bone.emplace_back(std::make_pair(killer::werewolf::Wrist_L, killer::werewolf::PinkyFinger1_L));
			bone.emplace_back(std::make_pair(killer::werewolf::PinkyFinger1_L, killer::werewolf::PinkyFinger2_L));
			bone.emplace_back(std::make_pair(killer::werewolf::PinkyFinger2_L, killer::werewolf::PinkyFinger3_L));
			bone.emplace_back(std::make_pair(killer::werewolf::PinkyFinger3_L, killer::werewolf::PinkyFinger4_L));

			bone.emplace_back(std::make_pair(killer::werewolf::pelvis, killer::werewolf::Hip_L));
			bone.emplace_back(std::make_pair(killer::werewolf::Hip_L, killer::werewolf::Knee_L));
			bone.emplace_back(std::make_pair(killer::werewolf::Knee_L, killer::werewolf::KneePart1_L));
			bone.emplace_back(std::make_pair(killer::werewolf::KneePart1_L, killer::werewolf::Ankle_L));
			bone.emplace_back(std::make_pair(killer::werewolf::Ankle_L, killer::werewolf::Toes_L));
		}

		// right
		{
			bone.emplace_back(std::make_pair(killer::werewolf::Neck_M, killer::werewolf::Shoulder_R));
			bone.emplace_back(std::make_pair(killer::werewolf::Shoulder_R, killer::werewolf::Elbow_R));
			bone.emplace_back(std::make_pair(killer::werewolf::Elbow_R, killer::werewolf::Wrist_R));

			bone.emplace_back(std::make_pair(killer::werewolf::Wrist_R, killer::werewolf::ThumbFinger1_R));
			bone.emplace_back(std::make_pair(killer::werewolf::ThumbFinger1_R, killer::werewolf::ThumbFinger2_R));
			bone.emplace_back(std::make_pair(killer::werewolf::ThumbFinger2_R, killer::werewolf::ThumbFinger3_R));
			bone.emplace_back(std::make_pair(killer::werewolf::ThumbFinger3_R, killer::werewolf::ThumbFinger4_R));

			bone.emplace_back(std::make_pair(killer::werewolf::Wrist_R, killer::werewolf::IndexFinger1_R));
			bone.emplace_back(std::make_pair(killer::werewolf::IndexFinger1_R, killer::werewolf::IndexFinger2_R));
			bone.emplace_back(std::make_pair(killer::werewolf::IndexFinger2_R, killer::werewolf::IndexFinger3_R));
			bone.emplace_back(std::make_pair(killer::werewolf::IndexFinger3_R, killer::werewolf::IndexFinger4_R));

			bone.emplace_back(std::make_pair(killer::werewolf::Wrist_R, killer::werewolf::MiddleFinger1_R));
			bone.emplace_back(std::make_pair(killer::werewolf::MiddleFinger1_R, killer::werewolf::MiddleFinger2_R));
			bone.emplace_back(std::make_pair(killer::werewolf::MiddleFinger2_R, killer::werewolf::MiddleFinger3_R));
			bone.emplace_back(std::make_pair(killer::werewolf::MiddleFinger3_R, killer::werewolf::MiddleFinger4_R));

			bone.emplace_back(std::make_pair(killer::werewolf::Wrist_R, killer::werewolf::RingFinger1_R));
			bone.emplace_back(std::make_pair(killer::werewolf::RingFinger1_R, killer::werewolf::RingFinger2_R));
			bone.emplace_back(std::make_pair(killer::werewolf::RingFinger2_R, killer::werewolf::RingFinger3_R));
			bone.emplace_back(std::make_pair(killer::werewolf::RingFinger3_R, killer::werewolf::RingFinger4_R));

			bone.emplace_back(std::make_pair(killer::werewolf::Wrist_R, killer::werewolf::PinkyFinger1_R));
			bone.emplace_back(std::make_pair(killer::werewolf::PinkyFinger1_R, killer::werewolf::PinkyFinger2_R));
			bone.emplace_back(std::make_pair(killer::werewolf::PinkyFinger2_R, killer::werewolf::PinkyFinger3_R));
			bone.emplace_back(std::make_pair(killer::werewolf::PinkyFinger3_R, killer::werewolf::PinkyFinger4_R));

			bone.emplace_back(std::make_pair(killer::werewolf::pelvis, killer::werewolf::Hip_R));
			bone.emplace_back(std::make_pair(killer::werewolf::Hip_R, killer::werewolf::Knee_R));
			bone.emplace_back(std::make_pair(killer::werewolf::Knee_R, killer::werewolf::KneePart1_R));
			bone.emplace_back(std::make_pair(killer::werewolf::KneePart1_R, killer::werewolf::Ankle_R));
			bone.emplace_back(std::make_pair(killer::werewolf::Ankle_R, killer::werewolf::Toes_R));
		}
	}

	{
		// toad bones
		auto& bone = bone_array[1];

		bone.emplace_back(std::make_pair(killer::toad::Head_M, killer::toad::Neck_M));
		bone.emplace_back(std::make_pair(killer::toad::Neck_M, killer::toad::Chest_M));
		bone.emplace_back(std::make_pair(killer::toad::Chest_M, killer::toad::pelvis));

		// left
		{
			bone.emplace_back(std::make_pair(killer::toad::Neck_M, killer::toad::Shoulder_L));
			bone.emplace_back(std::make_pair(killer::toad::Shoulder_L, killer::toad::Elbow_L));
			bone.emplace_back(std::make_pair(killer::toad::Elbow_L, killer::toad::Wrist_L));

			bone.emplace_back(std::make_pair(killer::toad::Wrist_L, killer::toad::ThumbFinger1_L));
			bone.emplace_back(std::make_pair(killer::toad::ThumbFinger1_L, killer::toad::ThumbFinger2_L));
			bone.emplace_back(std::make_pair(killer::toad::ThumbFinger2_L, killer::toad::ThumbFinger3_L));
			bone.emplace_back(std::make_pair(killer::toad::ThumbFinger3_L, killer::toad::ThumbFinger4_L));

			bone.emplace_back(std::make_pair(killer::toad::Wrist_L, killer::toad::IndexFinger1_L));
			bone.emplace_back(std::make_pair(killer::toad::IndexFinger1_L, killer::toad::IndexFinger2_L));
			bone.emplace_back(std::make_pair(killer::toad::IndexFinger2_L, killer::toad::IndexFinger3_L));
			bone.emplace_back(std::make_pair(killer::toad::IndexFinger3_L, killer::toad::IndexFinger4_L));

			bone.emplace_back(std::make_pair(killer::toad::Wrist_L, killer::toad::MiddleFinger1_L));
			bone.emplace_back(std::make_pair(killer::toad::MiddleFinger1_L, killer::toad::MiddleFinger2_L));
			bone.emplace_back(std::make_pair(killer::toad::MiddleFinger2_L, killer::toad::MiddleFinger3_L));
			bone.emplace_back(std::make_pair(killer::toad::MiddleFinger3_L, killer::toad::MiddleFinger4_L));

			bone.emplace_back(std::make_pair(killer::toad::Wrist_L, killer::toad::RingFinger1_L));
			bone.emplace_back(std::make_pair(killer::toad::RingFinger1_L, killer::toad::RingFinger2_L));
			bone.emplace_back(std::make_pair(killer::toad::RingFinger2_L, killer::toad::RingFinger3_L));
			bone.emplace_back(std::make_pair(killer::toad::RingFinger3_L, killer::toad::RingFinger4_L));

			bone.emplace_back(std::make_pair(killer::toad::pelvis, killer::toad::Hip_L));
			bone.emplace_back(std::make_pair(killer::toad::Hip_L, killer::toad::Hip1_L));
			bone.emplace_back(std::make_pair(killer::toad::Hip1_L, killer::toad::Hip2_L));
			bone.emplace_back(std::make_pair(killer::toad::Hip2_L, killer::toad::Ankle_L));
			bone.emplace_back(std::make_pair(killer::toad::Ankle_L, killer::toad::Toes_L));

			bone.emplace_back(std::make_pair(killer::toad::Toes_L, killer::toad::bigToe1_L));
			bone.emplace_back(std::make_pair(killer::toad::bigToe1_L, killer::toad::bigToe2_L));
			bone.emplace_back(std::make_pair(killer::toad::bigToe2_L, killer::toad::bigToe3_L));

			bone.emplace_back(std::make_pair(killer::toad::Toes_L, killer::toad::MiddleToe1_L));
			bone.emplace_back(std::make_pair(killer::toad::MiddleToe1_L, killer::toad::MiddleToe2_L));
			bone.emplace_back(std::make_pair(killer::toad::MiddleToe2_L, killer::toad::MiddleToe3_L));

			bone.emplace_back(std::make_pair(killer::toad::Toes_L, killer::toad::PinkyToe1_L));
			bone.emplace_back(std::make_pair(killer::toad::PinkyToe1_L, killer::toad::PinkyToe2_L));
			bone.emplace_back(std::make_pair(killer::toad::PinkyToe2_L, killer::toad::PinkyToe3_L));
		}

		// right
		{
			bone.emplace_back(std::make_pair(killer::toad::Neck_M, killer::toad::Shoulder_R));
			bone.emplace_back(std::make_pair(killer::toad::Shoulder_R, killer::toad::Elbow_R));
			bone.emplace_back(std::make_pair(killer::toad::Elbow_R, killer::toad::Wrist_R));

			bone.emplace_back(std::make_pair(killer::toad::Wrist_R, killer::toad::ThumbFinger1_R));
			bone.emplace_back(std::make_pair(killer::toad::ThumbFinger1_R, killer::toad::ThumbFinger2_R));
			bone.emplace_back(std::make_pair(killer::toad::ThumbFinger2_R, killer::toad::ThumbFinger3_R));
			bone.emplace_back(std::make_pair(killer::toad::ThumbFinger3_R, killer::toad::ThumbFinger4_R));

			bone.emplace_back(std::make_pair(killer::toad::Wrist_R, killer::toad::IndexFinger1_R));
			bone.emplace_back(std::make_pair(killer::toad::IndexFinger1_R, killer::toad::IndexFinger2_R));
			bone.emplace_back(std::make_pair(killer::toad::IndexFinger2_R, killer::toad::IndexFinger3_R));
			bone.emplace_back(std::make_pair(killer::toad::IndexFinger3_R, killer::toad::IndexFinger4_R));

			bone.emplace_back(std::make_pair(killer::toad::Wrist_R, killer::toad::MiddleFinger1_R));
			bone.emplace_back(std::make_pair(killer::toad::MiddleFinger1_R, killer::toad::MiddleFinger2_R));
			bone.emplace_back(std::make_pair(killer::toad::MiddleFinger2_R, killer::toad::MiddleFinger3_R));
			bone.emplace_back(std::make_pair(killer::toad::MiddleFinger3_R, killer::toad::MiddleFinger4_R));

			bone.emplace_back(std::make_pair(killer::toad::Wrist_R, killer::toad::RingFinger1_R));
			bone.emplace_back(std::make_pair(killer::toad::RingFinger1_R, killer::toad::RingFinger2_R));
			bone.emplace_back(std::make_pair(killer::toad::RingFinger2_R, killer::toad::RingFinger3_R));
			bone.emplace_back(std::make_pair(killer::toad::RingFinger3_R, killer::toad::RingFinger4_R));

			bone.emplace_back(std::make_pair(killer::toad::pelvis, killer::toad::Hip_R));
			bone.emplace_back(std::make_pair(killer::toad::Hip_R, killer::toad::Hip1_R));
			bone.emplace_back(std::make_pair(killer::toad::Hip1_R, killer::toad::Hip2_R));
			bone.emplace_back(std::make_pair(killer::toad::Hip2_R, killer::toad::Ankle_R));
			bone.emplace_back(std::make_pair(killer::toad::Ankle_R, killer::toad::Toes_R));

			bone.emplace_back(std::make_pair(killer::toad::Toes_R, killer::toad::bigToe1_R));
			bone.emplace_back(std::make_pair(killer::toad::bigToe1_R, killer::toad::bigToe2_R));
			bone.emplace_back(std::make_pair(killer::toad::bigToe2_R, killer::toad::bigToe3_R));

			bone.emplace_back(std::make_pair(killer::toad::Toes_R, killer::toad::MiddleToe1_R));
			bone.emplace_back(std::make_pair(killer::toad::MiddleToe1_R, killer::toad::MiddleToe2_R));
			bone.emplace_back(std::make_pair(killer::toad::MiddleToe2_R, killer::toad::MiddleToe3_R));

			bone.emplace_back(std::make_pair(killer::toad::Toes_R, killer::toad::PinkyToe1_R));
			bone.emplace_back(std::make_pair(killer::toad::PinkyToe1_R, killer::toad::PinkyToe2_R));
			bone.emplace_back(std::make_pair(killer::toad::PinkyToe2_R, killer::toad::PinkyToe3_R));
		}
	}

	{
		// dollmaster bones
		auto& bone = bone_array[2];

		bone.emplace_back(std::make_pair(killer::dollmaster::Head_M, killer::dollmaster::Neck_M));
		bone.emplace_back(std::make_pair(killer::dollmaster::Neck_M, killer::dollmaster::Chest_M));
		bone.emplace_back(std::make_pair(killer::dollmaster::Chest_M, killer::dollmaster::pelvis));

		// left
		{
			bone.emplace_back(std::make_pair(killer::dollmaster::Neck_M, killer::dollmaster::Shoulder_L));
			bone.emplace_back(std::make_pair(killer::dollmaster::Shoulder_L, killer::dollmaster::Elbow_L));
			bone.emplace_back(std::make_pair(killer::dollmaster::Elbow_L, killer::dollmaster::Wrist_L));

			bone.emplace_back(std::make_pair(killer::dollmaster::Wrist_L, killer::dollmaster::ThumbFinger1_L));
			bone.emplace_back(std::make_pair(killer::dollmaster::ThumbFinger1_L, killer::dollmaster::ThumbFinger2_L));
			bone.emplace_back(std::make_pair(killer::dollmaster::ThumbFinger2_L, killer::dollmaster::ThumbFinger3_L));
			bone.emplace_back(std::make_pair(killer::dollmaster::ThumbFinger3_L, killer::dollmaster::ThumbFinger4_L));

			bone.emplace_back(std::make_pair(killer::dollmaster::Wrist_L, killer::dollmaster::IndexFinger1_L));
			bone.emplace_back(std::make_pair(killer::dollmaster::IndexFinger1_L, killer::dollmaster::IndexFinger2_L));
			bone.emplace_back(std::make_pair(killer::dollmaster::IndexFinger2_L, killer::dollmaster::IndexFinger3_L));
			bone.emplace_back(std::make_pair(killer::dollmaster::IndexFinger3_L, killer::dollmaster::IndexFinger4_L));

			bone.emplace_back(std::make_pair(killer::dollmaster::Wrist_L, killer::dollmaster::MiddleFinger1_L));
			bone.emplace_back(std::make_pair(killer::dollmaster::MiddleFinger1_L, killer::dollmaster::MiddleFinger2_L));
			bone.emplace_back(std::make_pair(killer::dollmaster::MiddleFinger3_L, killer::dollmaster::MiddleFinger3_L));
			bone.emplace_back(std::make_pair(killer::dollmaster::MiddleFinger3_L, killer::dollmaster::MiddleFinger4_L));

			bone.emplace_back(std::make_pair(killer::dollmaster::Wrist_L, killer::dollmaster::RingFinger1_L));
			bone.emplace_back(std::make_pair(killer::dollmaster::RingFinger1_L, killer::dollmaster::RingFinger2_L));
			bone.emplace_back(std::make_pair(killer::dollmaster::RingFinger2_L, killer::dollmaster::RingFinger3_L));
			bone.emplace_back(std::make_pair(killer::dollmaster::RingFinger3_L, killer::dollmaster::RingFinger4_L));

			bone.emplace_back(std::make_pair(killer::dollmaster::Wrist_L, killer::dollmaster::PinkyFinger1_L));
			bone.emplace_back(std::make_pair(killer::dollmaster::PinkyFinger1_L, killer::dollmaster::PinkyFinger2_L));
			bone.emplace_back(std::make_pair(killer::dollmaster::PinkyFinger2_L, killer::dollmaster::PinkyFinger3_L));
			bone.emplace_back(std::make_pair(killer::dollmaster::PinkyFinger3_L, killer::dollmaster::PinkyFinger4_L));

			bone.emplace_back(std::make_pair(killer::dollmaster::pelvis, killer::dollmaster::Hip_L));
			bone.emplace_back(std::make_pair(killer::dollmaster::Hip_L, killer::dollmaster::HipPart1_L));
			bone.emplace_back(std::make_pair(killer::dollmaster::HipPart1_L, killer::dollmaster::Knee_L));
			bone.emplace_back(std::make_pair(killer::dollmaster::Knee_L, killer::dollmaster::KneePart1_L));
			bone.emplace_back(std::make_pair(killer::dollmaster::KneePart1_L, killer::dollmaster::Ankle_L));
			bone.emplace_back(std::make_pair(killer::dollmaster::Ankle_L, killer::dollmaster::Toes_L));
		}

		// right
		{
			bone.emplace_back(std::make_pair(killer::dollmaster::Neck_M, killer::dollmaster::Shoulder_R));
			bone.emplace_back(std::make_pair(killer::dollmaster::Shoulder_R, killer::dollmaster::Elbow_R));
			bone.emplace_back(std::make_pair(killer::dollmaster::Elbow_R, killer::dollmaster::Wrist_R));

			bone.emplace_back(std::make_pair(killer::dollmaster::Wrist_R, killer::dollmaster::ThumbFinger1_R));
			bone.emplace_back(std::make_pair(killer::dollmaster::ThumbFinger1_R, killer::dollmaster::ThumbFinger2_R));
			bone.emplace_back(std::make_pair(killer::dollmaster::ThumbFinger2_R, killer::dollmaster::ThumbFinger3_R));
			bone.emplace_back(std::make_pair(killer::dollmaster::ThumbFinger3_R, killer::dollmaster::ThumbFinger4_R));

			bone.emplace_back(std::make_pair(killer::dollmaster::Wrist_R, killer::dollmaster::IndexFinger1_R));
			bone.emplace_back(std::make_pair(killer::dollmaster::IndexFinger1_R, killer::dollmaster::IndexFinger2_R));
			bone.emplace_back(std::make_pair(killer::dollmaster::IndexFinger2_R, killer::dollmaster::IndexFinger3_R));
			bone.emplace_back(std::make_pair(killer::dollmaster::IndexFinger3_R, killer::dollmaster::IndexFinger4_R));

			bone.emplace_back(std::make_pair(killer::dollmaster::Wrist_R, killer::dollmaster::MiddleFinger1_R));
			bone.emplace_back(std::make_pair(killer::dollmaster::MiddleFinger1_R, killer::dollmaster::MiddleFinger2_R));
			bone.emplace_back(std::make_pair(killer::dollmaster::MiddleFinger2_R, killer::dollmaster::MiddleFinger3_R));
			bone.emplace_back(std::make_pair(killer::dollmaster::MiddleFinger3_R, killer::dollmaster::MiddleFinger4_R));

			bone.emplace_back(std::make_pair(killer::dollmaster::Wrist_R, killer::dollmaster::RingFinger1_R));
			bone.emplace_back(std::make_pair(killer::dollmaster::RingFinger1_R, killer::dollmaster::RingFinger2_R));
			bone.emplace_back(std::make_pair(killer::dollmaster::RingFinger2_R, killer::dollmaster::RingFinger3_R));
			bone.emplace_back(std::make_pair(killer::dollmaster::RingFinger3_R, killer::dollmaster::RingFinger4_R));

			bone.emplace_back(std::make_pair(killer::dollmaster::Wrist_R, killer::dollmaster::PinkyFinger1_R));
			bone.emplace_back(std::make_pair(killer::dollmaster::PinkyFinger1_R, killer::dollmaster::PinkyFinger2_R));
			bone.emplace_back(std::make_pair(killer::dollmaster::PinkyFinger2_R, killer::dollmaster::PinkyFinger3_R));
			bone.emplace_back(std::make_pair(killer::dollmaster::PinkyFinger3_R, killer::dollmaster::PinkyFinger4_R));

			bone.emplace_back(std::make_pair(killer::dollmaster::pelvis, killer::dollmaster::Hip_R));
			bone.emplace_back(std::make_pair(killer::dollmaster::Hip_R, killer::dollmaster::HipPart1_R));
			bone.emplace_back(std::make_pair(killer::dollmaster::HipPart1_R, killer::dollmaster::Knee_R));
			bone.emplace_back(std::make_pair(killer::dollmaster::Knee_R, killer::dollmaster::KneePart1_R));
			bone.emplace_back(std::make_pair(killer::dollmaster::KneePart1_R, killer::dollmaster::Ankle_R));
			bone.emplace_back(std::make_pair(killer::dollmaster::Ankle_R, killer::dollmaster::Toes_R));
		}
	}

	{
		// survivor bones
		auto& bone = bone_array[3];

		bone.emplace_back(std::make_pair(survivor::head, survivor::neck_01));
		bone.emplace_back(std::make_pair(survivor::neck_01, survivor::spine_01));
		bone.emplace_back(std::make_pair(survivor::spine_01, survivor::pelvis));

		// left
		{
			bone.emplace_back(std::make_pair(survivor::neck_01, survivor::upperarm_l));
			bone.emplace_back(std::make_pair(survivor::upperarm_l, survivor::upperarm_twist_01_l));
			bone.emplace_back(std::make_pair(survivor::upperarm_twist_01_l, survivor::lowerarm_l));
			bone.emplace_back(std::make_pair(survivor::lowerarm_l, survivor::lowerarm_twist_01_l));
			bone.emplace_back(std::make_pair(survivor::lowerarm_twist_01_l, survivor::hand_l));

			bone.emplace_back(std::make_pair(survivor::hand_l, survivor::thumb_01_l));
			bone.emplace_back(std::make_pair(survivor::thumb_01_l, survivor::thumb_02_l));
			bone.emplace_back(std::make_pair(survivor::thumb_02_l, survivor::thumb_03_l));
			bone.emplace_back(std::make_pair(survivor::thumb_03_l, survivor::thumb_03_END_l));

			bone.emplace_back(std::make_pair(survivor::hand_l, survivor::index_01_l));
			bone.emplace_back(std::make_pair(survivor::index_01_l, survivor::index_02_l));
			bone.emplace_back(std::make_pair(survivor::index_02_l, survivor::index_03_l));
			bone.emplace_back(std::make_pair(survivor::index_03_l, survivor::index_03_END_l));

			bone.emplace_back(std::make_pair(survivor::hand_l, survivor::middle_01_l));
			bone.emplace_back(std::make_pair(survivor::middle_01_l, survivor::middle_02_l));
			bone.emplace_back(std::make_pair(survivor::middle_02_l, survivor::middle_03_l));
			bone.emplace_back(std::make_pair(survivor::middle_03_l, survivor::middle_03_END_l));

			bone.emplace_back(std::make_pair(survivor::hand_l, survivor::ring_01_l));
			bone.emplace_back(std::make_pair(survivor::ring_01_l, survivor::ring_02_l));
			bone.emplace_back(std::make_pair(survivor::ring_02_l, survivor::ring_03_l));
			bone.emplace_back(std::make_pair(survivor::ring_03_l, survivor::ring_03_END_l));

			bone.emplace_back(std::make_pair(survivor::hand_l, survivor::pinky_01_l));
			bone.emplace_back(std::make_pair(survivor::pinky_01_l, survivor::pinky_02_l));
			bone.emplace_back(std::make_pair(survivor::pinky_02_l, survivor::pinky_03_l));
			bone.emplace_back(std::make_pair(survivor::pinky_03_l, survivor::pinky_03_END_l));

			bone.emplace_back(std::make_pair(survivor::pelvis, survivor::thigh_l));
			bone.emplace_back(std::make_pair(survivor::thigh_l, survivor::thigh_twist_01_l));
			bone.emplace_back(std::make_pair(survivor::thigh_twist_01_l, survivor::calf_l));
			bone.emplace_back(std::make_pair(survivor::calf_l, survivor::calf_twist_01_l));
			bone.emplace_back(std::make_pair(survivor::calf_twist_01_l, survivor::foot_l));
		}

		// right
		{
			bone.emplace_back(std::make_pair(survivor::neck_01, survivor::upperarm_r));
			bone.emplace_back(std::make_pair(survivor::upperarm_r, survivor::upperarm_twist_01_r));
			bone.emplace_back(std::make_pair(survivor::upperarm_twist_01_r, survivor::lowerarm_r));
			bone.emplace_back(std::make_pair(survivor::lowerarm_r, survivor::lowerarm_twist_01_r));
			bone.emplace_back(std::make_pair(survivor::lowerarm_twist_01_r, survivor::hand_r));

			bone.emplace_back(std::make_pair(survivor::hand_r, survivor::thumb_01_r));
			bone.emplace_back(std::make_pair(survivor::thumb_01_r, survivor::thumb_02_r));
			bone.emplace_back(std::make_pair(survivor::thumb_02_r, survivor::thumb_03_r));
			bone.emplace_back(std::make_pair(survivor::thumb_03_r, survivor::thumb_03_END_r));

			bone.emplace_back(std::make_pair(survivor::hand_r, survivor::index_01_r));
			bone.emplace_back(std::make_pair(survivor::index_01_r, survivor::index_02_r));
			bone.emplace_back(std::make_pair(survivor::index_02_r, survivor::index_03_r));
			bone.emplace_back(std::make_pair(survivor::index_03_r, survivor::index_03_END_r));

			bone.emplace_back(std::make_pair(survivor::hand_r, survivor::middle_01_r));
			bone.emplace_back(std::make_pair(survivor::middle_01_r, survivor::middle_02_r));
			bone.emplace_back(std::make_pair(survivor::middle_02_r, survivor::middle_03_r));
			bone.emplace_back(std::make_pair(survivor::middle_03_r, survivor::middle_03_END_r));

			bone.emplace_back(std::make_pair(survivor::hand_r, survivor::ring_01_r));
			bone.emplace_back(std::make_pair(survivor::ring_01_r, survivor::ring_02_r));
			bone.emplace_back(std::make_pair(survivor::ring_02_r, survivor::ring_03_r));
			bone.emplace_back(std::make_pair(survivor::ring_03_r, survivor::ring_03_END_r));

			bone.emplace_back(std::make_pair(survivor::hand_r, survivor::pinky_01_r));
			bone.emplace_back(std::make_pair(survivor::pinky_01_r, survivor::pinky_02_r));
			bone.emplace_back(std::make_pair(survivor::pinky_02_r, survivor::pinky_03_r));
			bone.emplace_back(std::make_pair(survivor::pinky_03_r, survivor::pinky_03_END_r));

			bone.emplace_back(std::make_pair(survivor::pelvis, survivor::thigh_r));
			bone.emplace_back(std::make_pair(survivor::thigh_r, survivor::thigh_twist_01_r));
			bone.emplace_back(std::make_pair(survivor::thigh_twist_01_r, survivor::calf_r));
			bone.emplace_back(std::make_pair(survivor::calf_r, survivor::calf_twist_01_r));
			bone.emplace_back(std::make_pair(survivor::calf_twist_01_r, survivor::foot_r));
		}
	}
}

std::vector < std::pair < int, int > >& bones::get_bone_array(const sdk::a_actor* actor) {
	if (actor->is_a(sdk::werewolf_bp)) {
		return bone_array[0];
	}

	if (actor->is_a(sdk::toad_bp)) {
		return bone_array[1];
	}

	if (actor->is_a(sdk::doll_master_bp)) {
		return bone_array[2];
	}

	if (actor->is_a(sdk::cheerleader_bp) || actor->is_a(sdk::jock_bp) || actor->is_a(sdk::outsider_bp) ||
		actor->is_a(sdk::punk_bp) || actor->is_a(sdk::virgin_bp)) {

		return bone_array[3];
	}
}