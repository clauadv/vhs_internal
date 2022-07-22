#include <includes.h>

void features::misc::auto_skillcheck::run(ue4::game_framework::a_pawn* my_player) {
	if (!variables::misc::auto_skillcheck) return;

	const auto minigame = my_player->minigame;
	if (!minigame) return;

	if (!my_player->get_equipped_weapon() && minigame->state == vhs::minigame::skill_test_state::show_minigame) {
		auto current_value = minigame->get_current_value();
		auto target_value = minigame->get_target_value();

		if (std::abs(current_value - target_value) < 0.05f) {
			minigame->submit_value(minigame->get_current_value());
		}
	}
}