#include "pangram.h"
#include <ctype.h>
#include <stdint.h>

static const uint32_t ALL_LETTERS_MASK = (1U << 26) - 1;
static inline uint32_t mark_letter(uint32_t current_set, char c){
    unsigned char uc = (unsigned char)c;
    if(isalpha(uc)){
        uint32_t bit = 1U << (tolower(uc) - 'a');
        return current_set | bit;
    }
    return current_set;
}

bool is_pangram(const char *sentence){
    if(!sentence) return false;
    uint32_t letter_flags = 0;
    
    for(; *sentence != '\0'; ++sentence){
        letter_flags = mark_letter(letter_flags, *sentence);
        if(letter_flags == ALL_LETTERS_MASK) return true;
    }
    return false;
}