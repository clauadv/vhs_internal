#pragma once

#include <Windows.h>
#include <iostream>
#include <string>
#include <cstdint>
#include <algorithm>
#include <iomanip>
#include <list>
#include <sstream>
#include <mutex>
#include <utility>
#include <cstdint>
#include <future>
#include <corecrt_math_defines.h>
#include <d3d11.h>

#include "utils/utils.h"
#include "utils/libraries/minhook/include/MinHook.h"
#include "utils/libraries/xor.h"
#include "utils/libraries/lazy_importer.h"
#include "utils/libraries/fnv.h"

#include "utils/libraries/imgui/imgui.h"
#include "utils/libraries/imgui/imgui_impl_dx11.h"
#include "utils/libraries/imgui/imgui_impl_win32.h"
#include "utils/libraries/imgui/imgui_internal.h"

#include "ue4/sdk.h"

#include "ue4/math/vector.h"
#include "ue4/math/vector_2d.h"
#include "ue4/math/rotator.h"
#include "ue4/math/color.h"
#include "ue4/math/matrix.h"
#include "ue4/containers/array.h"
#include "ue4/containers/string.h"
#include "ue4/containers/enum_as_byte.h"

#include "ue4/engine/world/world.h"
#include "ue4/core_object/name/name.h"
#include "ue4/core_object/object/object.h"

#include "ue4/core_object/field/field.h"
#include "ue4/core_object/struct/struct.h"
#include "ue4/core_object/class/class.h"
#include "ue4/engine/canvas/canvas.h"
#include "ue4/engine/game_instance/game_instance.h"
#include "ue4/engine/player/player.h"
#include "ue4/engine/level/level.h"
#include "ue4/engine/camera/camera.h"
#include "ue4/game_framework/actor/actor.h"
#include "ue4/game_framework/pawn/pawn.h"
#include "ue4/game_framework/controller/controller.h"
#include "ue4/game_framework/player_controller/player_controller.h"
#include "ue4/game_framework/player_state/player_state.h"
#include "ue4/game_framework/game_state_base/game_state_base.h"
#include "ue4/components/scene_component/scene_component.h"
#include "ue4/components/skeletal_mesh_component/skeletal_mesh_component.h"

#include "vhs/bones/bones.h"
#include "vhs/weapon/weapon.h"
#include "vhs/station/station.h"
#include "vhs/minigame/minigame.h"
#include "features/features.h"

#include "menu/d3d11/d3d11.h"
#include "menu/menu.h"

#include "render/render.h"