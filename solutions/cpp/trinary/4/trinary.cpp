#include "trinary.h"
#include <cctype>
namespace trinary {

unsigned int to_decimal(std::string_view trinary_number){
    
    unsigned int decimal_num{0};
    for(char ch : trinary_number){
        if(ch >= '0' && ch <= '2'){
            decimal_num = decimal_num * 3 + (ch - '0');
        } else {
            return 0;
        }
    }
    
    return decimal_num;
}



}  // namespace trinary
