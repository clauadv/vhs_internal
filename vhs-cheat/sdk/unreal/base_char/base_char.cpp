#include <pch.h>

// sadly these work only on local server

void sdk::a_base_char::set_reveal_time(const float new_value) {
	/*
	* DoServerSetDemonSwordRevealTimeRemaining => red
	* DoServerSetRaygunRevealTimeRemaining => blue
	*/
	static const auto fn = sdk::object_array->find_object(_("Function Game.FPChar.DoServerSetDemonSwordRevealTimeRemaining"));
	if (!fn) return;

	struct {
		float new_value;
	} params{};

	params.new_value = new_value;

	const auto flags = fn->flags;
	sdk::process_event(this, fn, &params);
	fn->flags = flags;
}

void sdk::a_base_char::remove_injury(bool bReduceLife, bool bApplyArendaline) {
	static const auto fn = sdk::object_array->find_object(_("Function Game.TPChar.DoServerApplyInjury"));
	if (!fn) return;

	struct {
		bool bReduceLife;
		bool bApplyArendaline;
	} params{};

	params.bReduceLife = bReduceLife;
	params.bApplyArendaline = bApplyArendaline;

	const auto flags = fn->flags;
	sdk::process_event(this, fn, &params);
	fn->flags = flags;
}