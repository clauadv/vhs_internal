#include "sdk.h"
#include "../hooks/hooks.h"

namespace sdk {
	bool sdk::a_player_controller::world_to_screen(const sdk::vector& world, sdk::vector_2d& screen) {
		static const auto fn = sdk::object_array->find_object(_("Function Engine.PlayerController.ProjectWorldLocationToScreen"));
		if (!fn) return false;

		struct {
			vector world;
			vector_2d screen;
			bool player_viewport_relative;
			bool return_value;
		} params{};

		params.world = world;
		params.screen = screen;
		params.player_viewport_relative = false;

		sdk::process_event(this, fn, &params);

		screen = params.screen;

		return params.return_value;
	}

	bool initialize() {
		const auto main = reinterpret_cast<std::uintptr_t>(LI_FN(GetModuleHandleA)(nullptr));
		if (!main) return false;

		sdk::name_pool = reinterpret_cast<decltype(sdk::name_pool)>(utils::pattern_scan(main, _("48 8D 05 ? ? ? ? EB 13 48 8D 0D ? ? ? ? E8 ? ? ? ? C6 05 ? ? ? ? ? 0F 10"), true));
		if (!sdk::name_pool) return false;

		sdk::object_array = reinterpret_cast<decltype(sdk::object_array)>(utils::pattern_scan(main, _("48 8B 05 ? ? ? ? 48 8B 0C C8 4C 8D 04 D1 EB"), true));
		if (!sdk::object_array) return false;

		sdk::world = reinterpret_cast<decltype(sdk::world)>(utils::pattern_scan(main, _("48 8B 1D ? ? ? ? 48 85 DB 74 3B 41 B0 01 33 D2 48 8B CB E8"), true));
		if (!sdk::world) return false;

		sdk::get_bone_matrix = utils::pattern_scan(main, "48 8B C4 48 89 58 08 48 89 70 10 57 48 81 EC ? ? ? ? F6");
		if (!sdk::get_bone_matrix) return false;

		sdk::get_viewpoint = utils::pattern_scan(main, "4C 8B DC 53 55 56 57 48 81 EC ? ? ? ? 48 8B 05 ? ? ? ? 48 33 C4 48 89 84 24 ? ? ? ? 4D 89 7B D8");
		if (!sdk::get_viewpoint) return false;

		sdk::font = sdk::object_array->find_object(_("Font Roboto.Roboto"));

		// killers
		sdk::werewolf_bp = sdk::object_array->find_object(_("BlueprintGeneratedClass Werewolf_BP.Werewolf_BP_C"));
		sdk::toad_bp = sdk::object_array->find_object(_("BlueprintGeneratedClass Toad_BP.Toad_BP_C"));
		sdk::doll_master_bp = sdk::object_array->find_object(_("BlueprintGeneratedClass DollMaster_BP.DollMaster_BP_C"));
		sdk::doll_minion_bp = sdk::object_array->find_object(_("BlueprintGeneratedClass DollMinion_BP.DollMinion_BP_C"));

		// survivors
		sdk::cheerleader_bp = sdk::object_array->find_object(_("BlueprintGeneratedClass Cheerleader_BP.Cheerleader_BP_C"));
		sdk::jock_bp = sdk::object_array->find_object(_("BlueprintGeneratedClass Jock_BP.Jock_BP_C"));
		sdk::outsider_bp = sdk::object_array->find_object(_("BlueprintGeneratedClass Outsider_BP.Outsider_BP_C"));
		sdk::punk_bp = sdk::object_array->find_object(_("BlueprintGeneratedClass Punk_BP.Punk_BP_C"));
		sdk::virgin_bp = sdk::object_array->find_object(_("BlueprintGeneratedClass Virgin_BP.Virgin_BP_C"));
		
		// props
		sdk::lockbox_bp = sdk::object_array->find_object(_("Class Game.SearchableLockbox"));
		sdk::noisemaker_bp = sdk::object_array->find_object(_("Class Game.NoisemakerPickup"));
		sdk::pills_bp = sdk::object_array->find_object(_("Class Game.PillsPickup"));
		sdk::adrenaline_bp = sdk::object_array->find_object(_("BlueprintGeneratedClass AdrenalinePickup_BP.AdrenalinePickup_BP_C"));
		sdk::walkie_bp = sdk::object_array->find_object(_("BlueprintGeneratedClass WalkiePickup_BP.WalkiePickup_BP_C"));
		sdk::vending_machine_bp = sdk::object_array->find_object(_("Class Game.SearchableVendingMachine"));
		sdk::basket_bp = sdk::object_array->find_object(_("Class Game.SearchableWasteBasket"));
		sdk::station_base_bp = sdk::object_array->find_object(_("Class Game.StationBase"));
		sdk::flamethrower_bp = sdk::object_array->find_object(_("Class Game.FlamethrowerWeapon"));
		sdk::molotov_bp = sdk::object_array->find_object(_("Class Game.MolotovWeapon"));
		sdk::ray_gun_bp = sdk::object_array->find_object(_("Class Game.RayGunWeapon"));
		sdk::cross_bp = sdk::object_array->find_object(_("Class Game.CrossWeapon"));
		sdk::sword_bp = sdk::object_array->find_object(_("Class Game.DemonSwordWeapon"));
		sdk::magic_sphere_bp = sdk::object_array->find_object(_("Class Game.MagicSphere"));
		sdk::life_essence_bp = sdk::object_array->find_object(_("Class Game.LifeEssencePowerup"));
		sdk::medkit_point_bp = sdk::object_array->find_object(_("Class Game.MedKitPoint"));
		sdk::doll_master_trap_bp = sdk::object_array->find_object(_("BlueprintGeneratedClass DollMasterTrap_BP.DollMasterTrap_BP_C"));

		hooks::initialize();

		return true;
	}
}
