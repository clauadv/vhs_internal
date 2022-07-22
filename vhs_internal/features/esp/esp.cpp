#include <includes.h>

void features::esp::players::draw(ue4::game_framework::a_pawn* pawn, ue4::game_framework::a_pawn* my_player, ue4::components::u_skeletal_mesh_component* mesh, ue4::game_framework::a_player_controller* player_controller) {
	const auto root = mesh->get_bone(0, player_controller);
	if (root.is_zero()) return;

	// draw name
	{
		const auto actor_info = pawn->get_actor_info(my_player);
		const auto distance = my_player->get_distance_to_string(pawn);

		std::wstring text;
		text.append(std::get<0>(actor_info).c_str()).append(L" [").append(distance).append(L"]");
		std::ranges::transform(text.begin(), text.end(), text.begin(), ::tolower);

		render::text({ root.x, root.y + 2.f }, text.c_str(), std::get<1>(actor_info));
	}

	// draw weapon
	{
		const auto weapon = pawn->get_equipped_weapon();
		if (weapon) {
			const auto weapon_name = weapon->get_weapon_name();
			const auto distance = my_player->get_distance_to_string(pawn);

			render::text({ root.x, root.y + 20.f }, weapon_name.first.c_str(), weapon_name.second);
		}
	}

	// draw skeleton
	{
		for (const auto& bone : vhs::bones::get_array(mesh, pawn)) {
			ue4::math::vector_2d first_bone{}, second_bone{};

			auto first = mesh->get_bone_matrix(bone.first);
			auto second = mesh->get_bone_matrix(bone.second);

			if (player_controller->world_to_screen(first, first_bone) && player_controller->world_to_screen(second, second_bone)) {
				render::line({ first_bone.x, first_bone.y }, { second_bone.x, second_bone.y }, 1.f, { 1.f, 1.f, 1.f, 1.f });
			}
		}
	}

	// draw snap lines
	{
		// render::line(root, { render::screen.x / 2.f, render::screen.y }, 1.f, color);
	}
}

void features::esp::entities::draw(ue4::game_framework::a_actor* actor, ue4::game_framework::a_pawn* my_player, ue4::game_framework::a_player_controller* player_controller) {
	const std::vector<ue4::core_object::u_object*> actors = {
		ue4::sdk::lockbox, ue4::sdk::noisemaker,
		ue4::sdk::pills, ue4::sdk::adrenaline,
		ue4::sdk::walkie, ue4::sdk::vending_machine,
		ue4::sdk::basket, ue4::sdk::station_base,
		ue4::sdk::medkit, ue4::sdk::life_essence,
		ue4::sdk::trap
	};

	for (const auto& _actor : actors) {
		if (actor->is_a(_actor)) {
			const auto distance_string = my_player->get_distance_to_string(actor);
			const auto actor_info = actor->get_actor_info(my_player);

			const auto distance = my_player->get_distance_to(actor);
			if (distance * 0.01f >= std::get<2>(actor_info)) return;

			const auto location = actor->get_location();

			ue4::math::vector_2d position{};
			if (player_controller->world_to_screen(location, position)) {

				// draw name
				{
					std::wstring text;
					text.append(std::get<0>(actor_info).c_str()).append(L" [").append(distance_string).append(L"]");

					render::text(position, text.c_str(), std::get<1>(actor_info));
				}
			}
		}
	}
}