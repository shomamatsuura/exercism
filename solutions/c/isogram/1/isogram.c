#include "isogram.h"
#include <ctype.h>
#include <stddef.h>



bool is_isogram(const char phrase[]){
    // uint32_t all_alphabet_mask = (1 << 26) - 1;
    // uint32_t alphabet_existence = 0;
    int alphabet_existence[26] = {0}; 
    
    if(phrase == NULL) return false;
    for(; *phrase != '\0'; phrase++){
    
        if(isalpha(*phrase)){
            char c = tolower(*phrase);
            if(alphabet_existence[c - 'a'] == 1) return false;
            alphabet_existence[c - 'a'] = 1;
            
            // alphabet_existence = 1 << (c - 'a');
        }
    }
    return true;
}