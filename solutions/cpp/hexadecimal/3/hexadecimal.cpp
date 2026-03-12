#include "hexadecimal.h"
#include <cctype>
namespace hexadecimal {

int convert(std::string_view hexadecimal_number){
    int result{0};
    for(auto c : hexadecimal_number){ 
        if(std::isdigit(c)){
            result = result * 16 + static_cast<int>(c - '0');        
        } else if(c >= 'a' && c <= 'f'){
            result = result * 16 + static_cast<int>(c - 'a' + 10);        
        } else {
            return 0;
        }
        
    }
    return result;
}

}  // namespace hexadecimal
