#include "rotational_cipher.h"
#include <cctype>
namespace rotational_cipher {

std::string rotate(const std::string& input, int key){
    std::string output{""};
    key %= 26;
    for(auto c : input){
        if(std::isalpha(c)){
            if(std::islower(c)){
                if(c + key > 'z'){
                    output += ('a' + (c + key) - 'z' - 1);
                } else{
                    output += (c + key);
                }
            } else{
                if(c + key > 'Z'){
                    output += ('A' + (c + key) - 'Z' - 1);
                } else{
                    output += (c + key);
                }
            }
        } else{
            output += c;
        }
    }
    return output;
}
}  // namespace rotational_cipher
