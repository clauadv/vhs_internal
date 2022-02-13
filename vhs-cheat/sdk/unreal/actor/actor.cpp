#include <pch.h>

struct sdk::vector sdk::a_actor::get_location() {
	static const auto fn = sdk::object_array->find_object(_("Function Engine.Actor.K2_GetActorLocation"));
	if (!fn) return {};

	struct {
		struct sdk::vector return_value;
	} params{};

	sdk::process_event(this, fn, &params);

	return params.return_value;
}

sdk::rotator sdk::a_actor::get_rotation() {
	static const auto fn = sdk::object_array->find_object(_("Function Engine.Actor.K2_GetActorRotation"));
	if (!fn) return {};

	struct {
		sdk::rotator return_value;
	} params{};

	const auto flags = fn->flags;
	fn->flags |= 0x00000400;

	sdk::process_event(this, fn, &params);
	fn->flags = flags;


	return params.return_value;
}

void sdk::a_actor::get_bounds(const bool only_colliding_components, sdk::vector* origin, sdk::vector* extent) {
	static const auto fn = sdk::object_array->find_object(_("Function Engine.Actor.GetActorBounds"));
	if (!fn) return;

	struct {
		bool only_colliding_components;
		struct sdk::vector origin;
		struct sdk::vector extent;
	} params{};

	params.only_colliding_components = only_colliding_components;

	sdk::process_event(this, fn, &params);

	if (origin != nullptr)
		*origin = params.origin;

	if (extent != nullptr)
		*extent = params.extent;
}

float sdk::a_actor::get_distance_to(sdk::a_actor* actor) {
	static const auto fn = sdk::object_array->find_object(_("Function Engine.Actor.GetDistanceTo"));
	if (!fn) return {};

	struct {
		sdk::a_actor* actor;
		float return_value;
	} params{};

	params.actor = actor;

	sdk::process_event(this, fn, &params);

	return params.return_value;
}

std::wstring sdk::a_actor::get_distance_to_string(sdk::a_actor* actor) {
	const auto distance = this->get_distance_to(actor);
	const auto meters = distance * 0.01f;

	std::wstringstream ss;
	if (meters < 1000.f) {
		ss << std::fixed << std::setprecision(0) << meters << "m";

	} else {
		ss.precision(3);
		ss << std::fixed << std::setprecision(0) << (meters / 1000.f) << "km";
	}

	return ss.str();
}

std::pair<sdk::u_string, sdk::color> sdk::a_actor::get_character_name() const {
	if (this->is_a(sdk::werewolf_bp))
		return { L"werewolf", { 255, 0, 0, 255} };
	if (this->is_a(sdk::toad_bp))
		return { L"wart", { 255, 0, 0, 255} };
	if (this->is_a(sdk::doll_master_bp))
		return { L"doll_master", { 255, 0, 0, 255} };
	if (this->is_a(sdk::doll_minion_bp))
		return { L"doll_minion", { 255, 0, 0, 255} };

	if (this->is_a(sdk::cheerleader_bp))
		return { L"gloria", { 255, 255, 255, 255} };
	if (this->is_a(sdk::jock_bp))
		return { L"brett", { 255, 255, 255, 255} };
	if (this->is_a(sdk::outsider_bp))
		return { L"jess", { 255, 255, 255, 255} };
	if (this->is_a(sdk::punk_bp))
		return { L"leo", { 255, 255, 255, 255} };
	if (this->is_a(sdk::virgin_bp))
		return { L"faith", { 255, 255, 255, 255} };

	if (this->is_a(sdk::lockbox_bp))
		return { L"lockbox", { 52, 134, 235, 255} };
	if (this->is_a(sdk::noisemaker_bp))
		return { L"noise_maker", { 52, 134, 235, 255} };
	if (this->is_a(sdk::pills_bp))
		return { L"candy_bar", { 52, 134, 235, 255} };
	if (this->is_a(sdk::adrenaline_bp))
		return { L"pop_can", { 52, 134, 235, 255} };
	if (this->is_a(sdk::walkie_bp))
		return { L"walkie_talkie", { 52, 134, 235, 255} };
	if (this->is_a(sdk::vending_machine_bp))
		return { L"vending_machine", { 52, 134, 235, 255} };
	if (this->is_a(sdk::basket_bp))
		return { L"trashbox", { 52, 134, 235, 255} };
	if (this->is_a(sdk::station_base_bp))
		return { L"station_base", { 52, 134, 235, 255} };
	if (this->is_a(sdk::flamethrower_bp))
		return { L"flamethrower", { 52, 134, 235, 255} };
	if (this->is_a(sdk::molotov_bp))
		return { L"molotov", { 52, 134, 235, 255} };
	if (this->is_a(sdk::ray_gun_bp))
		return { L"ray_gun", { 52, 134, 235, 255} };
	if (this->is_a(sdk::cross_bp))
		return { L"cross", { 52, 134, 235, 255} };
	if (this->is_a(sdk::sword_bp))
		return { L"sword", { 52, 134, 235, 255} };
	if (this->is_a(sdk::magic_sphere_bp))
		return { L"eyeball", { 52, 134, 235, 255} };
	if (this->is_a(sdk::life_essence_bp))
		return { L"luma", { 52, 134, 235, 255} };
	if (this->is_a(sdk::medkit_point_bp))
		return { L"healing_station", { 52, 134, 235, 255} };
	if (this->is_a(sdk::doll_master_trap_bp))
		return { L"trap", { 255, 0, 0, 255} };

	return { L"", { 0, 0, 0, 0 } };
}