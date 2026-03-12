#pragma once
#include <string>
#include <string_view>
namespace atbash_cipher {
std::string encode(std::string_view text);
std::string decode(std::string_view encoded_text);
    


}  // namespace atbash_cipher
