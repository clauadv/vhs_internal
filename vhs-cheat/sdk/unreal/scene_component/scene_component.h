#pragma once

namespace sdk {
	struct vector;
	struct rotator;

	struct u_scene_component {
		char pad_0001[0x11c]; // 0x00(0x11c)
		sdk::vector relative_location; // 0x11c(0x0c)
		sdk::rotator relative_rotation; // 0x128(0x0c)
	};
}