#pragma once

namespace sdk {
	struct u_skeletal_mesh_component;

	struct a_pawn : sdk::a_actor {
		char pad_0001[0x108]; // 0x138(0x108)
		sdk::a_player_state* player_state; // 0x240(0x08)
		char pad_0002[0x38]; // 0x248(0x38)
		sdk::u_skeletal_mesh_component* mesh; // 0x280(0x08)
	};
}