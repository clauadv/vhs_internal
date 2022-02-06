#pragma once
#include "../actor/actor.h"

namespace sdk {
	struct a_player_state;

	struct a_controller : sdk::a_actor {
		char pad_0001[0xf0]; // 0x138(0xf0)
		sdk::a_player_state* player_state; // 0x228(0x08)
	};
}