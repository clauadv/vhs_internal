#include <includes.h>

float vhs::minigame::a_minigame_base::get_current_value() {
	struct {
		float return_value;
	} params{};
	
	ue4::sdk::process_event(this, ue4::sdk::get_current_value, &params);

	return params.return_value;
}

float vhs::minigame::a_minigame_base::get_target_value() {
	struct {
		float return_value;
	} params{};

	ue4::sdk::process_event(this, ue4::sdk::get_target_value, &params);

	return params.return_value;
}

void vhs::minigame::a_minigame_base::submit_value(float value) {
	struct {
		float value;
	} params{};

	params.value = value;

	const auto flags = ue4::sdk::submit_value->flags;
	ue4::sdk::submit_value->flags |= 0x00000400;

	ue4::sdk::process_event(this, ue4::sdk::submit_value, &params);

	ue4::sdk::submit_value->flags = flags;
}