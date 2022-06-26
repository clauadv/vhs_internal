#pragma once

namespace vhs::minigame {
	enum class skill_test_state {
		inactive,
		hidden,
		warning_continuous,
		warning_only,
		show_minigame,
		post_submit
	};

	class a_minigame_base : public ue4::core_object::u_object {
	public:
		char pad_0001[0x90]; // 0x28(0x90)
		vhs::minigame::skill_test_state state; // 0xb8(0x01)

		float get_current_value();
		float get_target_value();
		void submit_value(float value);
	};
}