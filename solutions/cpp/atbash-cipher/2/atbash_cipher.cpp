#include "atbash_cipher.h"

namespace atbash_cipher {
    char transform(char c){
        if(std::isalpha(c)){
            return 'a' + 'z' - std::tolower(c);
        }
        return c;
    }
    
    std::string encode(std::string text){
        std::string result{""};
        int count{0};
        for(char c: text){
            if(std::isalnum(c)){
                 if(count > 0 && count % 5 == 0){
                     result += ' ';
                 }
                result += transform(c);
                ++count;
            }
        }
        return result;

    }
    
    std::string decode(std::string text){
        std::string result{""};
        for(char c: text){
            if(std::isalnum(c)){
                result += transform(c);
            }
        }
        return result;
    }

}  // namespace atbash_cipher
