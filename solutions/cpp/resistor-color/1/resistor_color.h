#pragma once
#include <string>
#include <string_view>
#include <vector>

namespace resistor_color {

int color_code(const std::string& color);
std::vector<std::string> colors();
}  // namespace resistor_color
