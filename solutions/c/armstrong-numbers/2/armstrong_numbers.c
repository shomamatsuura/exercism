#include "armstrong_numbers.h"

static int count_digits(int value){
    int num_digits = 0;
    do {
        ++num_digits;
        value /= 10;
    } while(value != 0);
    return num_digits;
}

static long long calc_power(int base, int power){
    long long result = 1;
    for(int i = 0; i < power; i++){
        result *= base;
    }
    return result;
}

bool is_armstrong_number(int candidate){
    if(candidate < 0) return false;
    int digits = count_digits(candidate);

    long long armstrong_sum = 0;
    int dividend = candidate;
    while(dividend != 0){
        armstrong_sum += calc_power(dividend % 10, digits);
        dividend /= 10;
    }

    return candidate == armstrong_sum;
    
    
}

