#include <includes.h>

void features::run(const ue4::engine::u_world* world, ue4::game_framework::a_pawn* my_player, ue4::game_framework::a_player_controller* player_controller) {
	const auto& game_state = world->game_state;
	if (!game_state) return;

	auto players = game_state->player_array;
	for (auto i = 0; i < players.size(); i++) {
		if (!players.is_valid(i)) break;

		const auto player = players[i];
		if (!player) continue;

		const auto pawn = player->pawn_private;
		if (!pawn) continue;
		if (pawn == my_player) continue;

		const auto mesh = pawn->mesh;
		if (!mesh) continue;

		const auto state = pawn->player_state;
		if (!state) continue;

		features::esp::players::draw(pawn, my_player, mesh, player_controller);
		features::misc::auto_skillcheck::run(my_player);
	}

	auto levels = world->levels;
	for (auto i = 0; i < levels.size(); i++) {
		if (!levels.is_valid(i)) break;

		const auto level = levels[i];
		if (!level) continue;

		for (auto actors = 0; i < level->actors.size(); actors++) {
			if (!level || !level->actors.is_valid(actors)) break;

			const auto actor = level->actors[actors];
			if (!actor || actor->root_component == nullptr) continue;
			if (actor == my_player) continue;

			features::esp::entities::draw(actor, my_player, player_controller);
		}
	}
}