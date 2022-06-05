#include <includes.h>

void features::esp::players::draw(const ue4::engine::u_world* world, ue4::game_framework::a_pawn* my_player, ue4::game_framework::a_player_controller* player_controller) {
	auto actors = world->persistent_level->actors;
	for (auto i = 0; i < actors.size(); i++) {
		const auto actor = actors[i];
		if (!actor || actor->root_component == nullptr) continue;
		if (actor == my_player) continue;

		const auto pawn = actor->instigator;
		if (!pawn) continue;

		std::call_once(features::esp::players::flag, [] {
			vhs::bones::initialize();
		});

		if (actor->is_a(ue4::sdk::werewolf) || actor->is_a(ue4::sdk::toad) || actor->is_a(ue4::sdk::doll_master) ||
			actor->is_a(ue4::sdk::doll_minion) || actor->is_a(ue4::sdk::cheerleader) || actor->is_a(ue4::sdk::jock) ||
			actor->is_a(ue4::sdk::outsider) || actor->is_a(ue4::sdk::punk) || actor->is_a(ue4::sdk::virgin)) {

			const auto mesh = pawn->mesh;
			if (!mesh) continue;

			const auto character = reinterpret_cast<vhs::game::a_base_char*>(actor->instigator);
			if (!character) continue;

			const auto state = pawn->player_state;
			if (!state) continue;

			const auto& bone = vhs::bones::get(actor);
			if (bone.empty()) continue;

			const auto head = mesh->get_bone(bone.at(0).first, player_controller);
			const auto root = mesh->get_bone(0, player_controller);

			if (head.is_zero()) continue;
			if (root.is_zero()) continue;

			const float height = abs(root.y - head.y);
			const float width = height * 0.5f;

			// draw name
			{
				const auto character_name = actor->get_actor_name();
				const auto distance = my_player->get_distance_to_string(actor);

				std::wstring name;
				name.append(character_name.first.c_str()).append(L" [").append(distance).append(L"]");

				const auto text_size = render::text_size(name.c_str());
				render::text({ head.x + (width / 2.f) - (text_size.x / 2.f), head.y + height + 2.f }, name.c_str(), character_name.second);
			}

			// draw skeleton
			{
				for (const auto& bone : vhs::bones::get(actor)) {
					ue4::math::vector_2d _first{}, _second{};

					auto first = mesh->get_bone_matrix(bone.first);
					auto second = mesh->get_bone_matrix(bone.second);

					if (player_controller->world_to_screen(first, _first) && player_controller->world_to_screen(second, _second)) {
						render::line({ _first.x, _first.y }, { _second.x, _second.y }, 1.f, { 255, 255, 255, 255 });
					}
				}
			}
		}
	}
}

void features::esp::entities::draw(const ue4::engine::u_world* world, ue4::game_framework::a_pawn* my_player, ue4::game_framework::a_player_controller* player_controller) {
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

			if (actor->is_a(ue4::sdk::station_base)) {

				const auto location = actor->get_location();

				ue4::math::vector_2d position{};
				if (player_controller->world_to_screen(location, position)) {
					const auto character_name = actor->get_actor_name();
					const auto distance_string = my_player->get_distance_to_string(actor);

					// draw name
					{
						std::wstring name;
						name.append(character_name.first.c_str()).append(L" [").append(distance_string).append(L"]");

						render::text({ position.x, position.y }, name.c_str(), character_name.second);
					}
				}
			}

			if (actor->is_a(ue4::sdk::lockbox) || actor->is_a(ue4::sdk::noisemaker) || actor->is_a(ue4::sdk::pills) ||
				actor->is_a(ue4::sdk::adrenaline) || actor->is_a(ue4::sdk::walkie) || actor->is_a(ue4::sdk::vending_machine) ||
				actor->is_a(ue4::sdk::basket) || actor->is_a(ue4::sdk::flamethrower) || actor->is_a(ue4::sdk::molotov) ||
				actor->is_a(ue4::sdk::ray_gun) || actor->is_a(ue4::sdk::cross) || actor->is_a(ue4::sdk::sword) ||
				actor->is_a(ue4::sdk::magic_sphere) || actor->is_a(ue4::sdk::life_essence) || actor->is_a(ue4::sdk::medkit) ||
				actor->is_a(ue4::sdk::trap)) {

				const auto distance = my_player->get_distance_to(actor);
				if (distance * 0.01f >= 30.f || distance * 0.01f == 0.f) continue;

				const auto location = actor->get_location();

				ue4::math::vector_2d position{};
				if (player_controller->world_to_screen(location, position)) {
					const auto character_name = actor->get_actor_name();
					const auto distance_string = my_player->get_distance_to_string(actor);

					// draw name
					{
						std::wstring name;
						name.append(character_name.first.c_str()).append(L" [").append(distance_string).append(L"]");

						render::text({ position.x, position.y }, name.c_str(), character_name.second);
					}
				}
			}
		}
	}
}