#include <includes.h>
#include "hooks/hooks.h"

bool ue4::sdk::initialize() {
	const auto main = reinterpret_cast<std::uintptr_t>(LI_FN(GetModuleHandleA)(nullptr));
	if (!main) return false;

	ue4::core_object::names = reinterpret_cast<decltype(ue4::core_object::names)>(utils::pattern_scan(main, _("48 8D 05 ? ? ? ? EB 13 48 8D 0D ? ? ? ? E8 ? ? ? ? C6 05 ? ? ? ? ? 0F 10"), true));
	if (!ue4::core_object::names) throw std::runtime_error(_("failed to get ue4::core_object::names"));

	ue4::core_object::objects = reinterpret_cast<decltype(ue4::core_object::objects)>(utils::pattern_scan(main, _("48 8B 05 ? ? ? ? 48 8B 0C C8 4C 8D 04 D1 EB 03"), true));
	if (!ue4::core_object::objects) throw std::runtime_error(_("failed to get ue4::core_object::objects"));

	ue4::engine::world = reinterpret_cast<decltype(ue4::engine::world)>(utils::pattern_scan(main, _("48 8B 1D ? ? ? ? 48 85 DB 74 3B 41 B0 01 33 D2 48 8B CB E8"), true));
	if (!ue4::engine::world) throw std::runtime_error(_("failed to get ue4::engine::world"));

	ue4::sdk::bone_matrix = utils::pattern_scan(main, _("48 8B C4 48 89 58 08 48 89 70 10 57 48 81 EC ? ? ? ? F6"));
	if (!sdk::bone_matrix) throw std::runtime_error(_("failed to get ue4::sdk::bone_matrix"));

	ue4::sdk::view_point = utils::pattern_scan(main, _("4C 8B DC 53 55 56 57 48 81 EC ? ? ? ? 48 8B 05 ? ? ? ? 48 33 C4 48 89 84 24 ? ? ? ? 4D 89 7B D8"));
	if (!sdk::view_point) throw std::runtime_error(_("failed to get ue4::sdk::view_point"));

	// u_canvas
	ue4::sdk::font = ue4::core_object::objects->find(_("Font Roboto.Roboto"));
	ue4::sdk::draw_box = ue4::core_object::objects->find(_("Function Engine.Canvas.K2_DrawBox"));
	ue4::sdk::draw_line = ue4::core_object::objects->find(_("Function Engine.Canvas.K2_DrawLine"));
	ue4::sdk::draw_text = ue4::core_object::objects->find(_("Function Engine.Canvas.K2_DrawText"));
	ue4::sdk::draw_polygon = ue4::core_object::objects->find(_("Function Engine.Canvas.K2_DrawPolygon"));
	ue4::sdk::text_size = ue4::core_object::objects->find(_("Function Engine.Canvas.K2_TextSize"));

	// a_player_controller
	ue4::sdk::world_to_screen = ue4::core_object::objects->find(_("Function Engine.PlayerController.ProjectWorldLocationToScreen"));

	// a_actor
	ue4::sdk::get_actor_location = ue4::core_object::objects->find(_("Function Engine.Actor.K2_GetActorLocation"));
	ue4::sdk::get_actor_rotation = ue4::core_object::objects->find(_("Function Engine.Actor.K2_GetActorRotation"));
	ue4::sdk::get_actor_bounds = ue4::core_object::objects->find(_("Function Engine.Actor.GetActorBounds"));
	ue4::sdk::get_distance_to = ue4::core_object::objects->find(_("Function Engine.Actor.GetDistanceTo"));

	// u_skeletal_mesh_component
	ue4::sdk::get_bone_name = ue4::core_object::objects->find(_("Function Engine.SkinnedMeshComponent.GetBoneName"));

	// killers
	ue4::sdk::werewolf = ue4::core_object::objects->find(_("BlueprintGeneratedClass Werewolf_BP.Werewolf_BP_C"));
	ue4::sdk::toad = ue4::core_object::objects->find(_("BlueprintGeneratedClass Toad_BP.Toad_BP_C"));
	ue4::sdk::doll_master = ue4::core_object::objects->find(_("BlueprintGeneratedClass DollMaster_BP.DollMaster_BP_C"));
	ue4::sdk::doll_minion = ue4::core_object::objects->find(_("BlueprintGeneratedClass DollMinion_BP.DollMinion_BP_C"));

	// survivors
	ue4::sdk::cheerleader = ue4::core_object::objects->find(_("BlueprintGeneratedClass Cheerleader_BP.Cheerleader_BP_C"));
	ue4::sdk::jock = ue4::core_object::objects->find(_("BlueprintGeneratedClass Jock_BP.Jock_BP_C"));
	ue4::sdk::outsider = ue4::core_object::objects->find(_("BlueprintGeneratedClass Outsider_BP.Outsider_BP_C"));
	ue4::sdk::punk = ue4::core_object::objects->find(_("BlueprintGeneratedClass Punk_BP.Punk_BP_C"));
	ue4::sdk::virgin = ue4::core_object::objects->find(_("BlueprintGeneratedClass Virgin_BP.Virgin_BP_C"));

	// items
	ue4::sdk::lockbox = ue4::core_object::objects->find(_("Class Game.SearchableLockbox"));
	ue4::sdk::noisemaker = ue4::core_object::objects->find(_("Class Game.NoisemakerPickup"));
	ue4::sdk::pills = ue4::core_object::objects->find(_("Class Game.PillsPickup"));
	ue4::sdk::adrenaline = ue4::core_object::objects->find(_("BlueprintGeneratedClass AdrenalinePickup_BP.AdrenalinePickup_BP_C"));
	ue4::sdk::walkie = ue4::core_object::objects->find(_("BlueprintGeneratedClass WalkiePickup_BP.WalkiePickup_BP_C"));
	ue4::sdk::vending_machine = ue4::core_object::objects->find(_("Class Game.SearchableVendingMachine"));
	ue4::sdk::basket = ue4::core_object::objects->find(_("Class Game.SearchableWasteBasket"));
	ue4::sdk::station_base = ue4::core_object::objects->find(_("Class Game.StationBase"));
	ue4::sdk::flamethrower = ue4::core_object::objects->find(_("Class Game.FlamethrowerWeapon"));
	ue4::sdk::molotov = ue4::core_object::objects->find(_("Class Game.MolotovWeapon"));
	ue4::sdk::ray_gun = ue4::core_object::objects->find(_("Class Game.RayGunWeapon"));
	ue4::sdk::cross = ue4::core_object::objects->find(_("Class Game.CrossWeapon"));
	ue4::sdk::sword = ue4::core_object::objects->find(_("Class Game.DemonSwordWeapon"));
	ue4::sdk::magic_sphere = ue4::core_object::objects->find(_("Class Game.MagicSphere"));
	ue4::sdk::life_essence = ue4::core_object::objects->find(_("Class Game.LifeEssencePowerup"));
	ue4::sdk::medkit = ue4::core_object::objects->find(_("Class Game.MedKitPoint"));
	ue4::sdk::trap = ue4::core_object::objects->find(_("BlueprintGeneratedClass DollMasterTrap_BP.DollMasterTrap_BP_C"));

	hooks::initialize();

	return true;
}
