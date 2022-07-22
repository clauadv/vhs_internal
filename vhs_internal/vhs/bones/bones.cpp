#include <includes.h>

int vhs::bones::get(std::string bone, ue4::components::u_skeletal_mesh_component* mesh, ue4::game_framework::a_pawn* pawn) {
	const auto hashed_pawn = hash::get(pawn->get_name().c_str());
	const auto hashed_bone = hash::get(bone.c_str());
	const auto cached_bones = bones.find(hashed_pawn);

	if (cached_bones != bones.end()) {
		const auto cached_bone = (*cached_bones).second.find(hashed_bone);

		if (cached_bone != (*cached_bones).second.end()) {
			return (*cached_bone).second;
		}
	}

	for (auto i = 0; i < mesh->get_bones_num(); i++) {
		auto bone_name = mesh->get_bone_name(i).get_name();
		std::ranges::transform(bone_name.begin(), bone_name.end(), bone_name.begin(), ::tolower);

		if (bone_name.find(bone) != std::string::npos) {
			bones[hashed_pawn][hashed_bone] = i;

			return i;
		}
	}

	return 0;
}

std::vector<std::pair<int, int>> vhs::bones::get_array(ue4::components::u_skeletal_mesh_component* mesh, ue4::game_framework::a_pawn* pawn) {
	std::vector<std::pair<int, int>> bone;

	auto head = 0;
	if (pawn->is_monster()) {
		head = vhs::bones::get(_("head_m"), mesh, pawn);

	} else if (pawn->is_teen()) {
		head = vhs::bones::get(_("head"), mesh, pawn);
	}

	auto neck = 0;
	if (pawn->is_monster()) {
		neck = vhs::bones::get(_("neck_m"), mesh, pawn);

	} else if (pawn->is_teen()) {
		neck = vhs::bones::get(_("neck_01"), mesh, pawn);
	}

	auto pelvis = vhs::bones::get(_("pelvis"), mesh, pawn);

	bone.emplace_back(std::make_pair(head, neck));
	bone.emplace_back(std::make_pair(neck, pelvis));

	
	// right upper body
	{
		auto shoulder_r = 0;
		if (pawn->is_monster()) {
			shoulder_r = vhs::bones::get(_("shoulder_r"), mesh, pawn);

		} else if (pawn->is_teen()) {
			shoulder_r = vhs::bones::get(_("upperarm_r"), mesh, pawn);
		}

		auto elbow_r = 0;
		if (pawn->is_monster()) {
			elbow_r = vhs::bones::get(_("elbow_r"), mesh, pawn);

		} else if (pawn->is_teen()) {
			elbow_r = vhs::bones::get(_("lowerarm_r"), mesh, pawn);
		}

		auto hand_r = 0;
		if (pawn->is_monster()) {
			hand_r = vhs::bones::get(_("wrist_r"), mesh, pawn);

		} else if (pawn->is_teen()) {
			hand_r = vhs::bones::get(_("hand_r"), mesh, pawn);
		}

		bone.emplace_back(std::make_pair(neck, shoulder_r));
		bone.emplace_back(std::make_pair(shoulder_r, elbow_r));
		bone.emplace_back(std::make_pair(elbow_r, hand_r));
	}

	// right lower body
	{
		auto hip_r = 0;
		if (pawn->is_monster()) {
			hip_r = vhs::bones::get(_("hip_r"), mesh, pawn);

		} else if (pawn->is_teen()) {
			hip_r = vhs::bones::get(_("thigh_r"), mesh, pawn);
		}

		auto knee_r = 0;
		if (pawn->is_a(ue4::sdk::wart)) {
			knee_r = vhs::bones::get(_("hip2_r"), mesh, pawn);

		} else if (pawn->is_monster()) {
			knee_r = vhs::bones::get(_("knee_r"), mesh, pawn);

		} else if (pawn->is_teen()) {
			knee_r = vhs::bones::get(_("calf_r"), mesh, pawn);
		}

		auto ankle_r = 0;
		if (pawn->is_monster()) {
			ankle_r = vhs::bones::get(_("ankle_r"), mesh, pawn);

		} else if (pawn->is_teen()) {
			ankle_r = vhs::bones::get(_("calf_twist_01_r"), mesh, pawn);
		}

		auto foot_r = 0;
		if (pawn->is_monster()) {
			foot_r = vhs::bones::get(_("toes_r"), mesh, pawn);

		} else if (pawn->is_teen()) {
			foot_r = vhs::bones::get(_("foot_r"), mesh, pawn);
		}

		bone.emplace_back(std::make_pair(pelvis, hip_r));
		bone.emplace_back(std::make_pair(hip_r, knee_r));
		bone.emplace_back(std::make_pair(knee_r, ankle_r));
		bone.emplace_back(std::make_pair(ankle_r, foot_r));
	}

	
	// left upper body
	{
		auto shoulder_l = 0;
		if (pawn->is_monster()) {
			shoulder_l = vhs::bones::get(_("shoulder_l"), mesh, pawn);

		} else if (pawn->is_teen()) {
			shoulder_l = vhs::bones::get(_("upperarm_l"), mesh, pawn);
		}

		auto elbow_l = 0;
		if (pawn->is_monster()) {
			elbow_l = vhs::bones::get(_("elbow_l"), mesh, pawn);

		} else if (pawn->is_teen()) {
			elbow_l = vhs::bones::get(_("lowerarm_l"), mesh, pawn);
		}

		auto hand_l = 0;
		if (pawn->is_monster()) {
			hand_l = vhs::bones::get(_("wrist_l"), mesh, pawn);

		} else if (pawn->is_teen()) {
			hand_l = vhs::bones::get(_("hand_l"), mesh, pawn);
		}

		bone.emplace_back(std::make_pair(neck, shoulder_l));
		bone.emplace_back(std::make_pair(shoulder_l, elbow_l));
		bone.emplace_back(std::make_pair(elbow_l, hand_l));
	}

	// left lower body
	{
		auto hip_l = 0;
		if (pawn->is_monster()) {
			hip_l = vhs::bones::get(_("hip_l"), mesh, pawn);

		} else if (pawn->is_teen()) {
			hip_l = vhs::bones::get(_("thigh_l"), mesh, pawn);
		}

		auto knee_l = 0;
		if (pawn->is_a(ue4::sdk::wart)) {
			knee_l = vhs::bones::get(_("hip2_l"), mesh, pawn);

		} else if (pawn->is_monster()) {
			knee_l = vhs::bones::get(_("knee_l"), mesh, pawn);

		} else if (pawn->is_teen()) {
			knee_l = vhs::bones::get(_("calf_l"), mesh, pawn);
		}

		auto ankle_l = 0;
		if (pawn->is_monster()) {
			ankle_l = vhs::bones::get(_("ankle_l"), mesh, pawn);

		} else if (pawn->is_teen()) {
			ankle_l = vhs::bones::get(_("calf_twist_01_l"), mesh, pawn);
		}

		auto foot_l = 0;
		if (pawn->is_monster()) {
			foot_l = vhs::bones::get(_("toes_l"), mesh, pawn);

		} else if (pawn->is_teen()) {
			foot_l = vhs::bones::get(_("foot_l"), mesh, pawn);
		}

		bone.emplace_back(std::make_pair(pelvis, hip_l));
		bone.emplace_back(std::make_pair(hip_l, knee_l));
		bone.emplace_back(std::make_pair(knee_l, ankle_l));
		bone.emplace_back(std::make_pair(ankle_l, foot_l));
	}

	return bone;
}