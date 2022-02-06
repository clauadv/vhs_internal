#pragma once
#include <Windows.h>
#include <iostream>
#include <string>
#include <cstdint>
#include <algorithm>
#include <iomanip>
#include <list>
#include <sstream>
#include <mutex>

#include "../utils/utils.h"

#include "other/color.h"
#include "other/math.h"
#include "other/array.h"
#include "other/string.h"
#include "other/view_info.h"

#include "unreal/name_pool/name_pool.h"
#include "unreal/object_array/object_array.h"
#include "unreal/world/world.h"

#include "unreal/actor/actor.h"
#include "unreal/controller/controller.h"
#include "unreal/player_controller/player_controller.h"
#include "unreal/pawn/pawn.h"
#include "unreal/level/level.h"
#include "unreal/game_instance/game_instance.h"
#include "unreal/player/player.h"
#include "unreal/player_state/player_state.h"
#include "unreal/skeletal_mesh_component/skeletal_mesh_component.h"
#include "unreal/scene_component/scene_component.h"
#include "unreal/game_state_base/game_state_base.h"
#include "unreal/field/field.h"
#include "unreal/struct/struct.h"
#include "unreal/class/class.h"
#include "unreal/canvas/canvas.h"
#include "unreal/base_char/base_char.h"

namespace sdk {
	inline std::uintptr_t get_viewpoint;
	inline std::uintptr_t get_bone_matrix;

	inline u_object* font;

	// killers
	inline u_object* werewolf_bp;
	inline u_object* toad_bp;
	inline u_object* doll_minion_bp;
	inline u_object* doll_master_bp;

	// survivors
	inline u_object* cheerleader_bp;
	inline u_object* jock_bp;
	inline u_object* outsider_bp;
	inline u_object* punk_bp;
	inline u_object* virgin_bp;

	// props
	inline u_object* lockbox_bp;
	inline u_object* noisemaker_bp;
	inline u_object* pills_bp;
	inline u_object* adrenaline_bp;
	inline u_object* walkie_bp;
	inline u_object* vending_machine_bp;
	inline u_object* basket_bp;
	inline u_object* station_base_bp;
	inline u_object* flamethrower_bp;
	inline u_object* molotov_bp;
	inline u_object* ray_gun_bp;
	inline u_object* cross_bp;
	inline u_object* sword_bp;
	inline u_object* magic_sphere_bp;
	inline u_object* life_essence_bp;
	inline u_object* medkit_point_bp;

	bool initialize();
	void process_event(void* object, void* u_function, void* params);
}