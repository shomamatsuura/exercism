#include "rotational_cipher.h"

namespace rotational_cipher {

std::string rotate(const std::string& text, int rot){
    std::string result;
    // Optimization: Allocate memory once
    result.reserve(text.length()); 
    for(unsigned char ch: text){ // Use unsigned char to prevent UB(undefined behavior) with isalpha
        if(std::isalpha(ch)){
            char base = std::islower(ch) ? 'a' : 'A';
            result += static_cast<char>((ch - base + rot) % 26 + base);
        } else{
            result += ch;
        }
    }
    return result;
}

}  // namespace rotational_cipher
