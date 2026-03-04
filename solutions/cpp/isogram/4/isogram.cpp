#include "isogram.h"
#include <cctype>
#include <cstdint>
namespace isogram {

bool is_isogram(std::string_view word){
    uint32_t seen_mask{0};
    for(unsigned char c : word){
        if(std::isalpha(c)){
            int bit_index = std::tolower(c) - 'a';
            if(seen_mask & (1U << bit_index)){
                return false;
            }
            seen_mask |= (1U << bit_index);
        }
    }
    return true;
}

}  // namespace isogram
