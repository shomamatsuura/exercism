#include "isogram.h"
#include <ctype.h>
#include <stddef.h>
bool is_isogram(const char phrase[]){

    bool seen['z' - 'a' + 1] = {false}; 
    
    if(phrase == NULL) return false;
    for(; *phrase != '\0'; phrase++){
    
        if(isalpha(*phrase)){
            char c = tolower(*phrase);
            if(seen[c - 'a'] == true) return false;
            seen[c - 'a'] = true;         
        }
    }
    return true;
}