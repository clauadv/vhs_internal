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

void ue4::game_framework::a_actor::enable_input(ue4::game_framework::a_player_controller* player_controller) {
	struct {
		ue4::game_framework::a_player_controller* player_controller;
	} params{};

	params.player_controller = player_controller;

	const auto flags = ue4::sdk::enable_input->flags;
	ue4::sdk::enable_input->flags |= 0x00000400;

	ue4::sdk::process_event(this, ue4::sdk::enable_input, &params);
	ue4::sdk::enable_input->flags = flags;
}

void ue4::game_framework::a_actor::disable_input(ue4::game_framework::a_player_controller* player_controller) {
	struct {
		ue4::game_framework::a_player_controller* player_controller;
	} params{};

	params.player_controller = player_controller;

	const auto flags = ue4::sdk::disable_input->flags;
	ue4::sdk::disable_input->flags |= 0x00000400;

	ue4::sdk::process_event(this, ue4::sdk::disable_input, &params);
	ue4::sdk::disable_input->flags = flags;
}

std::tuple<ue4::containers::f_string, ue4::math::color, float> ue4::game_framework::a_actor::get_actor_info(ue4::game_framework::a_pawn* my_player) {

	// monsters
	{
		const auto color = ue4::math::color{
			variables::players::monster_color[0],
			variables::players::monster_color[1],
			variables::players::monster_color[2],
			variables::players::monster_color[3]
		};

		if (this->is_a(ue4::sdk::werewolf))
			return { L"werewolf", color, 0.f };
		if (this->is_a(ue4::sdk::wart))
			return { L"wart", color, 0.f };
		if (this->is_a(ue4::sdk::doll_master))
			return { L"doll master", color, 0.f };
		if (this->is_a(ue4::sdk::doll_minion))
			return { L"doll minion", color, 0.f };
		if (this->is_a(ue4::sdk::deathwire))
			return { L"deathwire", color, 0.f };
	}

	// teens
	{
		const auto color = ue4::math::color{
			variables::players::teen_color[0],
			variables::players::teen_color[1],
			variables::players::teen_color[2],
			variables::players::teen_color[3]
		};

		if (this->is_a(ue4::sdk::cheerleader))
			return { L"gloria", color, 0.f };
		if (this->is_a(ue4::sdk::jock))
			return { L"brett", color, 0.f };
		if (this->is_a(ue4::sdk::outsider))
			return { L"jess", color, 0.f };
		if (this->is_a(ue4::sdk::punk))
			return { L"leo", color, 0.f };
		if (this->is_a(ue4::sdk::virgin))
			return { L"faith", color, 0.f };
		if (this->is_a(ue4::sdk::free_spirit))
			return { L"spirit", color, 0.f };
	}

	// entities
	{
		if (this->is_a(ue4::sdk::lockbox) && variables::entities::lockbox) {
			const auto color = ue4::math::color{
				variables::entities::lockbox_color[0],
				variables::entities::lockbox_color[1],
				variables::entities::lockbox_color[2],
				variables::entities::lockbox_color[3]
			};

			return { L"lockbox", color, variables::entities::max_distance };
		}

		if (this->is_a(ue4::sdk::noisemaker) && variables::entities::noisemaker) {
			const auto color = ue4::math::color{
				variables::entities::noisemaker_color[0],
				variables::entities::noisemaker_color[1],
				variables::entities::noisemaker_color[2],
				variables::entities::noisemaker_color[3]
			};

			return { L"noisemaker", color, variables::entities::max_distance };
		}

		if (this->is_a(ue4::sdk::pills) && variables::entities::pills) {
			const auto color = ue4::math::color{
				variables::entities::pills_color[0],
				variables::entities::pills_color[1],
				variables::entities::pills_color[2],
				variables::entities::pills_color[3]
			};

			return { L"candy", color, variables::entities::max_distance };
		}

		if (this->is_a(ue4::sdk::adrenaline) && variables::entities::adrenaline) {
			const auto color = ue4::math::color{
				variables::entities::adrenaline_color[0],
				variables::entities::adrenaline_color[1],
				variables::entities::adrenaline_color[2],
				variables::entities::adrenaline_color[3]
			};

			return { L"can", color, variables::entities::max_distance };
		}

		if (this->is_a(ue4::sdk::walkie) && variables::entities::walkie) {
			const auto color = ue4::math::color{
				variables::entities::walkie_color[0],
				variables::entities::walkie_color[1],
				variables::entities::walkie_color[2],
				variables::entities::walkie_color[3]
			};

			return { L"walkie", color, variables::entities::max_distance };
		}

		if (this->is_a(ue4::sdk::vending) && variables::entities::vending) {
			const auto color = ue4::math::color{
				variables::entities::vending_color[0],
				variables::entities::vending_color[1],
				variables::entities::vending_color[2],
				variables::entities::vending_color[3]
			};

			return { L"vending", color, variables::entities::max_distance };
		}

		if (this->is_a(ue4::sdk::basket) && variables::entities::basket) {
			const auto color = ue4::math::color{
				variables::entities::basket_color[0],
				variables::entities::basket_color[1],
				variables::entities::basket_color[2],
				variables::entities::basket_color[3]
			};

			return { L"trashbox", color, variables::entities::max_distance };
		}

		if (this->is_a(ue4::sdk::station_base) && variables::entities::station) {
			const auto station_name = reinterpret_cast<vhs::station::a_station_base*>(this)->get_station_name();
			const auto percent = reinterpret_cast<vhs::station::a_station_base*>(this)->get_crafting_percent(my_player->player_state, my_player, reinterpret_cast<vhs::station::a_station_base*>(this)->get_station_weapon_type());
			const auto distance = my_player->get_distance_to_string(this);

			std::wstring name;
			name.append(station_name.first.c_str()).append(L" - ").append(percent).append(L"%");

			return { name.c_str(), station_name.second, variables::entities::max_distance };
		}

		if ((this->is_a(ue4::sdk::life_essence) && my_player->get_spectral()) && variables::entities::life_essence) {
			const auto color = ue4::math::color{
				variables::entities::life_essence_color[0],
				variables::entities::life_essence_color[1],
				variables::entities::life_essence_color[2],
				variables::entities::life_essence_color[3]
			};

			return { L"luma", color, variables::entities::max_distance };
		}

		if (this->is_a(ue4::sdk::medkit) && variables::entities::medkit) {
			const auto color = ue4::math::color{
				variables::entities::medkit_color[0],
				variables::entities::medkit_color[1],
				variables::entities::medkit_color[2],
				variables::entities::medkit_color[3]
			};

			return { L"medkit", color, variables::entities::max_distance };
		}

		if (this->is_a(ue4::sdk::trap) && variables::entities::trap) {
			const auto color = ue4::math::color{
				variables::entities::trap_color[0],
				variables::entities::trap_color[1],
				variables::entities::trap_color[2],
				variables::entities::trap_color[3]
			};

			return { L"trap", color, variables::entities::max_distance };
		}
	}

	return { L"none", { 0.f, 0.f, 0.f, 0.f }, 0.f };
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
		this->is_a(ue4::sdk::doll_master) || this->is_a(ue4::sdk::doll_minion) ||
		this->is_a(ue4::sdk::deathwire)) {

		return true;
	}

	return false;
}