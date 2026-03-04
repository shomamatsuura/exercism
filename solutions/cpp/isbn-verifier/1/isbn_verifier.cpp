#include "isbn_verifier.h"
#include <cctype>
namespace isbn_verifier {

bool is_valid(std::string_view isbn){
    unsigned int sum{0};
    unsigned int multiplier{10};
    for(std::size_t i{0}; i < isbn.length(); ++i){
        // Validate check character (either a digit or an X only)
        if(i == isbn.length() - 1){
            if(std::isdigit(static_cast<unsigned char>(isbn[i]))){
                sum += ((isbn[i] - '0') * multiplier);
                break;
            } else if(isbn[i] == 'X'){
                sum += (10 * multiplier);
                break;
            } else{
                return false;
            }
        }
        
        if(std::isdigit(static_cast<unsigned char>(isbn[i]))){
            sum += ((isbn[i] - '0') * multiplier);
            --multiplier;
        } else if(isbn[i] == '-'){
            continue;
        } else{
            return false;
        }
        
    }
    if(multiplier != 1) return false;
    return (sum % 11) == 0;
}

}  // namespace isbn_verifier
