#include "pangram.h"

namespace pangram {
    
bool is_pangram(std::string sentence){
    int full_mask = (1 << 26) - 1;
    int alphabet{0};
    for(char letter: sentence){
        if(std::isalpha(letter)){
            alphabet = alphabet | (1 << (std::tolower(letter) - 'a'));
        }
    }
    return (alphabet & full_mask) == full_mask;
}

}  // namespace pangram
