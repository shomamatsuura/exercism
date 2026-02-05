#include "collatz_conjecture.h"

int steps(int start){
    if(start <= 0) return -1;
    int stepCount = 0;
    
    while(start != 1){
        if(start % 2 == 0){
            start /= 2;
        } else{
            start = start * 3 + 1;
        }
        stepCount++;
    }
    return stepCount;
}