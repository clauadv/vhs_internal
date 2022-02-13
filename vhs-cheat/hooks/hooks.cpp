#include <pch.h>
#include "hooks.h"
#include "../features/features.h"
#include "../utils/utils.h"

hooks::post_render::fn post_render_original = nullptr;
hooks::view_point::fn view_point_original;

bool hooks::initialize() {
	const auto world = *reinterpret_cast<decltype(sdk::world)*>(sdk::world);
	if (!world) return false;

	const auto game_instance = world->owning_game_instance;
	if (!game_instance) return false;

	const auto local_player = game_instance->local_players[0];
	if (!local_player) return false;

	const auto viewport_client = local_player->viewport_client;
	if (!viewport_client) return false;

	void** viewport_client_vtable = viewport_client->vf_table;
	if (!viewport_client_vtable) return false;

	if (MH_Initialize() != MH_OK) {
		throw std::runtime_error(_("failed to initialize hooking system."));
	}

	if (MH_CreateHook(viewport_client_vtable[post_render::index], &post_render::hook, reinterpret_cast<void**>(&post_render_original)) != MH_OK) {
		throw std::runtime_error(_("failed to initialize post render."));
	}

	if (MH_CreateHook(reinterpret_cast<LPVOID>(sdk::get_viewpoint), &view_point::hook, reinterpret_cast<void**>(&view_point_original)) != MH_OK) {
		throw std::runtime_error(_("failed to initialize viewpoint."));
	}

	if (MH_EnableHook(nullptr) != MH_OK) {
		throw std::runtime_error(_("failed to initialize hooks."));
	}

	return true;
}

bool hooks::release() {
	MH_Uninitialize();

	MH_DisableHook(nullptr);
	MH_RemoveHook(nullptr);

	utils::console::release();

	return true;
}

void __stdcall hooks::post_render::hook(sdk::u_object* viewport_client, sdk::u_canvas* canvas) {
	render::canvas = canvas;

	render::text(50.f, 50.f, _(L"vhs-cheat"), { 255, 255, 255, 255 });

	const auto discord = reinterpret_cast<sdk::u_discord*>(viewport_client);
	if (!discord) return;

	std::call_once(flag, [&discord]() {
		// mai gata ce atata colectare de date
		discord->destroy_discord_object();

		discord->create_discord_object(940296659693363221);
		discord->set_state(_(L"driving an infernus"));
		discord->set_details(_(L"pe ruby nephrite"));
		discord->set_image(_(L"gtasa"));
	});

	const auto world = *reinterpret_cast<sdk::u_world**>(sdk::world);
	if (!world) return;

	const auto game_state = world->game_state;
	if (!game_state) return;

	const auto local_player = world->owning_game_instance->local_players[0];
	if (!local_player) return;

	const auto player_controller = local_player->player_controller;
	if (!player_controller) return;

	const auto my_player = player_controller->acknowledged_pawn;
	if (!my_player) return;

	visuals::killer::run(world, my_player, player_controller);
	visuals::survivor::run(world, my_player, player_controller);
	visuals::entities::run(world, my_player, player_controller);

	post_render_original(viewport_client, canvas);
}

void __stdcall hooks::view_point::hook(sdk::u_player* player, sdk::minimal_view_info* view_info, const sdk::EStereoscopicPass stereo_pass) {
	view_point_original(player, view_info, stereo_pass);

	view_info->fov = 100.f;
}