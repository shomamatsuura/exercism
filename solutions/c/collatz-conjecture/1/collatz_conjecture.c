#include "collatz_conjecture.h"

int steps(int start){
    int stepCount = 0;
    if(start <= 0) return -1;
    while(start != 1){
        if(start % 2 == 0){
            start = start / 2;
        } else{
            start = start * 3 + 1;
        }
        stepCount++;
    }
    return stepCount;
}