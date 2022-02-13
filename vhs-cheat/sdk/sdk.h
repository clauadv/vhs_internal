#pragma once

namespace sdk {
	struct u_object;
	struct u_object_array;

	inline std::uintptr_t get_viewpoint;
	inline std::uintptr_t get_bone_matrix;

	inline u_object* font;

	// killers
	inline u_object* werewolf_bp;
	inline u_object* toad_bp;
	inline u_object* doll_master_bp;
	inline u_object* doll_minion_bp;

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
	inline u_object* doll_master_trap_bp;

	bool initialize();
	void process_event(void* object, void* u_function, void* params);
}