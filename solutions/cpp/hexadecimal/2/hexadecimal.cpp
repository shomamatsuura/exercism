#include "hexadecimal.h"
#include <cctype>
namespace hexadecimal {

int convert(const std::string& hexadecimal_num){
    int decimal_num{0};
    for(char c: hexadecimal_num){
        int current_num{0};
        if(std::isdigit(c)){
            current_num = c - '0';
        } else if(c >= 'a' && c <= 'f') {
            current_num = c - 'a' + 10;
        } else if(c >= 'A' && c <= 'F')
            current_num = c - 'A' + 10;
        else {
            return 0;
        }
        
        decimal_num = (decimal_num * 16) + current_num;
    }
    return decimal_num;
}

}  // namespace hexadecimal
