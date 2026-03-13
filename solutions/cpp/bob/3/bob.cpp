#include "bob.h"
#include <cctype>
#include <iostream>
namespace bob {

std::string hey(std::string_view question){
    // if(question == "") return "Fine. Be that way!";
    
    unsigned int letter_count{0};
    unsigned int upper_count{0};
    unsigned int space_count{0};
    char last_char{};
    for(auto c : question){
        if(c != ' ') last_char = c;
        if(std::isalpha(c)){
            ++letter_count;
            if(std::isupper(c)){
                ++upper_count;
            }
        }
        if((c == ' ' || c == '\n' || c == '\r' || c == '\t')){
            ++space_count;
        }
    }
    const bool has_question_mark = last_char == '?';
    const bool is_all_capital_letters = letter_count > 0 && letter_count == upper_count;
    
    
    if(has_question_mark){
        if(is_all_capital_letters){
            return "Calm down, I know what I'm doing!";
        }
        return "Sure.";
        
    }
    if(is_all_capital_letters){
        return "Whoa, chill out!";
    }
    
    if(question.length() == space_count){
        return "Fine. Be that way!" ;
    }

    return "Whatever.";
    
}

}  // namespace bob
