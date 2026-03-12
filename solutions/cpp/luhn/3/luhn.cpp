#include "luhn.h"
#include <cctype>
namespace luhn {

bool valid(std::string_view card_number){
    if(card_number.length() <= 1)  return false;
    if(card_number == " 0") return false;
    unsigned int sum{0};
    unsigned int num_count{0};
    
    for(auto i{static_cast<int>(card_number.length())-1}; i >= 0; --i){
        if(card_number.at(i) == ' ') continue;
        else if(std::isdigit(card_number.at(i))){
            ++num_count;
            if(num_count % 2 == 0){
                unsigned int doubled_digit = (card_number.at(i) - '0') * 2;
                sum +=  (doubled_digit > 9) ? doubled_digit - 9 : doubled_digit;
            } else{
                sum += (card_number.at(i) - '0');
            }
        } else{
            return false;
        }
    }
    return sum % 10 == 0;
}

}  // namespace luhn
