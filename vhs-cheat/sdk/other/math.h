#pragma once

namespace sdk {
	struct matrix {
		float m[4][4];
	};

	struct vector_2d {
		float x, y;
	};

	struct vector {
		float x, y, z;
	};

	struct rotator {
		float x, y, z;
	};
}