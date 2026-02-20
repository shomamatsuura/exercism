#include "hexadecimal.h"
#include <cctype>
namespace hexadecimal {

int convert(std::string hexadecimal_num){
    int decimal_num{0};
    for(size_t i = 0; i < hexadecimal_num.length(); ++i){
        char c = hexadecimal_num[i];
        if(!std::isdigit(c) && (c < 'a' || c > 'f')){
            return 0;
        }
        int currenct_num{0};
        
        if(std::isdigit(c)){
            currenct_num = c - '0';
        } else if(c >= 'a' && c <= 'f') {
            currenct_num = c - 'a' + 10;
        }
        decimal_num = decimal_num * 16 + currenct_num;
    }
    return decimal_num;
}

}  // namespace hexadecimal
