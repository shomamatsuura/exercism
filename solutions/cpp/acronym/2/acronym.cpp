#include "acronym.h"
#include <cctype>
namespace acronym {

std::string acronym(std::string_view phrase){
    std::string output;
    bool new_word = true; // State: Are we looking for the start of a word?
    
    for(auto ch : phrase){
        // Skip apostrophes entirely (they don't start or end words)
        if(ch == '\'') continue;
        // If it's a letter, check if it's the start of a new word
        if(std::isalpha(static_cast<unsigned char>(ch))){
            if(new_word){
                output += static_cast<char>(std::toupper(static_cast<unsigned char>(ch)));
                new_word = false;
            }
        } else{
            // Any non-alpha (space, hyphen, underscore) triggers a "new word" state
            new_word = true;
        }
    }
    return output;
}

}  // namespace acronym
