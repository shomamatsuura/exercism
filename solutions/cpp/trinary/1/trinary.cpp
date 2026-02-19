#include "trinary.h"

namespace trinary {

unsigned int to_decimal(const std::string& trinary_num){
    unsigned int result{0};
    for(size_t i{0}; i < trinary_num.length(); ++i){
         if(trinary_num.at(i) == '0' || trinary_num.at(i) == '1' || trinary_num.at(i) == '2'){
             result = result * 3 + (unsigned int)(trinary_num.at(i) - '0');
         } else{
             return 0;
         }
    }
    return result;
}

}  // namespace trinary
