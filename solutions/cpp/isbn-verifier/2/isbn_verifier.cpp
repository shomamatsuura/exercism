#include "isbn_verifier.h"
#include <cctype>
namespace isbn_verifier {

bool is_valid(std::string_view isbn){
    int factor{10};
    int sum{0};
    for(char c : isbn){
        if(c == '-') continue;

        bool is_digit = (c >= '0' && c <= '9');
        bool is_last_char_x = (factor == 1 && c == 'X');

        if(!is_digit && !is_last_char_x) return false;

        int value = (c == 'X') ? 10 : (c - '0');
        sum += value * factor;
        --factor;
        if(factor < 0) return false;
    }
    
    return (factor == 0 && sum % 11 == 0);
}

}  // namespace isbn_verifier
