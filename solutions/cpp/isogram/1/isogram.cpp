#include "isogram.h"
#include <cctype>
namespace isogram {

bool is_isogram(std::string_view word){
    int alphabet{0};
    for(auto c : word){
        if(std::isalpha(c)){
            c = std::tolower(c);
            if((alphabet & (1 << (c - 'a'))) == (1 << (c - 'a'))) return false;
            else{
                alphabet = alphabet | (1 << (c - 'a'));
            }
        }
    }
    return true;
}

}  // namespace isogram
