#pragma once
#include "../sdk/sdk.h"
#include "../render/render.h"
#include "../sdk/misc/bones.h"

namespace visuals::killer {
	inline std::once_flag flag;
	void run(const sdk::u_world* world, sdk::a_pawn* my_player, sdk::a_player_controller* player_controller);
	void box(const sdk::vector_2d& head, float width, float height);
	void name(const sdk::vector_2d& head, float width, float height, sdk::a_pawn* my_player, sdk::a_actor* actor);
	void skeleton(const sdk::a_actor* actor, sdk::a_player_controller* player_controller, sdk::u_skeletal_mesh_component* mesh);
}

namespace visuals::survivor {
	inline std::once_flag flag;
	void run(const sdk::u_world* world, sdk::a_pawn* my_player, sdk::a_player_controller* player_controller);
	void name(const sdk::vector_2d& head, float width, float height, sdk::a_pawn* my_player, sdk::a_actor* actor);
	void skeleton(const sdk::a_actor* actor, sdk::a_player_controller* player_controller, sdk::u_skeletal_mesh_component* mesh);
}

namespace visuals::entities {
	void run(const sdk::u_world* world, sdk::a_pawn* my_player, sdk::a_player_controller* player_controller);
	void name(sdk::a_actor* actor, sdk::a_actor* my_player, sdk::a_player_controller* player_controller);
}