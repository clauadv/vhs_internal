#pragma once

namespace ue4::engine {
	enum class stereoscopic_pass {
		essp_full,
		essp_left_eye,
		essp_right_eye,
		essp_left_eye_side,
		essp_right_eye_side
	};

	class f_minimal_view_info {
	public:
		ue4::math::vector location;
		ue4::math::rotator rotation;
		float fov;
	};
}