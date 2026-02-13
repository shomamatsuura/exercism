#include "binary.h"

int convert(const char *input){
    int result = 0;    
    for(; *input != '\0'; ++input){
        char binary = *input;
        if(binary == '0' || binary == '1'){
            result = (result << 1) + (binary - '0');
        } else return INVALID;
    }
    return result;
}