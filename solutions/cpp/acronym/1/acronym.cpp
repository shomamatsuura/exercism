#include "acronym.h"
#include <cctype>
namespace acronym {

std::string acronym(std::string_view phrase){
    std::string output{};
    if(phrase.length() == 0) return "";
    
    char prefix = std::toupper(phrase.at(0));
    for(auto ch : phrase){
        if(isalpha(ch) && prefix == '\0'){
            prefix = ch;
        } else if(!isalpha(ch) && prefix != '\0' && ch != '\''){
            output += std::toupper(prefix);
            prefix = '\0';
        }
    }
    if(prefix != '\0') output += std::toupper(prefix);
    return output;
}

}  // namespace acronym
