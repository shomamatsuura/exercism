#include "atbash_cipher.h"
#include <cctype>
namespace atbash_cipher {
char transform(char c){
    if(std::isalpha(c)){
        return 'a' + 'z' - std::tolower(c);
    }
    return c;
}
std::string encode(std::string_view text){
    std::string encoded_text{""};
    std::size_t char_count{0};
    for(auto c : text){
        if(std::isalnum(c)){
            if(char_count > 0 && char_count % 5 == 0){
                encoded_text += ' ';
            } 
            encoded_text += transform(c);
            ++char_count;
        }
    }
    return encoded_text;
}
std::string decode(std::string_view encoded_text){
    std::string text{""};
    for(auto c : encoded_text){
        if(std::isalnum(c)){
            text += transform(c);
        }
    }
    return text;
}

}  // namespace atbash_cipher
