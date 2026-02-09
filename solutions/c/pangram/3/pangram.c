#include "pangram.h"
#include <string.h>

bool is_pangram(const char *sentence){
    
    if(sentence == NULL) return false;
    size_t sentence_len = strlen(sentence);
    if(sentence_len < 26) return false;
    
    bool alphabet_array[26] = {false};
    for(size_t i = 0; i < sentence_len; i++){
            char ascii = sentence[i];
            if(ascii >= 'A' && ascii <= 'Z'){
                // Upper canse
                alphabet_array[ascii-'A'] = true;
            } else if(ascii >= 'a' && ascii <= 'z'){
                // Lower canse
                alphabet_array[ascii-'a'] = true;
            }
    }
    for(int i = 0; i < 26; i++){
        if(!alphabet_array[i]) return false;
    }
    return true;
}