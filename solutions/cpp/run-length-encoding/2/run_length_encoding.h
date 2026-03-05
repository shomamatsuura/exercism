#pragma once
#include <string_view>
#include <string>
namespace run_length_encoding {

std::string encode(std::string_view plain_text);
std::string decode(std::string_view encoded_text);


}  // namespace run_length_encoding
