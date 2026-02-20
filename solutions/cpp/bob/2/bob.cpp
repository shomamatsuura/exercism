#include "bob.h"
#include <cctype>

namespace bob {
    std::string hey(const std::string& str) {
        bool has_upper{false};
        bool has_lower{false};
        bool is_question{false};
        bool is_silence{true};

        // One pass: Character classification
        for(char c: str){
            unsigned char uc = static_cast<unsigned char>(c);
            if(!std::isspace(uc)){
                is_silence = false;
                // Since this updates on every non-spce, the final value
                // represents the last visible character
                is_question = (c == '?');

                if(std::isalpha(uc)){
                    if(std::isupper(uc)) has_upper = true;
                    if(std::islower(uc)) has_lower = true;
                }
            }
        }
        bool is_shouting = has_upper && !has_lower;
        
        if(is_silence){
            return "Fine. Be that way!";
        }
        if(is_shouting){
            if(is_question) return "Calm down, I know what I'm doing!";
            return "Whoa, chill out!";
        }
        if(is_question){
            return "Sure.";
        }
        return "Whatever.";
        
    }
}  // namespace bob