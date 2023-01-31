#include <includes.h>

std::pair<ue4::containers::f_string, ue4::math::color> vhs::weapon::a_weapon_base::get_weapon_name() {
	const auto burn_color = ue4::math::color{ 0.89f, 0.56f, 0.07f, 1.f };
	const auto holy_color = ue4::math::color{ 0.89f, 0.88f, 0.25f, 1.f };
	const auto occult_color = ue4::math::color{ 0.76f, 0.24f, 0.87f, 1.f };
	const auto shock_color = ue4::math::color{ 0.20f, 0.80f, 0.86f, 1.f };

	if (this->type == vhs::weapon::weapon_type::cross)
		return { L"cross", holy_color };

	if (this->type == vhs::weapon::weapon_type::holy_slingshot)
		return { L"slingshot", holy_color };

	if (this->type == vhs::weapon::weapon_type::parchment)
		return { L"parchment", occult_color };

	if (this->type == vhs::weapon::weapon_type::talisman)
		return { L"talisman", occult_color };

	if (this->type == vhs::weapon::weapon_type::molotov)
		return { L"molotov", burn_color };

	if (this->type == vhs::weapon::weapon_type::flamethrower)
		return { L"flamethrower", burn_color };

	if (this->type == vhs::weapon::weapon_type::rc_copter)
		return { L"rc copter", shock_color };

	if (this->type == vhs::weapon::weapon_type::static_shield)
		return { L"static shield", shock_color };

	if (this->type == vhs::weapon::weapon_type::ray_gun)
		return { L"ray gun", shock_color };

	if (this->type == vhs::weapon::weapon_type::demon_sword)
		return { L"demon sword", occult_color };

	if (this->type == vhs::weapon::weapon_type::holy_staff)
		return { L"sacred staff", holy_color };

	if (this->type == vhs::weapon::weapon_type::flame_mine)
		return { L"flame mine", burn_color };

	return { L"none", { 0.f, 0.f, 0.f, 1.f } };
}