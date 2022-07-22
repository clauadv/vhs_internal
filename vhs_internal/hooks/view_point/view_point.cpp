#include <includes.h>
#include "../hooks.h"

void hooks::view_point::hook(ue4::engine::u_player* local_player, ue4::engine::f_minimal_view_info* view_info, ue4::engine::stereoscopic_pass stereo_pass) {
	hooks::view_point::original(local_player, view_info, stereo_pass);

	if (variables::misc::fov_changer) {
		view_info->fov = variables::misc::fov_value;
	}
}