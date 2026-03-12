#include "hexadecimal.h"
#include <cctype>
namespace hexadecimal {

int convert(std::string_view hexadecimal_number){
    int result{0};
    for(auto c : hexadecimal_number){ 
        int current_num{0};
        if(std::isdigit(c)){
            current_num = c - '0';
        } else if(c >= 'a' && c <= 'f'){
            current_num = c - 'a' + 10;
        } else if(c >= 'A' && c <= 'F'){
            current_num = c - 'A' + 10;
        } else {
            return 0;
        }
        result = (result * 16) + current_num;
        
    }
    return result;
}

}  // namespace hexadecimal
