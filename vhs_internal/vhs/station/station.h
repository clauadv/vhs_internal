#pragma once

namespace vhs::station {
	enum class damage_type {
		none,
		burn,
		holy,
		occult,
		shock
	};

	class a_station_base : public ue4::game_framework::a_actor {
	public:
		char pad_0001[0x110]; // 0x138(0x110)
		vhs::station::damage_type type; // 0x248(0x01)

		std::pair<ue4::containers::f_string, ue4::math::color> get_station_name();
		vhs::weapon::weapon_type get_station_weapon_type();
		std::wstring get_crafting_percent(ue4::game_framework::a_player_state* player_state, ue4::game_framework::a_pawn* my_player, vhs::weapon::weapon_type weapon_type);
	};
}