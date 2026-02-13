#include "perfect_numbers.h"

kind classify_number(int num){
    if(num <= 0) return ERROR;
    if(num == 1) return DEFICIENT_NUMBER;

    int aliquot_sum = 1;
    for(int i = 2; i <= num / i; ++i){
        if(num % i == 0){
            aliquot_sum += i;

            if(i != num / i) aliquot_sum += num / i;
        }
    }
    if(num == aliquot_sum) return PERFECT_NUMBER;
    if(num < aliquot_sum) return ABUNDANT_NUMBER;
    return DEFICIENT_NUMBER;
}
