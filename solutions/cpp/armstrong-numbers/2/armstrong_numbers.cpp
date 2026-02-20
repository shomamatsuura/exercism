#include "armstrong_numbers.h"
#include <cmath>

namespace armstrong_numbers {
    
bool is_armstrong_number(int num){
    if(num < 0) return false;
    int digits = (num == 0) ? 1 : static_cast<int>(std::log10(num) + 1);
    long long sum = 0;
    int temp = num;
    while(temp > 0){
        int digit = temp % 10;
        long long power_result = 1;
        for(int i = 0; i < digits; ++i){
            power_result *= digit;
        }
        sum += power_result;
        temp /= 10;
    }
    return sum == static_cast<long long>(num);
}

}  // namespace armstrong_numbers
