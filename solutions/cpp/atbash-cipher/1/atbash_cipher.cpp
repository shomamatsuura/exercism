#include "atbash_cipher.h"

namespace atbash_cipher {

    std::string encode(std::string word){
        std::string result{""};
        std::string tmp{""};
        for(char c: word){
            if(isalpha(c)){
                // Replace c
                tmp += (122 - (tolower(c) - 97));
            } else if(c >= '0' && c <= '9'){ // if c is a number: just add to result
                tmp += c;
            }
            if(tmp.length() == 5) {
                result += (tmp + " ");
                tmp = "";
            }
        }
        if(tmp != "") result += tmp;
        else result = result.substr(0, result.length() - 1);
        return result;
    }
    
    std::string decode(std::string word){
        std::string result{""};
        for(char c: word){
            // Check if c is from a-z
            if(isalpha(c)){
                // Replace c
                result += (122 - (tolower(c) - 97));
            } else if(c >= '0' && c <= '9'){ // if c is a number: just add to result
                result += c;
            }
            
        }
        return result;
    }

}  // namespace atbash_cipher
