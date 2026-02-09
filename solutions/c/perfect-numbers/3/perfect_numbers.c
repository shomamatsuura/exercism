#include "perfect_numbers.h"

kind classify_number(int num){
    if(num < 1) return ERROR;
    if(num == 1) return DEFICIENT_NUMBER;

    long long aliquotSum = 1;
    for(int i = 2; i <= num / i; i++){
        if(num % i == 0){
            aliquotSum += i;
            if(i != num / i){
                aliquotSum += num / i;                            
            }
        }
    }
    if(num == aliquotSum) return PERFECT_NUMBER;
    else if(num < aliquotSum) return ABUNDANT_NUMBER;
    else return DEFICIENT_NUMBER;
    
}