#include "binary.h"
#include <cctype>
#include <stdexcept>
namespace binary {

int convert(std::string_view decimal_num){
    int result{0};
    for(auto c : decimal_num){
        if(c != '0' && c != '1'){
            return 0;
        }
        result = (result << 1) + (c - '0');
    }
    return result;
}

}  // namespace binary
