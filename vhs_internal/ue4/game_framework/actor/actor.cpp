#include <includes.h>

ue4::math::vector ue4::game_framework::a_actor::get_location() {
	struct {
		ue4::math::vector return_value;
	} params{};

	ue4::sdk::process_event(this, ue4::sdk::get_actor_location, &params);

	return params.return_value;
}

ue4::math::rotator ue4::game_framework::a_actor::get_rotation() {
	struct {
		ue4::math::rotator return_value;
	} params{};

	const auto flags = ue4::sdk::get_actor_rotation->flags;
	ue4::sdk::get_actor_rotation->flags |= 0x00000400;

	ue4::sdk::process_event(this, ue4::sdk::get_actor_rotation, &params);
	ue4::sdk::get_actor_rotation->flags = flags;

	return params.return_value;
}

void ue4::game_framework::a_actor::get_bounds(const bool only_colliding_components, ue4::math::vector* origin, ue4::math::vector* extent) {
	struct {
		bool only_colliding_components;
		ue4::math::vector origin;
		ue4::math::vector extent;
	} params{};

	params.only_colliding_components = only_colliding_components;

	ue4::sdk::process_event(this, ue4::sdk::get_actor_bounds, &params);

	if (origin != nullptr)
		*origin = params.origin;

	if (extent != nullptr)
		*extent = params.extent;
}

float ue4::game_framework::a_actor::get_distance_to(ue4::game_framework::a_actor* actor) {
	struct {
		ue4::game_framework::a_actor* actor;
		float return_value;
	} params{};

	params.actor = actor;

	ue4::sdk::process_event(this, ue4::sdk::get_distance_to, &params);

	return params.return_value;
}

std::wstring ue4::game_framework::a_actor::get_distance_to_string(ue4::game_framework::a_actor* actor) {
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

std::tuple<ue4::containers::f_string, ue4::math::color, float> ue4::game_framework::a_actor::get_actor_info(ue4::game_framework::a_pawn* my_player) {
	if (this->is_a(sdk::werewolf))
		return { L"werewolf", { 1.f, 0.f, 0.f, 1.f}, 0.f };
	if (this->is_a(sdk::wart))
		return { L"wart", { 1.f, 0.f, 0.f, 1.f}, 0.f };
	if (this->is_a(sdk::doll_master))
		return { L"doll_master", { 1.f, 0.f, 0.f, 1.f}, 0.f };
	if (this->is_a(sdk::doll_minion))
		return { L"doll_minion", { 1.f, 0.f, 0.f, 1.f}, 0.f };

	if (this->is_a(sdk::cheerleader))
		return { L"gloria", { 1.f, 1.f, 1.f, 1.f}, 0.f };
	if (this->is_a(sdk::jock))
		return { L"brett", { 1.f, 1.f, 1.f, 1.f}, 0.f };
	if (this->is_a(sdk::outsider))
		return { L"jess", { 1.f, 1.f, 1.f, 1.f}, 0.f };
	if (this->is_a(sdk::punk))
		return { L"leo", { 1.f, 1.f, 1.f, 1.f}, 0.f };
	if (this->is_a(sdk::virgin))
		return { L"faith", { 1.f, 1.f, 1.f, 1.f}, 0.f };

	if (this->is_a(sdk::lockbox))
		return { L"lockbox", { 0.20f, 0.52f, 0.92f, 1.f }, 50.f };
	if (this->is_a(sdk::noisemaker))
		return { L"noise_maker", { 0.20f, 0.52f, 0.92f, 1.f}, 30.f };
	if (this->is_a(sdk::pills))
		return { L"candy_bar", { 0.20f, 0.52f, 0.92f, 1.f}, 30.f };
	if (this->is_a(sdk::adrenaline))
		return { L"pop_can", { 0.20f, 0.52f, 0.92f, 1.f}, 30.f };
	if (this->is_a(sdk::walkie))
		return { L"walkie_talkie", { 0.20f, 0.52f, 0.92f, 1.f}, 30.f };
	if (this->is_a(sdk::vending_machine))
		return { L"vending_machine", { 0.71f, 0.27f, 0.92f, 1.f}, 30.f };
	if (this->is_a(sdk::basket))
		return { L"trashbox", { 0.20f, 0.52f, 0.92f, 1.f}, 30.f };
	if (this->is_a(sdk::life_essence))
		return { L"luma", { 0.20f, 0.52f, 0.92f, 1.f}, 30.f };
	if (this->is_a(sdk::medkit))
		return { L"healing_station", { 0.71f, 0.27f, 0.92f, 1.f}, 30.f };
	if (this->is_a(sdk::trap))
		return { L"trap", { 1.f, 0.f, 0.f, 1.f}, 30.f };

	if (this->is_a(sdk::station_base)) {
		const auto station_name = reinterpret_cast<vhs::station::a_station_base*>(this)->get_station_name();
		const auto percent = reinterpret_cast<vhs::station::a_station_base*>(this)->get_crafting_percent(my_player->player_state, my_player, reinterpret_cast<vhs::station::a_station_base*>(this)->get_station_weapon_type());
		const auto distance = my_player->get_distance_to_string(this);

		std::wstring name;
		name.append(station_name.first.c_str()).append(L" [").append(percent).append(L"%]");

		return { name.c_str(), station_name.second, 100.f };
	}

	return { L"none", { 0.f, 0.f, 0.f, 1.f }, 0.f };
}

bool ue4::game_framework::a_actor::is_teen() {
	if (this->is_a(ue4::sdk::cheerleader) || this->is_a(ue4::sdk::jock) || this->is_a(ue4::sdk::outsider) ||
		this->is_a(ue4::sdk::punk) || this->is_a(ue4::sdk::virgin)) {

		return true;
	}

	return false;
}

bool ue4::game_framework::a_actor::is_monster() {
	if (this->is_a(ue4::sdk::werewolf) || this->is_a(ue4::sdk::wart) ||
		this->is_a(ue4::sdk::doll_master) || this->is_a(ue4::sdk::doll_minion)) {

		return true;
	}

	return false;
}