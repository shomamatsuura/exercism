#include "rotational_cipher.h"

namespace rotational_cipher {

std::string rotate(std::string text, int key){
    std::string result{""};
    for(char c: text){
        if(isalpha(c)){
            if(c >= 'a' && c <= 'z'){
                if(c + key > 'z'){
                    result += 'a' + (c + key) % ('z' + 1);
                } else result += (c + key);
            } else if(c >= 'A' && c <= 'Z'){
                if(c + key > 'Z'){
                    result += 'A' + (c + key) % ('Z' + 1);
                } else result += (c + key);                
            }
        } else{
            result += c;
        }
    }
    return result;
}

}  // namespace rotational_cipher
