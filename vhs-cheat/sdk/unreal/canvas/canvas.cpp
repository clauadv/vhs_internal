#include "canvas.h"
#include "../../sdk.h"

void sdk::u_canvas::draw_box(const sdk::vector_2d& screen, const sdk::vector_2d& size, const float thickness, const sdk::color& color) {
	static const auto fn = sdk::object_array->find_object(_("Function Engine.Canvas.K2_DrawBox"));
	if (!fn) return;

	struct {
		sdk::vector_2d screen{};
		sdk::vector_2d size{};
		float thickness{};
		sdk::color color{};
	} params;

	params.screen = screen;
	params.size = size;
	params.thickness = thickness;
	params.color = color;

	const auto flags = fn->flags;
	fn->flags |= 0x00000400;

	sdk::process_event(this, fn, &params);
	fn->flags = flags;
}

void sdk::u_canvas::draw_line(const sdk::vector_2d screen_a, const sdk::vector_2d screen_b, const float thickness, const sdk::color color) {
	static const auto fn = sdk::object_array->find_object(_("Function Engine.Canvas.K2_DrawLine"));
	if (!fn) return;

	struct {
		sdk::vector_2d screen_a{};
		sdk::vector_2d screen_b{};
		float thickness{};
		sdk::color color{};
	} params{};

	params.screen_a = screen_a;
	params.screen_b = screen_b;
	params.thickness = thickness;
	params.color = color;

	sdk::process_event(this, fn, &params);
}

void sdk::u_canvas::draw_text(const sdk::u_string text, const sdk::vector_2d screen, const sdk::vector_2d scale, const sdk::color color, const float kerning, const sdk::color shadow_color, const sdk::vector_2d shadow_offset, const bool center_x, const bool center_y, const bool outlined, const sdk::color outline_color) {
	static const auto fn = sdk::object_array->find_object(_("Function Engine.Canvas.K2_DrawText"));
	if (!fn) return;

	struct {
		sdk::u_object* font{};
		sdk::u_string text{};
		sdk::vector_2d screen{};
		sdk::vector_2d scale{};
		sdk::color color{};
		float kerning{};
		sdk::color shadow_color{};
		sdk::vector_2d shadow_offset{};
		bool center_x{};
		bool center_y{};
		bool outlined{};
		sdk::color outline_color{};
	} params{};

	params.font = font;
	params.text = text;
	params.screen = screen;
	params.scale = scale;
	params.color = color;
	params.kerning = kerning;
	params.shadow_color = shadow_color;
	params.shadow_offset = shadow_offset;
	params.center_x = center_x;
	params.center_y = center_y;
	params.outlined = outlined;
	params.outline_color = outline_color;

	sdk::process_event(this, fn, &params);
}

void sdk::u_canvas::draw_polygon(class u_texture* texture, const sdk::vector_2d& screen, const sdk::vector_2d& radius, const int side_number, const sdk::color& color) {
	static const auto fn = sdk::object_array->find_object(_("Function Engine.Canvas.K2_DrawPolygon"));
	if (!fn) return;

	struct {
		class u_texture* texture{};
		sdk::vector_2d screen{};
		sdk::vector_2d radius{};
		int side_number{};
		sdk::color color{};
	} params{};

	params.texture = texture;
	params.screen = screen;
	params.radius = radius;
	params.side_number = side_number;
	params.color = color;

	const auto flags = fn->flags;
	fn->flags |= 0x00000400;

	sdk::process_event(this, fn, &params);
	fn->flags = flags;
}

sdk::vector_2d sdk::u_canvas::text_size(const sdk::u_string& text, const sdk::vector_2d& scale) {
	static const auto fn = sdk::object_array->find_object(_("Function Engine.Canvas.K2_TextSize"));
	if (!fn) return {};

	struct {
		sdk::u_object* font;
		sdk::u_string text;
		sdk::vector_2d scale;
		sdk::vector_2d return_value;
	} params{};

	params.font = font;
	params.text = text;
	params.scale = scale;

	const auto flags = fn->flags;
	fn->flags |= 0x00000400;

	sdk::process_event(this, fn, &params);
	fn->flags = flags;

	return params.return_value;
}