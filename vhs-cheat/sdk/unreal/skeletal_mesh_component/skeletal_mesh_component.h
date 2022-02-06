#pragma once
#include "../object_array/object_array.h"
#include "../../other/math.h"

namespace sdk {
	struct a_player_controller;

	struct u_skeletal_mesh_component : sdk::u_object {
		sdk::u_name get_bone_name(int index);
		sdk::vector get_bone_matrix(int index);
		sdk::vector_2d get_bone(int index, sdk::a_player_controller* player_controller);
		void dump_bones();
	};
}