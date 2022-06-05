#include <includes.h>

std::array<std::vector<std::pair<int, int>>, 5> _bones;

void vhs::bones::initialize() {
	// werewolf
	{
		auto& bone = _bones[0];

		bone.emplace_back(std::make_pair(vhs::bones::werewolf::head_m, vhs::bones::werewolf::neck_m));
		bone.emplace_back(std::make_pair(vhs::bones::werewolf::neck_m, vhs::bones::werewolf::chest_m));
		bone.emplace_back(std::make_pair(vhs::bones::werewolf::chest_m, vhs::bones::werewolf::pelvis));

		// left
		{
			bone.emplace_back(std::make_pair(vhs::bones::werewolf::neck_m, vhs::bones::werewolf::shoulder_l));
			bone.emplace_back(std::make_pair(vhs::bones::werewolf::shoulder_l, vhs::bones::werewolf::elbow_l));
			bone.emplace_back(std::make_pair(vhs::bones::werewolf::elbow_l, vhs::bones::werewolf::wrist_l));

			bone.emplace_back(std::make_pair(vhs::bones::werewolf::wrist_l, vhs::bones::werewolf::thumbfinger1_l));
			bone.emplace_back(std::make_pair(vhs::bones::werewolf::thumbfinger1_l, vhs::bones::werewolf::thumbfinger2_l));
			bone.emplace_back(std::make_pair(vhs::bones::werewolf::thumbfinger2_l, vhs::bones::werewolf::thumbfinger3_l));
			bone.emplace_back(std::make_pair(vhs::bones::werewolf::thumbfinger3_l, vhs::bones::werewolf::thumbfinger4_l));

			bone.emplace_back(std::make_pair(vhs::bones::werewolf::wrist_l, vhs::bones::werewolf::indexfinger1_l));
			bone.emplace_back(std::make_pair(vhs::bones::werewolf::indexfinger1_l, vhs::bones::werewolf::indexfinger2_l));
			bone.emplace_back(std::make_pair(vhs::bones::werewolf::indexfinger2_l, vhs::bones::werewolf::indexfinger3_l));
			bone.emplace_back(std::make_pair(vhs::bones::werewolf::indexfinger3_l, vhs::bones::werewolf::indexfinger4_l));

			bone.emplace_back(std::make_pair(vhs::bones::werewolf::wrist_l, vhs::bones::werewolf::middlefinger1_l));
			bone.emplace_back(std::make_pair(vhs::bones::werewolf::middlefinger1_l, vhs::bones::werewolf::middlefinger2_l));
			bone.emplace_back(std::make_pair(vhs::bones::werewolf::middlefinger2_l, vhs::bones::werewolf::middlefinger3_l));
			bone.emplace_back(std::make_pair(vhs::bones::werewolf::middlefinger3_l, vhs::bones::werewolf::middlefinger4_l));

			bone.emplace_back(std::make_pair(vhs::bones::werewolf::wrist_l, vhs::bones::werewolf::ringfinger1_l));
			bone.emplace_back(std::make_pair(vhs::bones::werewolf::ringfinger1_l, vhs::bones::werewolf::ringfinger2_l));
			bone.emplace_back(std::make_pair(vhs::bones::werewolf::ringfinger2_l, vhs::bones::werewolf::ringfinger3_l));
			bone.emplace_back(std::make_pair(vhs::bones::werewolf::ringfinger3_l, vhs::bones::werewolf::ringfinger4_l));

			bone.emplace_back(std::make_pair(vhs::bones::werewolf::wrist_l, vhs::bones::werewolf::pinkyfinger1_l));
			bone.emplace_back(std::make_pair(vhs::bones::werewolf::pinkyfinger1_l, vhs::bones::werewolf::pinkyfinger2_l));
			bone.emplace_back(std::make_pair(vhs::bones::werewolf::pinkyfinger2_l, vhs::bones::werewolf::pinkyfinger3_l));
			bone.emplace_back(std::make_pair(vhs::bones::werewolf::pinkyfinger3_l, vhs::bones::werewolf::pinkyfinger4_l));

			bone.emplace_back(std::make_pair(vhs::bones::werewolf::pelvis, vhs::bones::werewolf::hip_l));
			bone.emplace_back(std::make_pair(vhs::bones::werewolf::hip_l, vhs::bones::werewolf::knee_l));
			bone.emplace_back(std::make_pair(vhs::bones::werewolf::knee_l, vhs::bones::werewolf::kneepart1_l));
			bone.emplace_back(std::make_pair(vhs::bones::werewolf::kneepart1_l, vhs::bones::werewolf::ankle_l));
			bone.emplace_back(std::make_pair(vhs::bones::werewolf::ankle_l, vhs::bones::werewolf::toes_l));
		}

		// right
		{
			bone.emplace_back(std::make_pair(vhs::bones::werewolf::neck_m, vhs::bones::werewolf::shoulder_r));
			bone.emplace_back(std::make_pair(vhs::bones::werewolf::shoulder_r, vhs::bones::werewolf::elbow_r));
			bone.emplace_back(std::make_pair(vhs::bones::werewolf::elbow_r, vhs::bones::werewolf::wrist_r));

			bone.emplace_back(std::make_pair(vhs::bones::werewolf::wrist_r, vhs::bones::werewolf::thumbfinger1_r));
			bone.emplace_back(std::make_pair(vhs::bones::werewolf::thumbfinger1_r, vhs::bones::werewolf::thumbfinger2_r));
			bone.emplace_back(std::make_pair(vhs::bones::werewolf::thumbfinger2_r, vhs::bones::werewolf::thumbfinger3_r));
			bone.emplace_back(std::make_pair(vhs::bones::werewolf::thumbfinger3_r, vhs::bones::werewolf::thumbfinger4_r));

			bone.emplace_back(std::make_pair(vhs::bones::werewolf::wrist_r, vhs::bones::werewolf::indexfinger1_r));
			bone.emplace_back(std::make_pair(vhs::bones::werewolf::indexfinger1_r, vhs::bones::werewolf::indexfinger2_r));
			bone.emplace_back(std::make_pair(vhs::bones::werewolf::indexfinger2_r, vhs::bones::werewolf::indexfinger3_r));
			bone.emplace_back(std::make_pair(vhs::bones::werewolf::indexfinger3_r, vhs::bones::werewolf::indexfinger4_r));

			bone.emplace_back(std::make_pair(vhs::bones::werewolf::wrist_r, vhs::bones::werewolf::middlefinger1_r));
			bone.emplace_back(std::make_pair(vhs::bones::werewolf::middlefinger1_r, vhs::bones::werewolf::middlefinger2_r));
			bone.emplace_back(std::make_pair(vhs::bones::werewolf::middlefinger2_r, vhs::bones::werewolf::middlefinger3_r));
			bone.emplace_back(std::make_pair(vhs::bones::werewolf::middlefinger3_r, vhs::bones::werewolf::middlefinger4_r));

			bone.emplace_back(std::make_pair(vhs::bones::werewolf::wrist_r, vhs::bones::werewolf::ringfinger1_r));
			bone.emplace_back(std::make_pair(vhs::bones::werewolf::ringfinger1_r, vhs::bones::werewolf::ringfinger2_r));
			bone.emplace_back(std::make_pair(vhs::bones::werewolf::ringfinger2_r, vhs::bones::werewolf::ringfinger3_r));
			bone.emplace_back(std::make_pair(vhs::bones::werewolf::ringfinger3_r, vhs::bones::werewolf::ringfinger4_r));

			bone.emplace_back(std::make_pair(vhs::bones::werewolf::wrist_r, vhs::bones::werewolf::pinkyfinger1_r));
			bone.emplace_back(std::make_pair(vhs::bones::werewolf::pinkyfinger1_r, vhs::bones::werewolf::pinkyfinger2_r));
			bone.emplace_back(std::make_pair(vhs::bones::werewolf::pinkyfinger2_r, vhs::bones::werewolf::pinkyfinger3_r));
			bone.emplace_back(std::make_pair(vhs::bones::werewolf::pinkyfinger3_r, vhs::bones::werewolf::pinkyfinger4_r));

			bone.emplace_back(std::make_pair(vhs::bones::werewolf::pelvis, vhs::bones::werewolf::hip_r));
			bone.emplace_back(std::make_pair(vhs::bones::werewolf::hip_r, vhs::bones::werewolf::knee_r));
			bone.emplace_back(std::make_pair(vhs::bones::werewolf::knee_r, vhs::bones::werewolf::kneepart1_r));
			bone.emplace_back(std::make_pair(vhs::bones::werewolf::kneepart1_r, vhs::bones::werewolf::ankle_r));
			bone.emplace_back(std::make_pair(vhs::bones::werewolf::ankle_r, vhs::bones::werewolf::toes_r));
		}
	}

	// toad
	{
		auto& bone = _bones[1];

		bone.emplace_back(std::make_pair(vhs::bones::toad::head_m, vhs::bones::toad::neck_m));
		bone.emplace_back(std::make_pair(vhs::bones::toad::neck_m, vhs::bones::toad::chest_m));
		bone.emplace_back(std::make_pair(vhs::bones::toad::chest_m, vhs::bones::toad::pelvis));

		// left
		{
			bone.emplace_back(std::make_pair(vhs::bones::toad::neck_m, vhs::bones::toad::shoulder_l));
			bone.emplace_back(std::make_pair(vhs::bones::toad::shoulder_l, vhs::bones::toad::elbow_l));
			bone.emplace_back(std::make_pair(vhs::bones::toad::elbow_l, vhs::bones::toad::wrist_l));

			bone.emplace_back(std::make_pair(vhs::bones::toad::wrist_l, vhs::bones::toad::thumbfinger1_l));
			bone.emplace_back(std::make_pair(vhs::bones::toad::thumbfinger1_l, vhs::bones::toad::thumbfinger2_l));
			bone.emplace_back(std::make_pair(vhs::bones::toad::thumbfinger2_l, vhs::bones::toad::thumbfinger3_l));
			bone.emplace_back(std::make_pair(vhs::bones::toad::thumbfinger3_l, vhs::bones::toad::thumbfinger4_l));

			bone.emplace_back(std::make_pair(vhs::bones::toad::wrist_l, vhs::bones::toad::indexfinger1_l));
			bone.emplace_back(std::make_pair(vhs::bones::toad::indexfinger1_l, vhs::bones::toad::indexfinger2_l));
			bone.emplace_back(std::make_pair(vhs::bones::toad::indexfinger2_l, vhs::bones::toad::indexfinger3_l));
			bone.emplace_back(std::make_pair(vhs::bones::toad::indexfinger3_l, vhs::bones::toad::indexfinger4_l));

			bone.emplace_back(std::make_pair(vhs::bones::toad::wrist_l, vhs::bones::toad::middlefinger1_l));
			bone.emplace_back(std::make_pair(vhs::bones::toad::middlefinger1_l, vhs::bones::toad::middlefinger2_l));
			bone.emplace_back(std::make_pair(vhs::bones::toad::middlefinger2_l, vhs::bones::toad::middlefinger3_l));
			bone.emplace_back(std::make_pair(vhs::bones::toad::middlefinger3_l, vhs::bones::toad::middlefinger4_l));

			bone.emplace_back(std::make_pair(vhs::bones::toad::wrist_l, vhs::bones::toad::ringfinger1_l));
			bone.emplace_back(std::make_pair(vhs::bones::toad::ringfinger1_l, vhs::bones::toad::ringfinger2_l));
			bone.emplace_back(std::make_pair(vhs::bones::toad::ringfinger2_l, vhs::bones::toad::ringfinger3_l));
			bone.emplace_back(std::make_pair(vhs::bones::toad::ringfinger3_l, vhs::bones::toad::ringfinger4_l));

			bone.emplace_back(std::make_pair(vhs::bones::toad::pelvis, vhs::bones::toad::hip_l));
			bone.emplace_back(std::make_pair(vhs::bones::toad::hip_l, vhs::bones::toad::hip1_l));
			bone.emplace_back(std::make_pair(vhs::bones::toad::hip1_l, vhs::bones::toad::hip2_l));
			bone.emplace_back(std::make_pair(vhs::bones::toad::hip2_l, vhs::bones::toad::ankle_l));
			bone.emplace_back(std::make_pair(vhs::bones::toad::ankle_l, vhs::bones::toad::toes_l));

			bone.emplace_back(std::make_pair(vhs::bones::toad::toes_l, vhs::bones::toad::bigtoe1_l));
			bone.emplace_back(std::make_pair(vhs::bones::toad::bigtoe1_l, vhs::bones::toad::bigtoe2_l));
			bone.emplace_back(std::make_pair(vhs::bones::toad::bigtoe2_l, vhs::bones::toad::bigtoe3_l));

			bone.emplace_back(std::make_pair(vhs::bones::toad::toes_l, vhs::bones::toad::middletoe1_l));
			bone.emplace_back(std::make_pair(vhs::bones::toad::middletoe1_l, vhs::bones::toad::middletoe2_l));
			bone.emplace_back(std::make_pair(vhs::bones::toad::middletoe2_l, vhs::bones::toad::middletoe3_l));

			bone.emplace_back(std::make_pair(vhs::bones::toad::toes_l, vhs::bones::toad::pinkytoe1_l));
			bone.emplace_back(std::make_pair(vhs::bones::toad::pinkytoe1_l, vhs::bones::toad::pinkytoe2_l));
			bone.emplace_back(std::make_pair(vhs::bones::toad::pinkytoe2_l, vhs::bones::toad::pinkytoe3_l));
		}

		// right
		{
			bone.emplace_back(std::make_pair(vhs::bones::toad::neck_m, vhs::bones::toad::shoulder_r));
			bone.emplace_back(std::make_pair(vhs::bones::toad::shoulder_r, vhs::bones::toad::elbow_r));
			bone.emplace_back(std::make_pair(vhs::bones::toad::elbow_r, vhs::bones::toad::wrist_r));

			bone.emplace_back(std::make_pair(vhs::bones::toad::wrist_r, vhs::bones::toad::thumbfinger1_r));
			bone.emplace_back(std::make_pair(vhs::bones::toad::thumbfinger1_r, vhs::bones::toad::thumbfinger2_r));
			bone.emplace_back(std::make_pair(vhs::bones::toad::thumbfinger2_r, vhs::bones::toad::thumbfinger3_r));
			bone.emplace_back(std::make_pair(vhs::bones::toad::thumbfinger3_r, vhs::bones::toad::thumbfinger4_r));

			bone.emplace_back(std::make_pair(vhs::bones::toad::wrist_r, vhs::bones::toad::indexfinger1_r));
			bone.emplace_back(std::make_pair(vhs::bones::toad::indexfinger1_r, vhs::bones::toad::indexfinger2_r));
			bone.emplace_back(std::make_pair(vhs::bones::toad::indexfinger2_r, vhs::bones::toad::indexfinger3_r));
			bone.emplace_back(std::make_pair(vhs::bones::toad::indexfinger3_r, vhs::bones::toad::indexfinger4_r));

			bone.emplace_back(std::make_pair(vhs::bones::toad::wrist_r, vhs::bones::toad::middlefinger1_r));
			bone.emplace_back(std::make_pair(vhs::bones::toad::middlefinger1_r, vhs::bones::toad::middlefinger2_r));
			bone.emplace_back(std::make_pair(vhs::bones::toad::middlefinger2_r, vhs::bones::toad::middlefinger3_r));
			bone.emplace_back(std::make_pair(vhs::bones::toad::middlefinger3_r, vhs::bones::toad::middlefinger4_r));

			bone.emplace_back(std::make_pair(vhs::bones::toad::wrist_r, vhs::bones::toad::ringfinger1_r));
			bone.emplace_back(std::make_pair(vhs::bones::toad::ringfinger1_r, vhs::bones::toad::ringfinger2_r));
			bone.emplace_back(std::make_pair(vhs::bones::toad::ringfinger2_r, vhs::bones::toad::ringfinger3_r));
			bone.emplace_back(std::make_pair(vhs::bones::toad::ringfinger3_r, vhs::bones::toad::ringfinger4_r));

			bone.emplace_back(std::make_pair(vhs::bones::toad::pelvis, vhs::bones::toad::hip_r));
			bone.emplace_back(std::make_pair(vhs::bones::toad::hip_r, vhs::bones::toad::hip1_r));
			bone.emplace_back(std::make_pair(vhs::bones::toad::hip1_r, vhs::bones::toad::hip2_r));
			bone.emplace_back(std::make_pair(vhs::bones::toad::hip2_r, vhs::bones::toad::ankle_r));
			bone.emplace_back(std::make_pair(vhs::bones::toad::ankle_r, vhs::bones::toad::toes_r));

			bone.emplace_back(std::make_pair(vhs::bones::toad::toes_r, vhs::bones::toad::bigtoe1_r));
			bone.emplace_back(std::make_pair(vhs::bones::toad::bigtoe1_r, vhs::bones::toad::bigtoe2_r));
			bone.emplace_back(std::make_pair(vhs::bones::toad::bigtoe2_r, vhs::bones::toad::bigtoe3_r));

			bone.emplace_back(std::make_pair(vhs::bones::toad::toes_r, vhs::bones::toad::middletoe1_r));
			bone.emplace_back(std::make_pair(vhs::bones::toad::middletoe1_r, vhs::bones::toad::middletoe2_r));
			bone.emplace_back(std::make_pair(vhs::bones::toad::middletoe2_r, vhs::bones::toad::middletoe3_r));

			bone.emplace_back(std::make_pair(vhs::bones::toad::toes_r, vhs::bones::toad::pinkytoe1_r));
			bone.emplace_back(std::make_pair(vhs::bones::toad::pinkytoe1_r, vhs::bones::toad::pinkytoe2_r));
			bone.emplace_back(std::make_pair(vhs::bones::toad::pinkytoe2_r, vhs::bones::toad::pinkytoe3_r));
		}
	}

	// doll master
	{
		auto& bone = _bones[2];

		bone.emplace_back(std::make_pair(vhs::bones::doll_master::head_m, vhs::bones::doll_master::neck_m));
		bone.emplace_back(std::make_pair(vhs::bones::doll_master::neck_m, vhs::bones::doll_master::chest_m));
		bone.emplace_back(std::make_pair(vhs::bones::doll_master::chest_m, vhs::bones::doll_master::pelvis));

		// left
		{
			bone.emplace_back(std::make_pair(vhs::bones::doll_master::neck_m, vhs::bones::doll_master::shoulder_l));
			bone.emplace_back(std::make_pair(vhs::bones::doll_master::shoulder_l, vhs::bones::doll_master::elbow_l));
			bone.emplace_back(std::make_pair(vhs::bones::doll_master::elbow_l, vhs::bones::doll_master::wrist_l));

			bone.emplace_back(std::make_pair(vhs::bones::doll_master::wrist_l, vhs::bones::doll_master::thumbfinger1_l));
			bone.emplace_back(std::make_pair(vhs::bones::doll_master::thumbfinger1_l, vhs::bones::doll_master::thumbfinger2_l));
			bone.emplace_back(std::make_pair(vhs::bones::doll_master::thumbfinger2_l, vhs::bones::doll_master::thumbfinger3_l));
			bone.emplace_back(std::make_pair(vhs::bones::doll_master::thumbfinger3_l, vhs::bones::doll_master::thumbfinger4_l));

			bone.emplace_back(std::make_pair(vhs::bones::doll_master::wrist_l, vhs::bones::doll_master::indexfinger1_l));
			bone.emplace_back(std::make_pair(vhs::bones::doll_master::indexfinger1_l, vhs::bones::doll_master::indexfinger2_l));
			bone.emplace_back(std::make_pair(vhs::bones::doll_master::indexfinger2_l, vhs::bones::doll_master::indexfinger3_l));
			bone.emplace_back(std::make_pair(vhs::bones::doll_master::indexfinger3_l, vhs::bones::doll_master::indexfinger4_l));

			bone.emplace_back(std::make_pair(vhs::bones::doll_master::wrist_l, vhs::bones::doll_master::middlefinger1_l));
			bone.emplace_back(std::make_pair(vhs::bones::doll_master::middlefinger1_l, vhs::bones::doll_master::middlefinger2_l));
			bone.emplace_back(std::make_pair(vhs::bones::doll_master::middlefinger3_l, vhs::bones::doll_master::middlefinger3_l));
			bone.emplace_back(std::make_pair(vhs::bones::doll_master::middlefinger3_l, vhs::bones::doll_master::middlefinger4_l));

			bone.emplace_back(std::make_pair(vhs::bones::doll_master::wrist_l, vhs::bones::doll_master::ringfinger1_l));
			bone.emplace_back(std::make_pair(vhs::bones::doll_master::ringfinger1_l, vhs::bones::doll_master::ringfinger2_l));
			bone.emplace_back(std::make_pair(vhs::bones::doll_master::ringfinger2_l, vhs::bones::doll_master::ringfinger3_l));
			bone.emplace_back(std::make_pair(vhs::bones::doll_master::ringfinger3_l, vhs::bones::doll_master::ringfinger4_l));

			bone.emplace_back(std::make_pair(vhs::bones::doll_master::wrist_l, vhs::bones::doll_master::pinkyfinger1_l));
			bone.emplace_back(std::make_pair(vhs::bones::doll_master::pinkyfinger1_l, vhs::bones::doll_master::pinkyfinger2_l));
			bone.emplace_back(std::make_pair(vhs::bones::doll_master::pinkyfinger2_l, vhs::bones::doll_master::pinkyfinger3_l));
			bone.emplace_back(std::make_pair(vhs::bones::doll_master::pinkyfinger3_l, vhs::bones::doll_master::pinkyfinger4_l));

			bone.emplace_back(std::make_pair(vhs::bones::doll_master::pelvis, vhs::bones::doll_master::hip_l));
			bone.emplace_back(std::make_pair(vhs::bones::doll_master::hip_l, vhs::bones::doll_master::hippart1_l));
			bone.emplace_back(std::make_pair(vhs::bones::doll_master::hippart1_l, vhs::bones::doll_master::knee_l));
			bone.emplace_back(std::make_pair(vhs::bones::doll_master::knee_l, vhs::bones::doll_master::kneepart1_l));
			bone.emplace_back(std::make_pair(vhs::bones::doll_master::kneepart1_l, vhs::bones::doll_master::ankle_l));
			bone.emplace_back(std::make_pair(vhs::bones::doll_master::ankle_l, vhs::bones::doll_master::toes_l));
		}

		// right
		{
			bone.emplace_back(std::make_pair(vhs::bones::doll_master::neck_m, vhs::bones::doll_master::shoulder_r));
			bone.emplace_back(std::make_pair(vhs::bones::doll_master::shoulder_r, vhs::bones::doll_master::elbow_r));
			bone.emplace_back(std::make_pair(vhs::bones::doll_master::elbow_r, vhs::bones::doll_master::wrist_r));

			bone.emplace_back(std::make_pair(vhs::bones::doll_master::wrist_r, vhs::bones::doll_master::thumbfinger1_r));
			bone.emplace_back(std::make_pair(vhs::bones::doll_master::thumbfinger1_r, vhs::bones::doll_master::thumbfinger2_r));
			bone.emplace_back(std::make_pair(vhs::bones::doll_master::thumbfinger2_r, vhs::bones::doll_master::thumbfinger3_r));
			bone.emplace_back(std::make_pair(vhs::bones::doll_master::thumbfinger3_r, vhs::bones::doll_master::thumbfinger4_r));

			bone.emplace_back(std::make_pair(vhs::bones::doll_master::wrist_r, vhs::bones::doll_master::indexfinger1_r));
			bone.emplace_back(std::make_pair(vhs::bones::doll_master::indexfinger1_r, vhs::bones::doll_master::indexfinger2_r));
			bone.emplace_back(std::make_pair(vhs::bones::doll_master::indexfinger2_r, vhs::bones::doll_master::indexfinger3_r));
			bone.emplace_back(std::make_pair(vhs::bones::doll_master::indexfinger3_r, vhs::bones::doll_master::indexfinger4_r));

			bone.emplace_back(std::make_pair(vhs::bones::doll_master::wrist_r, vhs::bones::doll_master::middlefinger1_r));
			bone.emplace_back(std::make_pair(vhs::bones::doll_master::middlefinger1_r, vhs::bones::doll_master::middlefinger2_r));
			bone.emplace_back(std::make_pair(vhs::bones::doll_master::middlefinger2_r, vhs::bones::doll_master::middlefinger3_r));
			bone.emplace_back(std::make_pair(vhs::bones::doll_master::middlefinger3_r, vhs::bones::doll_master::middlefinger4_r));

			bone.emplace_back(std::make_pair(vhs::bones::doll_master::wrist_r, vhs::bones::doll_master::ringfinger1_r));
			bone.emplace_back(std::make_pair(vhs::bones::doll_master::ringfinger1_r, vhs::bones::doll_master::ringfinger2_r));
			bone.emplace_back(std::make_pair(vhs::bones::doll_master::ringfinger2_r, vhs::bones::doll_master::ringfinger3_r));
			bone.emplace_back(std::make_pair(vhs::bones::doll_master::ringfinger3_r, vhs::bones::doll_master::ringfinger4_r));

			bone.emplace_back(std::make_pair(vhs::bones::doll_master::wrist_r, vhs::bones::doll_master::pinkyfinger1_r));
			bone.emplace_back(std::make_pair(vhs::bones::doll_master::pinkyfinger1_r, vhs::bones::doll_master::pinkyfinger2_r));
			bone.emplace_back(std::make_pair(vhs::bones::doll_master::pinkyfinger2_r, vhs::bones::doll_master::pinkyfinger3_r));
			bone.emplace_back(std::make_pair(vhs::bones::doll_master::pinkyfinger3_r, vhs::bones::doll_master::pinkyfinger4_r));

			bone.emplace_back(std::make_pair(vhs::bones::doll_master::pelvis, vhs::bones::doll_master::hip_r));
			bone.emplace_back(std::make_pair(vhs::bones::doll_master::hip_r, vhs::bones::doll_master::hippart1_r));
			bone.emplace_back(std::make_pair(vhs::bones::doll_master::hippart1_r, vhs::bones::doll_master::knee_r));
			bone.emplace_back(std::make_pair(vhs::bones::doll_master::knee_r, vhs::bones::doll_master::kneepart1_r));
			bone.emplace_back(std::make_pair(vhs::bones::doll_master::kneepart1_r, vhs::bones::doll_master::ankle_r));
			bone.emplace_back(std::make_pair(vhs::bones::doll_master::ankle_r, vhs::bones::doll_master::toes_r));
		}
	}

	// doll minion
	{
		auto& bone = _bones[3];

		bone.emplace_back(std::make_pair(vhs::bones::doll_minion::head_m, vhs::bones::doll_minion::neck_m));
		bone.emplace_back(std::make_pair(vhs::bones::doll_minion::neck_m, vhs::bones::doll_minion::spine1_m));
		bone.emplace_back(std::make_pair(vhs::bones::doll_minion::spine1_m, vhs::bones::doll_minion::pelvis));

		// left
		{
			bone.emplace_back(std::make_pair(vhs::bones::doll_minion::neck_m, vhs::bones::doll_minion::shoulder_l));
			bone.emplace_back(std::make_pair(vhs::bones::doll_minion::shoulder_l, vhs::bones::doll_minion::elbow_l));
			bone.emplace_back(std::make_pair(vhs::bones::doll_minion::elbow_l, vhs::bones::doll_minion::wrist_l));

			bone.emplace_back(std::make_pair(vhs::bones::doll_minion::pelvis, vhs::bones::doll_minion::hip_l));
			bone.emplace_back(std::make_pair(vhs::bones::doll_minion::hip_l, vhs::bones::doll_minion::knee_l));
			bone.emplace_back(std::make_pair(vhs::bones::doll_minion::knee_l, vhs::bones::doll_minion::ankle_l));
			bone.emplace_back(std::make_pair(vhs::bones::doll_minion::ankle_l, vhs::bones::doll_minion::toes_l));
			bone.emplace_back(std::make_pair(vhs::bones::doll_minion::toes_l, vhs::bones::doll_minion::toesend_l));
		}

		// right
		{
			bone.emplace_back(std::make_pair(vhs::bones::doll_minion::neck_m, vhs::bones::doll_minion::shoulder_r));
			bone.emplace_back(std::make_pair(vhs::bones::doll_minion::shoulder_r, vhs::bones::doll_minion::elbow_r));
			bone.emplace_back(std::make_pair(vhs::bones::doll_minion::elbow_r, vhs::bones::doll_minion::wrist_r));

			bone.emplace_back(std::make_pair(vhs::bones::doll_minion::pelvis, vhs::bones::doll_minion::hip_r));
			bone.emplace_back(std::make_pair(vhs::bones::doll_minion::hip_r, vhs::bones::doll_minion::knee_r));
			bone.emplace_back(std::make_pair(vhs::bones::doll_minion::knee_r, vhs::bones::doll_minion::ankle_r));
			bone.emplace_back(std::make_pair(vhs::bones::doll_minion::ankle_r, vhs::bones::doll_minion::toes_r));
			bone.emplace_back(std::make_pair(vhs::bones::doll_minion::toes_r, vhs::bones::doll_minion::toesend_r));
		}
	}

	// survivor
	{
		auto& bone = _bones[4];

		bone.emplace_back(std::make_pair(vhs::bones::survivor::head, vhs::bones::survivor::neck_01));
		bone.emplace_back(std::make_pair(vhs::bones::survivor::neck_01, vhs::bones::survivor::spine_01));
		bone.emplace_back(std::make_pair(vhs::bones::survivor::spine_01, vhs::bones::survivor::pelvis));

		// left
		{
			bone.emplace_back(std::make_pair(vhs::bones::survivor::neck_01, vhs::bones::survivor::upperarm_l));
			bone.emplace_back(std::make_pair(vhs::bones::survivor::upperarm_l, vhs::bones::survivor::upperarm_twist_01_l));
			bone.emplace_back(std::make_pair(vhs::bones::survivor::upperarm_twist_01_l, vhs::bones::survivor::lowerarm_l));
			bone.emplace_back(std::make_pair(vhs::bones::survivor::lowerarm_l, vhs::bones::survivor::lowerarm_twist_01_l));
			bone.emplace_back(std::make_pair(vhs::bones::survivor::lowerarm_twist_01_l, vhs::bones::survivor::hand_l));

			bone.emplace_back(std::make_pair(vhs::bones::survivor::hand_l, vhs::bones::survivor::thumb_01_l));
			bone.emplace_back(std::make_pair(vhs::bones::survivor::thumb_01_l, vhs::bones::survivor::thumb_02_l));
			bone.emplace_back(std::make_pair(vhs::bones::survivor::thumb_02_l, vhs::bones::survivor::thumb_03_l));
			bone.emplace_back(std::make_pair(vhs::bones::survivor::thumb_03_l, vhs::bones::survivor::thumb_03_end_l));

			bone.emplace_back(std::make_pair(vhs::bones::survivor::hand_l, vhs::bones::survivor::index_01_l));
			bone.emplace_back(std::make_pair(vhs::bones::survivor::index_01_l, vhs::bones::survivor::index_02_l));
			bone.emplace_back(std::make_pair(vhs::bones::survivor::index_02_l, vhs::bones::survivor::index_03_l));
			bone.emplace_back(std::make_pair(vhs::bones::survivor::index_03_l, vhs::bones::survivor::index_03_end_l));

			bone.emplace_back(std::make_pair(vhs::bones::survivor::hand_l, vhs::bones::survivor::middle_01_l));
			bone.emplace_back(std::make_pair(vhs::bones::survivor::middle_01_l, vhs::bones::survivor::middle_02_l));
			bone.emplace_back(std::make_pair(vhs::bones::survivor::middle_02_l, vhs::bones::survivor::middle_03_l));
			bone.emplace_back(std::make_pair(vhs::bones::survivor::middle_03_l, vhs::bones::survivor::middle_03_end_l));

			bone.emplace_back(std::make_pair(vhs::bones::survivor::hand_l, vhs::bones::survivor::ring_01_l));
			bone.emplace_back(std::make_pair(vhs::bones::survivor::ring_01_l, vhs::bones::survivor::ring_02_l));
			bone.emplace_back(std::make_pair(vhs::bones::survivor::ring_02_l, vhs::bones::survivor::ring_03_l));
			bone.emplace_back(std::make_pair(vhs::bones::survivor::ring_03_l, vhs::bones::survivor::ring_03_end_l));

			bone.emplace_back(std::make_pair(vhs::bones::survivor::hand_l, vhs::bones::survivor::pinky_01_l));
			bone.emplace_back(std::make_pair(vhs::bones::survivor::pinky_01_l, vhs::bones::survivor::pinky_02_l));
			bone.emplace_back(std::make_pair(vhs::bones::survivor::pinky_02_l, vhs::bones::survivor::pinky_03_l));
			bone.emplace_back(std::make_pair(vhs::bones::survivor::pinky_03_l, vhs::bones::survivor::pinky_03_end_l));

			bone.emplace_back(std::make_pair(vhs::bones::survivor::pelvis, vhs::bones::survivor::thigh_l));
			bone.emplace_back(std::make_pair(vhs::bones::survivor::thigh_l, vhs::bones::survivor::thigh_twist_01_l));
			bone.emplace_back(std::make_pair(vhs::bones::survivor::thigh_twist_01_l, vhs::bones::survivor::calf_l));
			bone.emplace_back(std::make_pair(vhs::bones::survivor::calf_l, vhs::bones::survivor::calf_twist_01_l));
			bone.emplace_back(std::make_pair(vhs::bones::survivor::calf_twist_01_l, vhs::bones::survivor::foot_l));
		}

		// right
		{
			bone.emplace_back(std::make_pair(vhs::bones::survivor::neck_01, vhs::bones::survivor::upperarm_r));
			bone.emplace_back(std::make_pair(vhs::bones::survivor::upperarm_r, vhs::bones::survivor::upperarm_twist_01_r));
			bone.emplace_back(std::make_pair(vhs::bones::survivor::upperarm_twist_01_r, vhs::bones::survivor::lowerarm_r));
			bone.emplace_back(std::make_pair(vhs::bones::survivor::lowerarm_r, vhs::bones::survivor::lowerarm_twist_01_r));
			bone.emplace_back(std::make_pair(vhs::bones::survivor::lowerarm_twist_01_r, vhs::bones::survivor::hand_r));

			bone.emplace_back(std::make_pair(vhs::bones::survivor::hand_r, vhs::bones::survivor::thumb_01_r));
			bone.emplace_back(std::make_pair(vhs::bones::survivor::thumb_01_r, vhs::bones::survivor::thumb_02_r));
			bone.emplace_back(std::make_pair(vhs::bones::survivor::thumb_02_r, vhs::bones::survivor::thumb_03_r));
			bone.emplace_back(std::make_pair(vhs::bones::survivor::thumb_03_r, vhs::bones::survivor::thumb_03_end_r));

			bone.emplace_back(std::make_pair(vhs::bones::survivor::hand_r, vhs::bones::survivor::index_01_r));
			bone.emplace_back(std::make_pair(vhs::bones::survivor::index_01_r, vhs::bones::survivor::index_02_r));
			bone.emplace_back(std::make_pair(vhs::bones::survivor::index_02_r, vhs::bones::survivor::index_03_r));
			bone.emplace_back(std::make_pair(vhs::bones::survivor::index_03_r, vhs::bones::survivor::index_03_end_r));

			bone.emplace_back(std::make_pair(vhs::bones::survivor::hand_r, vhs::bones::survivor::middle_01_r));
			bone.emplace_back(std::make_pair(vhs::bones::survivor::middle_01_r, vhs::bones::survivor::middle_02_r));
			bone.emplace_back(std::make_pair(vhs::bones::survivor::middle_02_r, vhs::bones::survivor::middle_03_r));
			bone.emplace_back(std::make_pair(vhs::bones::survivor::middle_03_r, vhs::bones::survivor::middle_03_end_r));

			bone.emplace_back(std::make_pair(vhs::bones::survivor::hand_r, vhs::bones::survivor::ring_01_r));
			bone.emplace_back(std::make_pair(vhs::bones::survivor::ring_01_r, vhs::bones::survivor::ring_02_r));
			bone.emplace_back(std::make_pair(vhs::bones::survivor::ring_02_r, vhs::bones::survivor::ring_03_r));
			bone.emplace_back(std::make_pair(vhs::bones::survivor::ring_03_r, vhs::bones::survivor::ring_03_end_r));

			bone.emplace_back(std::make_pair(vhs::bones::survivor::hand_r, vhs::bones::survivor::pinky_01_r));
			bone.emplace_back(std::make_pair(vhs::bones::survivor::pinky_01_r, vhs::bones::survivor::pinky_02_r));
			bone.emplace_back(std::make_pair(vhs::bones::survivor::pinky_02_r, vhs::bones::survivor::pinky_03_r));
			bone.emplace_back(std::make_pair(vhs::bones::survivor::pinky_03_r, vhs::bones::survivor::pinky_03_end_r));

			bone.emplace_back(std::make_pair(vhs::bones::survivor::pelvis, vhs::bones::survivor::thigh_r));
			bone.emplace_back(std::make_pair(vhs::bones::survivor::thigh_r, vhs::bones::survivor::thigh_twist_01_r));
			bone.emplace_back(std::make_pair(vhs::bones::survivor::thigh_twist_01_r, vhs::bones::survivor::calf_r));
			bone.emplace_back(std::make_pair(vhs::bones::survivor::calf_r, vhs::bones::survivor::calf_twist_01_r));
			bone.emplace_back(std::make_pair(vhs::bones::survivor::calf_twist_01_r, vhs::bones::survivor::foot_r));
		}
	}
}

std::vector<std::pair<int, int>>& vhs::bones::get(const ue4::game_framework::a_actor* actor) {
	if (actor->is_a(ue4::sdk::werewolf)) {
		return _bones[0];
	}

	if (actor->is_a(ue4::sdk::toad)) {
		return _bones[1];
	}

	if (actor->is_a(ue4::sdk::doll_master)) {
		return _bones[2];
	}

	if (actor->is_a(ue4::sdk::doll_minion)) {
		return _bones[3];
	}

	if (actor->is_a(ue4::sdk::cheerleader) || actor->is_a(ue4::sdk::jock) || actor->is_a(ue4::sdk::outsider) ||
		actor->is_a(ue4::sdk::punk) || actor->is_a(ue4::sdk::virgin)) {

		return _bones[4];
	}
}