#include "perfect_numbers.h"


kind classify_number(int number){

    if(number <= 0) return ERROR;
    if(number == 1) return DEFICIENT_NUMBER;
    int aliquot_sum = 1;
    for(int i = 2; i * i <= number; ++i){
        if(number % i == 0){
            aliquot_sum += i == (number / i)? i: i + (number / i);
        }
    }
    if(number == aliquot_sum) return PERFECT_NUMBER;
    if(number < aliquot_sum) return ABUNDANT_NUMBER;
    return DEFICIENT_NUMBER;
}