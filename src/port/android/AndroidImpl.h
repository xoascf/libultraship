#pragma once

#include <cstdint>
#include <string>

#include <ImGui/imgui.h>

namespace Ship {

class Android {
  public:
    static void ImGuiProcessEvent(bool wantsTextInput);
};
}; // namespace Ship
