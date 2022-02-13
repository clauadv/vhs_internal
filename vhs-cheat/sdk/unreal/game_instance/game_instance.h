#pragma once

namespace sdk {
	template<class T>
	struct u_array;
	struct u_player;

	struct u_game_instance {
		char pad_0001[0x38]; // 0x00(0x38)
		sdk::u_array<sdk::u_player*> local_players; // 0x38(0x10)
	};
}