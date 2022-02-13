#include <pch.h>

bool sdk::a_player_controller::world_to_screen(const sdk::vector& world, sdk::vector_2d& screen) {
	static const auto fn = sdk::object_array->find_object(_("Function Engine.PlayerController.ProjectWorldLocationToScreen"));
	if (!fn) return false;

	struct {
		sdk::vector world;
		sdk::vector_2d screen;
		bool player_viewport_relative;
		bool return_value;
	} params{};

	params.world = world;
	params.screen = screen;
	params.player_viewport_relative = false;

	sdk::process_event(this, fn, &params);

	screen = params.screen;

	return params.return_value;
}