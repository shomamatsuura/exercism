#include "binary.h"
#include <string.h>
#include <math.h>
#include <stdlib.h>
int convert(const char *input){
    int inputLen = strlen(input);
    int decimalNum = 0;
    
    for(int i = 0; i < inputLen; i++){
        if(input[inputLen - 1 - i] == '0' || input[inputLen - 1 - i] == '1'){
            int intInputNum = input[inputLen - 1 - i] - '0';
            decimalNum += intInputNum * pow(2, i);
        } else{
            return INVALID;
        }
    }
    return decimalNum;
}