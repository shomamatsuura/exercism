#include "binary.h"
#include <cctype>
#include <stdexcept>
namespace binary {

int convert(std::string_view binary_str){
    int decimal_result{0};
    for(auto bit : binary_str){
        if(bit != '0' && bit != '1'){
            return 0;
        }
        decimal_result = (decimal_result << 1) + (bit - '0');
    }
    return decimal_result;
}

}  // namespace binary
