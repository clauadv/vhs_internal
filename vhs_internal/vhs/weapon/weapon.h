#pragma once

namespace vhs::weapon {
	enum class weapon_type {
		none,
		cross,
		holy_slingshot,
		parchment,
		talisman,
		molotov,
		flamethrower,
		rc_copter,
		static_shield,
		ray_gun,
		demon_sword,
		holy_staff,
		flame_mine
	};

	class a_weapon_base : public ue4::game_framework::a_actor {
	public:
		char pad_0001[0x140]; // 0x138(0x140)
		vhs::weapon::weapon_type type; // 0x278(0x01)

		std::pair<ue4::containers::f_string, ue4::math::color> get_weapon_name();
	};
}