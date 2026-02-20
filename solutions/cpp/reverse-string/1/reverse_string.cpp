#include "reverse_string.h"

namespace reverse_string {

std::string reverse_string(std::string str){
    std::string new_str{""};
    for(char c: str){
        new_str = c + new_str;
    }
    return new_str;
}

}  // namespace reverse_string
