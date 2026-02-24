#pragma once
#include <string>
#include <array>

namespace kindergarten_garden {

    enum class Plants{
        grass,
        clover,
        radishes,
        violets
    };

    std::array<kindergarten_garden::Plants, 4> plants(const std::string& garden, const std::string& name);

}  // namespace kindergarten_garden
