#pragma once

namespace ue4::game_framework {
	class a_player_state : public ue4::game_framework::a_actor {
	public:
		char pad_0001[0x148]; // 0x138(0x148)
		ue4::game_framework::a_pawn* pawn_private; // 0x280(0x08)
	};
}