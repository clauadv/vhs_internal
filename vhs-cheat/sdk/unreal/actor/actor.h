#pragma once

namespace sdk {
	struct u_object;
	struct a_pawn;
	struct u_scene_component;
	struct a_actor;
	struct vector;
	struct rotator;
	struct u_string;
	struct color;

	struct a_actor : sdk::u_object {
		char pad_0001[0xF0]; // 0x28(0xF0)
		sdk::a_pawn* instigator; // 0x118(0x08)
		char pad_0002[0x10]; // 0x120(0x10)
		sdk::u_scene_component* root_component; // 0x130(0x08)

		sdk::vector get_location();
		sdk::rotator get_rotation();
		void get_bounds(bool only_colliding_components, sdk::vector* origin, sdk::vector* extent);
		float get_distance_to(sdk::a_actor* actor);
		std::wstring get_distance_to_string(sdk::a_actor* actor);
		std::pair<sdk::u_string, sdk::color> get_character_name() const;
	};
}