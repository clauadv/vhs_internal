#pragma once

namespace sdk {
	struct a_actor;

	struct a_player_state : sdk::a_actor {
		char pad_0001[0x148]; // 0x138(0x148)
		sdk::a_pawn* pawn_private; // 0x280(0x08);
	};
}