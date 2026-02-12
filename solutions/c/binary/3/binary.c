#include "binary.h"

int convert(const char *input){
    int result = 0;
    for(; *input != '\0'; ++input){
        char current_bit = *input;
        if(current_bit != '0' && current_bit != '1') return INVALID;
        result = (result << 1) + (current_bit - '0');
        
    }
    return result;
}