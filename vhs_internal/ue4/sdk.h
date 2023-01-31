#pragma once

namespace ue4::core_object {
	class u_object;
}

namespace ue4::sdk {

	// view_point
	inline std::uintptr_t view_point;

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
	inline ue4::core_object::u_object* enable_input;
	inline ue4::core_object::u_object* disable_input;

	// u_skeletal_mesh_component
	inline std::uintptr_t bone_matrix;
	inline ue4::core_object::u_object* get_bone_name;
	inline ue4::core_object::u_object* get_bones_num;

	// a_pawn
	inline ue4::core_object::u_object* get_spectral;
	inline ue4::core_object::u_object* get_equipped_weapon;

	// a_station_base
	inline ue4::core_object::u_object* get_crafting_percent;
	inline ue4::core_object::u_object* get_crafting_weapon_type;

	// a_minigame_base
	inline ue4::core_object::u_object* get_current_value;
	inline ue4::core_object::u_object* get_target_value;
	inline ue4::core_object::u_object* submit_value;

	// monsters
	inline ue4::core_object::u_object* werewolf;
	inline ue4::core_object::u_object* wart;
	inline ue4::core_object::u_object* doll_master;
	inline ue4::core_object::u_object* doll_minion;
	inline ue4::core_object::u_object* deathwire;

	// teens
	inline ue4::core_object::u_object* cheerleader;
	inline ue4::core_object::u_object* jock;
	inline ue4::core_object::u_object* outsider;
	inline ue4::core_object::u_object* punk;
	inline ue4::core_object::u_object* virgin;
	inline ue4::core_object::u_object* free_spirit;

	// items
	inline ue4::core_object::u_object* lockbox;
	inline ue4::core_object::u_object* noisemaker;
	inline ue4::core_object::u_object* pills;
	inline ue4::core_object::u_object* adrenaline;
	inline ue4::core_object::u_object* walkie;
	inline ue4::core_object::u_object* vending;
	inline ue4::core_object::u_object* basket;
	inline ue4::core_object::u_object* station_base;
	inline ue4::core_object::u_object* life_essence;
	inline ue4::core_object::u_object* medkit;
	inline ue4::core_object::u_object* trap;

	bool initialize();

	void process_event(void* object, void* u_function, void* params);
}
