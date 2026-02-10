#include "isogram.h"
#include <ctype.h>
#include <stddef.h>
#include <stdint.h>


bool is_isogram(const char phrase[]){
    uint32_t alphabet_existence = 0;
    
    if(phrase == NULL) return false;
    for(; *phrase != '\0'; phrase++){    
        if(isalpha(*phrase)){
            char c = tolower(*phrase);
            uint32_t temp = (1 << (c - 'a'));
            if((temp & alphabet_existence) != 0) return false;
            alphabet_existence = alphabet_existence | (1 << (c - 'a'));
        }
    }
    return true;
}