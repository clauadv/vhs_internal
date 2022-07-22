#pragma once

namespace variables::menu {
	inline bool opened{ true };
}

namespace variables::players {
	inline bool name{ false };
	inline bool weapon{ false };
	inline bool skeleton{ false };

	inline float teen_color[4]{ 1.f, 1.f, 1.f, 1.f };
	inline float monster_color[4]{ 1.f, 0.f, 0.f, 1.f };
}

namespace variables::entities {
	inline bool lockbox{ false };
	inline float lockbox_color[4]{ 0.2f, 0.5f, 0.9f, 1.f };

	inline bool noisemaker{ false };
	inline float noisemaker_color[4]{ 0.2f, 0.5f, 0.9f, 1.f };

	inline bool escape_door{ false };
	inline float escape_door_color[4]{ 0.2f, 0.5f, 0.9f, 1.f };

	inline bool pills{ false };
	inline float pills_color[4]{ 0.2f, 0.5f, 0.9f, 1.f };

	inline bool adrenaline{ false };
	inline float adrenaline_color[4]{ 0.2f, 0.5f, 0.9f, 1.f };

	inline bool walkie{ false };
	inline float walkie_color[4]{ 0.2f, 0.5f, 0.9f, 1.f };

	inline bool vending{ false };
	inline float vending_color[4]{ 0.2f, 0.5f, 0.9f, 1.f };

	inline bool basket{ false };
	inline float basket_color[4]{ 0.2f, 0.5f, 0.9f, 1.f };

	inline bool station{ false };

	inline bool medkit{ false };
	inline float medkit_color[4]{ 0.2f, 0.5f, 0.9f, 1.f };

	inline bool life_essence{ false };
	inline float life_essence_color[4]{ 0.2f, 0.5f, 0.9f, 1.f };

	inline bool trap{ false };
	inline float trap_color[4]{ 0.2f, 0.5f, 0.9f, 1.f };

	inline float max_distance{ 30.f };
}

namespace variables::misc {
	inline bool auto_skillcheck{ false };

	inline bool fov_changer{ false };
	inline float fov_value{ 90.f };
}