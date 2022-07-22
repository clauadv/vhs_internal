#include <includes.h>
#include "hooks/hooks.h"

bool menu::initialize() {
	ImGui::CreateContext();
	ImGui_ImplWin32_Init(hooks::window);
	ImGui_ImplDX11_Init(d3d11::device, d3d11::context);

	auto& io = ImGui::GetIO();
	io.IniFilename = nullptr;
	io.LogFilename = nullptr;
	io.ConfigFlags |= ImGuiConfigFlags_NoMouseCursorChange;

	ImGui::StyleColorsDark();

	auto& style = ImGui::GetStyle();
	style.ScrollbarSize = 13.0f;
	style.WindowTitleAlign = ImVec2{ 0.5f, 0.5f };
	style.WindowRounding = 6.f;

	return true;
}

void menu::handle_input(ue4::game_framework::a_pawn* my_player, ue4::game_framework::a_player_controller* player_controller) {
	if (variables::menu::opened) {
		my_player->disable_input(player_controller);
	} else {
		my_player->enable_input(player_controller);
	}
}

void menu::render() {
	auto& style = ImGui::GetStyle();
	auto& io = ImGui::GetIO();
	io.MouseDrawCursor = variables::menu::opened;

	static float alpha = 0.f;

	const auto& draw_list = ImGui::GetBackgroundDrawList();
	draw_list->AddRectFilled(ImVec2{ 0.f, 0.f }, io.DisplaySize, ImColor{ 0.f, 0.f, 0.f, alpha });

	if (!variables::menu::opened) {
		alpha = std::fmax(alpha - io.DeltaTime * 3.0f, 0.f);
		style.Alpha = std::fmax(style.Alpha - io.DeltaTime * 6.0f, 0.f);
		return;
	}

	alpha = std::fmin(alpha + io.DeltaTime * 3.0f, 0.5f);
	style.Alpha = std::fmin(style.Alpha + io.DeltaTime * 6.0f, 1.f);

	static std::uint32_t selected_tab = 0;
	ImGui::SetNextWindowSize(ImVec2{ 560.f, 412.f }, ImGuiCond_Once);
	ImGui::Begin(_("cheats.tw pt samp 2"), nullptr, ImGuiWindowFlags_NoResize | ImGuiWindowFlags_NoCollapse);

	ImGui::BeginChild(_("tabs"), ImVec2{ 150, 0 }, true);

	static constexpr const char* tabs[]{
		"players",
		"entities",
		"misc"
	};

	for (std::size_t i = 0; i < IM_ARRAYSIZE(tabs); ++i) {
		if (ImGui::Selectable(tabs[i], selected_tab == i)) {
			selected_tab = i;
		}
	}

	ImGui::EndChild();

	ImGui::SameLine();

	ImGui::BeginGroup();

	switch (selected_tab) {
		case 0:
			ImGui::Text(_("players esp"));
			ImGui::Separator();
			ImGui::Spacing();

			ImGui::Checkbox("name", &variables::players::name);
			ImGui::Checkbox("skeleton", &variables::players::skeleton);
			ImGui::Checkbox("weapon", &variables::players::weapon);

			ImGui::Spacing();
			ImGui::Spacing();

			ImGui::Text("teen color");
			ImGui::SameLine();
			ImGui::ColorEdit4(("##teen_color"), variables::players::teen_color, ImGuiColorEditFlags_NoInputs | ImGuiColorEditFlags_AlphaBar);

			ImGui::Text("monster color");
			ImGui::SameLine();
			ImGui::ColorEdit4(("##monster_color"), variables::players::monster_color, ImGuiColorEditFlags_NoInputs | ImGuiColorEditFlags_AlphaBar);

			break;
		case 1:
			ImGui::Text("entities esp");
			ImGui::Separator();
			ImGui::Spacing();

			ImGui::Checkbox("lockbox", &variables::entities::lockbox);
			ImGui::SameLine();
			ImGui::ColorEdit4(("##lockbox_color"), variables::entities::lockbox_color, ImGuiColorEditFlags_NoInputs | ImGuiColorEditFlags_AlphaBar);

			ImGui::Checkbox("noisemaker", &variables::entities::noisemaker);
			ImGui::SameLine();
			ImGui::ColorEdit4(("##noisemaker_color"), variables::entities::noisemaker_color, ImGuiColorEditFlags_NoInputs | ImGuiColorEditFlags_AlphaBar);

			ImGui::Checkbox("pills", &variables::entities::pills);
			ImGui::SameLine();
			ImGui::ColorEdit4(("##pills_color"), variables::entities::pills_color, ImGuiColorEditFlags_NoInputs | ImGuiColorEditFlags_AlphaBar);

			ImGui::Checkbox("adrenaline", &variables::entities::adrenaline);
			ImGui::SameLine();
			ImGui::ColorEdit4(("##adrenaline_color"), variables::entities::adrenaline_color, ImGuiColorEditFlags_NoInputs | ImGuiColorEditFlags_AlphaBar);

			ImGui::Checkbox("walkie", &variables::entities::walkie);
			ImGui::SameLine();
			ImGui::ColorEdit4(("##walkie_color"), variables::entities::walkie_color, ImGuiColorEditFlags_NoInputs | ImGuiColorEditFlags_AlphaBar);

			ImGui::Checkbox("window", &variables::entities::vending);
			ImGui::SameLine();
			ImGui::ColorEdit4(("##vending_color"), variables::entities::vending_color, ImGuiColorEditFlags_NoInputs | ImGuiColorEditFlags_AlphaBar);

			ImGui::Checkbox("basket", &variables::entities::basket);
			ImGui::SameLine();
			ImGui::ColorEdit4(("##basket_color"), variables::entities::basket_color, ImGuiColorEditFlags_NoInputs | ImGuiColorEditFlags_AlphaBar);

			ImGui::Checkbox("station", &variables::entities::station);

			ImGui::Checkbox("medkit", &variables::entities::medkit);
			ImGui::SameLine();
			ImGui::ColorEdit4(("##medkit_color"), variables::entities::medkit_color, ImGuiColorEditFlags_NoInputs | ImGuiColorEditFlags_AlphaBar);

			ImGui::Checkbox("life_essence", &variables::entities::life_essence);
			ImGui::SameLine();
			ImGui::ColorEdit4(("##life_essence_color"), variables::entities::life_essence_color, ImGuiColorEditFlags_NoInputs | ImGuiColorEditFlags_AlphaBar);

			ImGui::Checkbox("trap", &variables::entities::trap);
			ImGui::SameLine();
			ImGui::ColorEdit4(("#trap_color"), variables::entities::trap_color, ImGuiColorEditFlags_NoInputs | ImGuiColorEditFlags_AlphaBar);

			ImGui::Spacing();
			ImGui::Spacing();

			ImGui::Text("max distance");
			ImGui::SliderFloat("##max_distance", &variables::entities::max_distance, 0.f, 100.f, "%.3gm", 1.f);
			break;
		case 2:
			ImGui::Text("misc");
			ImGui::Separator();
			ImGui::Spacing();

			ImGui::Checkbox("auto skillcheck", &variables::misc::auto_skillcheck);
			ImGui::Checkbox("fov changer", &variables::misc::fov_changer);
			ImGui::SliderFloat("##fov_value", &variables::misc::fov_value, 50.f, 150.f, "%.3g", 1.f);
			break;
		default:
			break;
	}

	ImGui::EndGroup();

	ImGui::End();
}