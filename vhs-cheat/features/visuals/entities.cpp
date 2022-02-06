#include "../features.h"

void visuals::entities::run(const sdk::u_world* world, sdk::a_pawn* my_player, sdk::a_player_controller* player_controller) {
	auto levels = world->levels;
	for (auto i = 0; i < levels.size(); i++) {
		if (!levels.is_valid(i)) break;

		const auto level = levels[i];
		if (!level) continue;

		for (auto actors = 0; i < level->actors.size(); actors++) {
			if (!level || !level->actors.is_valid(actors)) break;

			const auto actor = level->actors[actors];
			if (!actor || !actor->root_component) continue;
			if (actor == my_player) continue;

			name(actor, my_player, player_controller);
			// debug(actor, my_player, player_controller);
		}
	}
}

void visuals::entities::name(sdk::a_actor* actor, sdk::a_actor* my_player, sdk::a_player_controller* player_controller) {
	if (actor->is_a(sdk::lockbox_bp) || actor->is_a(sdk::noisemaker_bp) || actor->is_a(sdk::pills_bp) ||
        actor->is_a(sdk::adrenaline_bp) || actor->is_a(sdk::walkie_bp) || actor->is_a(sdk::vending_machine_bp) ||
		actor->is_a(sdk::basket_bp) || actor->is_a(sdk::station_base_bp) || actor->is_a(sdk::flamethrower_bp) ||
		actor->is_a(sdk::molotov_bp) || actor->is_a(sdk::ray_gun_bp) || actor->is_a(sdk::cross_bp) ||
		actor->is_a(sdk::sword_bp) || actor->is_a(sdk::magic_sphere_bp) || actor->is_a(sdk::life_essence_bp) ||
		actor->is_a(sdk::medkit_point_bp)) {

		const auto location = actor->get_location();
		const auto distance = my_player->get_distance_to(actor);
		if (distance * 0.01f >= 30) return;

		const auto distance_string = my_player->get_distance_to_string(actor);

		sdk::vector_2d position{};
		if (player_controller->world_to_screen(location, position)) {
			std::wstring name;
			name.append(actor->get_character_name().c_str()).append(L" [").append(distance_string).append(L"]");

			render::text(position.x, position.y, name.c_str(), { 52, 134, 235, 255 });
		}
	}
}

void visuals::entities::debug(sdk::a_actor* actor, sdk::a_actor* my_player, sdk::a_player_controller* player_controller) {
	const auto name = actor->get_name();
	const auto widestr = std::wstring(name.begin(), name.end());

	const auto location = actor->get_location();
	const auto distance = my_player->get_distance_to(actor);
	if (distance * 0.01f >= 10) return;

	sdk::vector_2d position{};
	if (player_controller->world_to_screen(location, position)) {
		render::text(position.x, position.y, widestr.c_str(), { 52, 134, 235, 255 });
	}
}