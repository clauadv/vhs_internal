#pragma once
#include "../object_array/object_array.h"
#include "../../other/math.h"
#include "../../other/string.h"
#include "../scene_component/scene_component.h"

namespace sdk {
	struct a_pawn;

	struct a_actor : u_object {
		char pad_0001[0xF0]; // 0x28(0xF0)
		sdk::a_pawn* instigator; // 0x118(0x08)
		char pad_0002[0x10]; // 0x120(0x10)
		sdk::u_scene_component* root_component; // 0x130(0x08)

		sdk::vector get_location();
		sdk::rotator get_rotation();
		void get_bounds(bool only_colliding_components, sdk::vector* origin, sdk::vector* extent);
		float get_distance_to(sdk::a_actor* actor);
		std::wstring get_distance_to_string(sdk::a_actor* actor);
		sdk::u_string get_name() const;
	};
}