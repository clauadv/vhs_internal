#pragma once

namespace features {
	void run(const ue4::engine::u_world* world, ue4::game_framework::a_pawn* my_player, ue4::game_framework::a_player_controller* player_controller);
}

namespace features::esp::players {
	void draw(ue4::game_framework::a_pawn* pawn, ue4::game_framework::a_pawn* my_player, ue4::components::u_skeletal_mesh_component* mesh, ue4::game_framework::a_player_controller* player_controller);
}