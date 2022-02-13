#pragma once

namespace sdk {
	template<class T>
	struct u_array;
	struct a_actor;

	struct u_level {
		char pad_0001[0x98]; // 0x00(0x98)
		sdk::u_array<sdk::a_actor*> actors; // 0x98(0x10)
	};
}