#include "binary.h"
#include <string.h>
int convert(const char *input){
    int inputLen = strlen(input);
    int decimalNum = 0;
    
    for(int i = 0; i < inputLen; i++){
        char inputNum = input[i];
        if(inputNum != '0' && inputNum != '1'){
            return INVALID;
        }
        decimalNum = (decimalNum << 1) + (inputNum - '0');
        // decimalNum = decimalNum * 2 + (inputNum - '0');
    
    }
    return decimalNum;
}