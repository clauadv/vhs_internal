#pragma once

namespace sdk {
	struct a_pawn;
	struct a_weapon_base;

	struct a_base_char : sdk::a_pawn {
		char pad_0001[0x418]; // 0x288(0x418)
		bool can_move_character; // 0x6a0(0x01)
		char pad_0002[0xbf]; // 0x6a1(0xbf)
		sdk::a_weapon_base* equipped_weapon; // 0x760(0x08)
		char pad_0004[0x8e8]; // 0x768(0x8e8)
		bool force_thirdperson_camera; // 0x1050(0x01)
		char pad_0005[0x347]; // 0x768(0x347)
		void* active_doll_minion; // 0x1398(0x08)

		void set_reveal_time(float new_value);
		void remove_injury(bool bReduceLife, bool bApplyArendaline);
	};
}