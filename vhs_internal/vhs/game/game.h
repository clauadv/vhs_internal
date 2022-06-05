#pragma once

namespace vhs::game {
	class a_base_char : public ue4::game_framework::a_pawn {
	public:
		char pad_0001[0x1110]; // 0x288(0x1110)
		void* active_doll_minion; // 0x1398(0x08)
	};
}