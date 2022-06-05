#pragma once

namespace ue4::core_object {
	class u_object;
}

namespace ue4::sdk {
	// u_canvas
	inline ue4::core_object::u_object* font;
	inline ue4::core_object::u_object* draw_box;
	inline ue4::core_object::u_object* draw_line;
	inline ue4::core_object::u_object* draw_text;
	inline ue4::core_object::u_object* draw_polygon;
	inline ue4::core_object::u_object* text_size;

	// a_player_controller
	inline ue4::core_object::u_object* world_to_screen;

	// a_actor
	inline ue4::core_object::u_object* get_actor_location;
	inline ue4::core_object::u_object* get_actor_rotation;
	inline ue4::core_object::u_object* get_actor_bounds;
	inline ue4::core_object::u_object* get_distance_to;

	// u_skeletal_mesh_component
	inline std::uintptr_t bone_matrix;
	inline ue4::core_object::u_object* get_bone_name;

	// camera
	inline std::uintptr_t view_point;

	// killers
	inline ue4::core_object::u_object* werewolf;
	inline ue4::core_object::u_object* toad;
	inline ue4::core_object::u_object* doll_master;
	inline ue4::core_object::u_object* doll_minion;

	// survivors
	inline ue4::core_object::u_object* cheerleader;
	inline ue4::core_object::u_object* jock;
	inline ue4::core_object::u_object* outsider;
	inline ue4::core_object::u_object* punk;
	inline ue4::core_object::u_object* virgin;

	// items
	inline ue4::core_object::u_object* lockbox;
	inline ue4::core_object::u_object* noisemaker;
	inline ue4::core_object::u_object* pills;
	inline ue4::core_object::u_object* adrenaline;
	inline ue4::core_object::u_object* walkie;
	inline ue4::core_object::u_object* vending_machine;
	inline ue4::core_object::u_object* basket;
	inline ue4::core_object::u_object* station_base;
	inline ue4::core_object::u_object* flamethrower;
	inline ue4::core_object::u_object* molotov;
	inline ue4::core_object::u_object* ray_gun;
	inline ue4::core_object::u_object* cross;
	inline ue4::core_object::u_object* sword;
	inline ue4::core_object::u_object* magic_sphere;
	inline ue4::core_object::u_object* life_essence;
	inline ue4::core_object::u_object* medkit;
	inline ue4::core_object::u_object* trap;

	bool initialize();

	void process_event(void* object, void* u_function, void* params);
}
