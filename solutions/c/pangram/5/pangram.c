#include "pangram.h"
#include <ctype.h>
#include <stdint.h>

bool is_pangram(const char *sentence){
    if(!sentence) return false;
    uint32_t all_alphabet_mask = (1 << 26) - 1;
    uint32_t alphabet = 0;
    
    for(; *sentence != '\0'; ++sentence){
        char current_character = *sentence;
        if(isalpha(current_character)){
            current_character = tolower(current_character);
            alphabet |= (1 <<(current_character - 'a'));
        }
    }
    return (all_alphabet_mask & alphabet) == all_alphabet_mask;
}