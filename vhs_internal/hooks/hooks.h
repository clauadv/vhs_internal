#pragma once

namespace hooks {
	bool initialize();
	bool release();
}

namespace hooks::post_render {
	static constexpr auto index = 0x63;
	using fn = void(__thiscall*)(ue4::core_object::u_object*, ue4::engine::u_canvas*);
	inline fn original;
	void __stdcall hook(ue4::core_object::u_object* viewport_client, ue4::engine::u_canvas* canvas);
}

namespace hooks::view_point {
	using fn = void(__thiscall*)(ue4::engine::u_player*, ue4::engine::f_minimal_view_info*, ue4::engine::stereoscopic_pass);
	inline fn original;
	void __stdcall hook(ue4::engine::u_player* player, ue4::engine::f_minimal_view_info* view_info, ue4::engine::stereoscopic_pass stereo_pass);
}