#include "armstrong_numbers.h"

static inline int calc_digit(int candidate){
    if(candidate < 10) return 1;
    int digit = 0;
    while(candidate != 0){
        ++digit;
        candidate /= 10;
    }
    return digit;
}

static inline int calc_multiplier(int base, int power){
    int multiplier = 1;
    for(int i = 0; i < power; i++){
        multiplier *= base;
    }
    return multiplier;
}

bool is_armstrong_number(int candidate){
    int digit = calc_digit(candidate);

    int sum = 0;
    int dividend = candidate;
    while(dividend != 0){
        sum += calc_multiplier(dividend % 10, digit);
        dividend /= 10;
    }
    if(candidate == sum) return true;
    else return false;
    
    
}

