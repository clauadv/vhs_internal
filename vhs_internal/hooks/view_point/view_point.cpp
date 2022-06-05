#include <includes.h>
#include "../hooks.h"

void __stdcall hooks::view_point::hook(ue4::engine::u_player* player, ue4::engine::f_minimal_view_info* view_info, ue4::engine::stereoscopic_pass stereo_pass) {
	hooks::view_point::original(player, view_info, stereo_pass);

	view_info->fov = 100.f;
}