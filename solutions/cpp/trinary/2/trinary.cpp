#include "trinary.h"

namespace trinary {

unsigned int to_decimal(const std::string& trinary_num){
    unsigned int result{0};
    for(char ch: trinary_num){
         if(ch >= '0' && ch <= '2'){
             result = result * 3 + (ch - '0');
         } else{
             return 0;
         }
    }
    return result;
}

}  // namespace trinary
