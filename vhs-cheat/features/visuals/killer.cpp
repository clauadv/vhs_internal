#include "../features.h"

void visuals::killer::run(const sdk::u_world* world, sdk::a_pawn* my_player, sdk::a_player_controller* player_controller) {
	auto actors = world->persistent_level->actors;
	for (auto i = 0; i < actors.size(); i++) {
		const auto actor = actors[i];
		if (!actor || actor->root_component == nullptr) continue;
		if (actor == my_player) continue;

		const auto pawn = actor->instigator;
		if (!pawn) continue;

		std::call_once(flag, []() {
			bones::initialize();
		});

		if (actor->is_a(sdk::werewolf_bp) || actor->is_a(sdk::toad_bp) ||
			actor->is_a(sdk::doll_master_bp) || actor->is_a(sdk::doll_minion_bp)) {

			const auto mesh = pawn->mesh;
			if (!mesh) continue;

			const auto state = pawn->player_state;
			if (!state) continue;

			const auto character = reinterpret_cast<sdk::a_base_char*>(actor->instigator);
			if (!character) continue;

			const auto bone = bones::get_bone_array(actor);
			if (bone.empty()) continue;

			const auto head = mesh->get_bone(bone.at(0).first, player_controller);
			const auto root = mesh->get_bone(0, player_controller);

			if (head.is_zero()) continue;
			if (root.is_zero()) continue;

			const float height = abs(root.y - head.y);
			const float width = height * 0.5f;

			name(head, width, height, my_player, actor);
			skeleton(actor, player_controller, mesh);

			// character->force_thirdperson_camera = true;
		}
	}
}

void visuals::killer::box(const sdk::vector_2d& head, const float width, const float height) {
	render::cornered_box(head.x, head.y, width, height, 1.f, { 255, 0, 0, 255 });
}

void visuals::killer::name(const sdk::vector_2d& head, const float width, const float height, sdk::a_pawn* my_player, sdk::a_actor* actor) {
	const auto character_name = actor->get_character_name();
	const auto distance = my_player->get_distance_to_string(actor);

	std::wstring name;
	name.append(character_name.first.c_str()).append(L" [").append(distance).append(L"]");

	const auto text_size = render::text_size(name.c_str());
	render::text(head.x + (width / 2.f) - (text_size.x / 2.f), head.y + height + 2.f, name.c_str(), character_name.second);
}

void visuals::killer::skeleton(const sdk::a_actor* actor, sdk::a_player_controller* player_controller, sdk::u_skeletal_mesh_component* mesh) {
	for (const auto& bone : bones::get_bone_array(actor)) {
		sdk::vector_2d first_bone{}, second_bone{};

		auto first = mesh->get_bone_matrix(bone.first);
		auto second = mesh->get_bone_matrix(bone.second);

		if (player_controller->world_to_screen(first, first_bone) && player_controller->world_to_screen(second, second_bone)) {
			render::line(first_bone.x, first_bone.y, second_bone.x, second_bone.y, 1.f, { 255, 255, 255, 255 });
		}
	}
}