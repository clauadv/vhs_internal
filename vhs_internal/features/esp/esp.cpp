#include <includes.h>

void features::esp::players::draw(ue4::game_framework::a_pawn* pawn, ue4::game_framework::a_pawn* my_player, ue4::components::u_skeletal_mesh_component* mesh, ue4::game_framework::a_player_controller* player_controller) {
	
	const auto root = mesh->get_bone(0, player_controller);
	if (root.is_zero()) return;

	// draw name
	{
		const auto character = pawn->get_actor_info(my_player);
		const auto distance = my_player->get_distance_to_string(pawn);

		std::wstring text;
		text.append(std::get<0>(character).c_str()).append(L" [").append(distance).append(L"]");
		std::ranges::transform(text.begin(), text.end(), text.begin(), ::tolower);

		render::text({ root.x, root.y + 2.f }, text.c_str(), std::get<1>(character));
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
}
