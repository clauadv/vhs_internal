#include <includes.h>

std::pair<ue4::containers::f_string, ue4::math::color> vhs::station::a_station_base::get_station_name() {
	if (this->type == vhs::station::damage_type::burn)
		return { L"burn station", { 0.89f, 0.56f, 0.07f, 1.f } };

	if (this->type == vhs::station::damage_type::holy)
		return { L"holy station", { 0.89f, 0.88f, 0.25f, 1.f } };

	if (this->type == vhs::station::damage_type::occult)
		return { L"occult station", { 0.76f, 0.24f, 0.87f, 1.f } };

	if (this->type == vhs::station::damage_type::shock)
		return { L"shock station", { 0.20f, 0.80f, 0.86f, 1.f } };

	return { L"none", { 0.f, 0.f, 0.f, 1.f } };
}

vhs::weapon::weapon_type vhs::station::a_station_base::get_station_weapon_type() {
	struct {
		vhs::weapon::weapon_type return_value;
	} params{};

	ue4::sdk::process_event(this, ue4::sdk::get_crafting_weapon_type, &params);

	return params.return_value;
}

std::wstring vhs::station::a_station_base::get_crafting_percent(ue4::game_framework::a_player_state* player_state, ue4::game_framework::a_pawn* my_player, vhs::weapon::weapon_type weapon_type) {
	struct {
		ue4::game_framework::a_player_state* player_state;
		ue4::game_framework::a_pawn* my_player;
		vhs::weapon::weapon_type weapon_type;
		float return_value;
	} params{};

	params.player_state = player_state;
	params.my_player = my_player;
	params.weapon_type = weapon_type;

	ue4::sdk::process_event(this, ue4::sdk::get_crafting_percent, &params);

	const auto to_string = std::to_string(static_cast<int>(params.return_value * 100 - std::floor(params.return_value) * 100));
	std::wstring percent(to_string.begin(), to_string.end());

	return percent;
}