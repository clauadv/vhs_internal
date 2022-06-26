#include <includes.h>

void* ue4::game_framework::a_pawn::get_spectral() {
	struct {
		void* return_value;
	} params{};

	ue4::sdk::process_event(this, ue4::sdk::get_spectral, &params);

	return params.return_value;
}

vhs::weapon::a_weapon_base* ue4::game_framework::a_pawn::get_equipped_weapon() {
	struct {
		vhs::weapon::a_weapon_base* return_value;
	} params{};

	ue4::sdk::process_event(this, ue4::sdk::get_equipped_weapon, &params);

	return params.return_value;
}