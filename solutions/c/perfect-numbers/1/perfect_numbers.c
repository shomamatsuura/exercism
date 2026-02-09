#include "perfect_numbers.h"
#include <math.h>

int classify_number(int num){
    if(num <= 0) return ERROR;
    int aliquotSum = 0;
    for(int i = 1; i <= sqrt(num); i++){
        if(i == num) continue;
        if(num % i == 0){
            aliquotSum += i;
            if(num !=  num / i && num != i * i){
                aliquotSum += num / i;                            
            }
        }
    }
    if(num == aliquotSum) return PERFECT_NUMBER;
    else if(num < aliquotSum) return ABUNDANT_NUMBER;
    else return DEFICIENT_NUMBER;
    
}