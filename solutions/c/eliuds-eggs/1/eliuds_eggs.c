#include "eliuds_eggs.h"


int egg_count(int decimalNum){
    int oneBitCount = 0; 
    int remainder;

    while(decimalNum != 0){
        remainder = decimalNum % 2;
        decimalNum /= 2;

        if(remainder == 1) oneBitCount++;
        
    }
    return oneBitCount;
}