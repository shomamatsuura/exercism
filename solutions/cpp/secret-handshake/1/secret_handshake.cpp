#include "secret_handshake.h"
#include <algorithm>

namespace secret_handshake {

std::vector<std::string> commands(int num){
    std::vector<std::string> result{};
    if((num & 1) == 1) result.emplace_back("wink");
    if((num & 0b10) == 0b10) result.emplace_back("double blink");
    if((num & 0b100) == 0b100) result.emplace_back("close your eyes");
    if((num & 0b1000) == 0b1000) result.emplace_back("jump");
    if((num & 0b10000) == 0b10000){
         std::reverse(result.begin(), result.end());  
    }
    
    return result;
}

}  // namespace secret_handshake
