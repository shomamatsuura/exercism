#include "armstrong_numbers.h"

namespace armstrong_numbers {
    
bool is_armstrong_number(int num){
    int sum{0};
    int digits{0};
    int num_for_calc = num;
    while(num_for_calc != 0){
        ++digits;
        num_for_calc /= 10;
        
    }
    num_for_calc = num;
    while(num_for_calc != 0){
        int sub_sum{1};
        for(int i = 0; i < digits; ++i){
            sub_sum *= (num_for_calc % 10);
        }
        sum += sub_sum;
        num_for_calc /= 10;
    }
    return sum == num;
}

}  // namespace armstrong_numbers
