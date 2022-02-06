#pragma once
#include "./math.h"

namespace sdk {
	enum EStereoscopicPass {
		eSSP_FULL,
		eSSP_LEFT_EYE,
		eSSP_RIGHT_EYE,
		eSSP_LEFT_EYE_SIDE,
		eSSP_RIGHT_EYE_SIDE,
	};

	struct minimal_view_info {
		sdk::vector location;
		sdk::rotator rotation;
		float fov;
	};
}