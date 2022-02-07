#include "../features.h"

void visuals::survivor::run(const sdk::u_world* world, sdk::a_pawn* my_player, sdk::a_player_controller* player_controller) {
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

		if (actor->is_a(sdk::cheerleader_bp) || actor->is_a(sdk::jock_bp) || actor->is_a(sdk::outsider_bp) ||
											   actor->is_a(sdk::punk_bp) || actor->is_a(sdk::virgin_bp)) {
			const auto mesh = pawn->mesh;
			if (!mesh) continue;

			const auto state = pawn->player_state;
			if (!state) continue;

			const auto character = reinterpret_cast<sdk::a_base_char*>(actor->instigator);
			if (!character) continue;

			if (GetAsyncKeyState(VK_F9) & 1) {
				character->remove_injury(false, true);
			}

			const auto head = mesh->get_bone(bones::survivor::head, player_controller);
			const auto foot = mesh->get_bone(bones::survivor::Root, player_controller);

			if (head.x == 0.f && head.y == 0.f) continue;
			if (foot.x == 0.f && foot.y == 0.f) continue;

			const float height = abs(foot.y - head.y);
			const float width = height * 0.5f;

			name(head, width, height, my_player, actor);
			skeleton(actor, player_controller, mesh);
		}
	}
}

void visuals::survivor::name(const sdk::vector_2d& head, const float width, const float height, sdk::a_pawn* my_player, sdk::a_actor* actor) {
	const auto distance = my_player->get_distance_to_string(actor);

	std::wstring name;
	name.append(actor->get_character_name().c_str()).append(L" [").append(distance).append(L"]");

	const auto text_size = render::text_size(name.c_str());
	render::text(head.x + (width / 2.f) - (text_size.x / 2.f), head.y + height + 2.f, name.c_str(), { 255, 255, 255, 255 });
}

void visuals::survivor::skeleton(const sdk::a_actor* actor, sdk::a_player_controller* player_controller, sdk::u_skeletal_mesh_component* mesh) {
	for (const auto& bone : bones::get_bone_array(actor)) {
		sdk::vector_2d first_bone{}, second_bone{};

		auto first = mesh->get_bone_matrix(bone.first);
		auto second = mesh->get_bone_matrix(bone.second);

		if (player_controller->world_to_screen(first, first_bone) && player_controller->world_to_screen(second, second_bone)) {
			render::line(first_bone.x, first_bone.y, second_bone.x, second_bone.y, 1.f, { 255, 255, 255, 255 });
		}
	}
}