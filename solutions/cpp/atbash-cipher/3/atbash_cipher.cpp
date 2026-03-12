#include "atbash_cipher.h"
#include <cctype>
namespace atbash_cipher {
std::string encode(std::string_view text){
    std::string encoded_text{""};
    std::size_t char_count{0};
    for(auto c : text){
        if(std::isalpha(c)){
            c = std::tolower(c);
            if(char_count == 5){
                encoded_text += " ";
                char_count = 0;
            } 
            encoded_text += ('a' + 25 - (c - 'a'));
            
            ++char_count;
        } else if(std::isdigit(c)){
            if(char_count == 5){
                encoded_text += " ";
                char_count = 0;
            }
            encoded_text += c;
            ++char_count;
        }
    }
    return encoded_text;
}
std::string decode(std::string_view encoded_text){
    std::string text{""};
    for(auto c : encoded_text){
        if(std::isalpha(c)){
            text += ('a' + 25 - (c - 'a'));
        } else if(std::isdigit(c)){
            text += c;
        }
    }
    return text;
}

}  // namespace atbash_cipher
