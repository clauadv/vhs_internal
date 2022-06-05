#pragma once

namespace features::esp::players {
	inline std::once_flag flag;
	void draw(const ue4::engine::u_world*, ue4::game_framework::a_pawn*, ue4::game_framework::a_player_controller*);
}

namespace features::esp::entities {
	inline std::once_flag flag;
	void draw(const ue4::engine::u_world*, ue4::game_framework::a_pawn*, ue4::game_framework::a_player_controller*);
}