#pragma once

namespace sdk {
	enum EWeaponTypeEnum {
		wt_none = 0,
		wt_cross = 1,
		wt_holyslingshot = 2,
		wt_parchment = 3,
		wt_talisman = 4,
		wt_molotov = 5,
		wt_flamethrower = 6,
		wt_rccopter = 7,
		wt_staticshield = 8,
		wt_raygun = 9,
		wt_demonsword = 10,
		wt_holystaff = 11,
		wt_flamemine = 12,
		wt_count = 13,
		wt_max = 14
	};

	struct a_weapon_base : sdk::a_actor {
		char pad_0001[0x110]; // 0x138(0x110)
		float charge_remaining; // 0x248(0x04)
		float max_charge; // 0x24c(0x04)
	};
}