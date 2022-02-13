#include <pch.h>

void sdk::u_discord::create_discord_object(const std::int64_t client_id) {
	static const auto fn = sdk::object_array->find_object(_("Function DiscordUE4.DiscordObject.CreateDiscordObject"));
	if (!fn) return;

	struct {
		std::int64_t client_id;
		bool require_discord_running;
		bool start_elapsed_timer;
	} params{};

	params.client_id = client_id;
	params.require_discord_running = false;
	params.start_elapsed_timer = false;

	const auto flags = fn->flags;
	sdk::process_event(this, fn, &params);
	fn->flags = flags;
}

void sdk::u_discord::destroy_discord_object() {
	static const auto fn = sdk::object_array->find_object(_("Function DiscordUE4.DiscordObject.DestroyDiscordObject"));
	if (!fn) return;

	const auto flags = fn->flags;
	sdk::process_event(this, fn, nullptr);
	fn->flags = flags;
}

void sdk::u_discord::set_state(const sdk::u_string new_state) {
	static const auto fn = sdk::object_array->find_object(_("Function DiscordUE4.DiscordObject.SetState"));
	if (!fn) return;

	struct {
		sdk::u_string new_state;
	} params{};

	params.new_state = new_state;

	const auto flags = fn->flags;
	sdk::process_event(this, fn, &params);
	fn->flags = flags;
}

void sdk::u_discord::set_details(const sdk::u_string new_details) {
	static const auto fn = sdk::object_array->find_object(_("Function DiscordUE4.DiscordObject.SetDetails"));
	if (!fn) return;

	struct {
		sdk::u_string new_state;
	} params{};

	params.new_state = new_details;

	const auto flags = fn->flags;
	sdk::process_event(this, fn, &params);
	fn->flags = flags;
}

void sdk::u_discord::set_image(const sdk::u_string image_name) {
	static const auto fn = sdk::object_array->find_object(_("Function DiscordUE4.DiscordObject.SetLargeImage"));
	if (!fn) return;

	struct {
		sdk::u_string image_name;
	} params{};

	params.image_name = image_name;

	const auto flags = fn->flags;
	sdk::process_event(this, fn, &params);
	fn->flags = flags;
}