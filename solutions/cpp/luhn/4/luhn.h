#pragma once
#include <string_view>
namespace luhn {

bool valid(std::string_view card_number);

}  // namespace luhn
