#pragma once
#include "../sdk/sdk.h"
#include "../render/render.h"
#include "minhook/minhook.h"

namespace hooks {
	bool initialize();
	bool release();

	namespace post_render {
		static constexpr auto index = 0x63;
		using fn = void(__thiscall*)(sdk::u_object*, sdk::u_canvas*);
		static void __stdcall hook(sdk::u_object* viewport_client, sdk::u_canvas* canvas);
	}

	namespace view_point {
		using fn = void(__thiscall*)(sdk::u_player*, sdk::minimal_view_info*, sdk::EStereoscopicPass);
		static void __stdcall hook(sdk::u_player* player, sdk::minimal_view_info* view_info, sdk::EStereoscopicPass stereo_pass);
	}
}