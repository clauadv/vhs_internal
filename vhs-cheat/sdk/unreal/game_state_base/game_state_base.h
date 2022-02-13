#pragma once

namespace sdk {
	template<class T>
	struct u_array;
	struct a_player_state;

	struct a_game_state_base {
		char pad_0001[0x238]; // 0x00(0x238)
		struct sdk::u_array <sdk::a_player_state*> PlayerArray; // 0x238(0x10)
	};
}