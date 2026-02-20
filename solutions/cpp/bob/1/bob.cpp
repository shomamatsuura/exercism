#include "bob.h"

namespace bob {

std::string hey(const std::string& str){
    bool is_all_capital{false};
    bool is_changed_alpha_flg{false};
    unsigned int last_char_idx{0};
    for(size_t i{0}; i < str.length(); ++i){
        if(std::isspace(str[i])) continue;
        
        last_char_idx = i;
        if(std::isalpha(str[i])){  
            if(isupper(str[i]) && !is_changed_alpha_flg){
                is_all_capital = true;
                is_changed_alpha_flg = true;
            } else if(!isupper(str[i])){
                is_all_capital = false;
            }
        }
    }
    if(str.empty() || last_char_idx == 0) return "Fine. Be that way!";
    else if(str[last_char_idx] == '?' && is_all_capital) return "Calm down, I know what I'm doing!";
    else if(str[last_char_idx] == '?') return "Sure.";
    else if(is_all_capital) return "Whoa, chill out!";
    else return "Whatever.";
}

}  // namespace bob
