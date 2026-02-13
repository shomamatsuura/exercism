#include "pangram.h"
#include <ctype.h>
#include <stdint.h>
static const uint32_t ALL_MASK = (1U << 26) - 1;
// static inline uint32_t full_mark(uint32_t alphabet, char c){
    
// }

bool is_pangram(const char *sentence){
    if(!sentence) return false;
    
    uint32_t alphabet = 0;
    for(; *sentence != '\0'; ++sentence){
        char current = *sentence;
        if(isalpha(current)){
            alphabet |= (1U << (tolower(current) - 'a'));
            if((alphabet & ALL_MASK) == ALL_MASK) return true;
        }
    }
    return false;
}