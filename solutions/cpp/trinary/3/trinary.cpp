#include "trinary.h"
#include <cctype>
namespace trinary {

int to_decimal(std::string_view trinary_number){
    
    int decimal_num{0};
    for(unsigned int i{0}; i < trinary_number.length(); ++i){
        if(!isdigit(trinary_number.at(i))) return 0;
        int digit = trinary_number.at(i) - '0';
        for(unsigned int j{0}; j < trinary_number.length() - 1 - i; ++j){
            digit *= 3;
        }
        decimal_num += digit;
    }
    return decimal_num;
}



}  // namespace trinary
