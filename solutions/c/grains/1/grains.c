#include "grains.h"

uint64_t square(uint8_t index){
    if(index == 0) return 0;
    if(index == 1) return 1;
    uint64_t numGrains = 1;
    for(int i = 2; i <= index; i++){
        numGrains *= 2;
    }
    return numGrains;
}
uint64_t total(void){
    uint64_t total = 0;
    for(int i = 1; i <= 64; i++){
        total += square(i);
    }
    return total;
}

