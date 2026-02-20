#include "luhn.h"
#include <cctype>

namespace luhn {
bool valid(const std::string& num){

    int sum{0};
    int digit_count{0};
    for(int i = num.length() - 1; i >= 0; --i){
        char c = num[i];
        if(c == ' '){
            continue;  
        }
        if(!std::isdigit(c)){
            return false;
        }
        // Convert character to integer
        int current_num = c - '0';
        // Double every second digit (when digit_count is odd, since we start at 0)
        if(digit_count % 2 != 0){
            current_num *= 2;
            if(current_num > 9){
                current_num -= 9;
            }
        }
        sum += current_num;
        ++digit_count;
    }
    // A valid Luhn number must have more than 1 digit and a sum divisible by 10
    return digit_count > 1 && sum % 10 == 0;
}


}  // namespace luhn
