#pragma once
#include "../object_array/object_array.h"

namespace sdk {
	struct u_string;

	struct u_discord : sdk::u_object_array {
		void create_discord_object(std::int64_t client_id, bool start_elapsed_timer);
		void destroy_discord_object();
		void set_state(sdk::u_string new_state);
		void set_details(sdk::u_string new_details);
		void set_image(sdk::u_string image_name);
	};
}