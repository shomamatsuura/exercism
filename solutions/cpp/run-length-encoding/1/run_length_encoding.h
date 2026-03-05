#pragma once
#include <string_view>
#include <string>
namespace run_length_encoding {

std::string encode(std::string_view data);
std::string decode(std::string_view encoded_data);


}  // namespace run_length_encoding
