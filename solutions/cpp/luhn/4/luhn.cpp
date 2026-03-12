#include "luhn.h"
#include <cctype>
namespace luhn {

bool valid(std::string_view card_number){

    unsigned int sum{0};
    unsigned int num_count{0};
    
    for(int i = card_number.length() - 1; i >= 0; --i){
        char c = card_number.at(i);
        if(c == ' ') continue;
        if(!std::isdigit(c)) return false;
        
        int current_num = c - '0';
        ++num_count;
        if(num_count % 2 == 0){
            current_num *= 2;
            if(current_num > 9) current_num -= 9;
        }
        sum += current_num;
    }
    return num_count > 1 && sum % 10 == 0;
}

}  // namespace luhn
