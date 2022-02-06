#pragma once

namespace sdk {
	struct a_game_state_base;
	struct u_level;
	struct u_game_instance;

	struct u_world {
		char pad_0001[0x30]; // 0x00(0x30)
		sdk::u_level* persistent_level; // 0x30(0x08)
		char pad_0002[0xE8]; // 0x38(0xE8)
		sdk::a_game_state_base* game_state; // 0x120(0x08)
		char pad_0003[0x10]; // 0x128(0x10)
		sdk::u_array<struct u_level*> levels; // 0x138(0x10)
		char pad_0004[0x38]; // 0x148(0x38)
		sdk::u_game_instance* owning_game_instance; // 0x180(0x08)
	};

	inline u_world* world;
}