#include "luhn.h"

namespace luhn {
bool valid(const std::string& num){
    if(num.length() <= 1) return false;
    int sum{0};
    int digit{1};
    if(num.at(0) == ' ') return false;
    for(int i = num.length() - 1; i >= 0; --i){
        if(num.at(i) == ' ') continue;
        if(!isdigit(num.at(i))) return false;

        int current_num = num.at(i) - '0';    // substract '0' from the ch to cast
        if(digit % 2 == 0){
            int doubled_num = current_num * 2;
            current_num = doubled_num > 9 ? doubled_num - 9 : doubled_num;  
        }
        sum += current_num;
        ++digit;
    }
    return sum % 10 == 0;
}


}  // namespace luhn
