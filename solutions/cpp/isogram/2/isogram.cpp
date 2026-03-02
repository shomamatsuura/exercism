#include "isogram.h"
#include <cctype>
#include <bitset>
namespace isogram {

bool is_isogram(std::string_view word){
    std::bitset<26> alphabet;
    for(auto c : word){
        if(std::isalpha(c)){
            c = std::tolower(c);
            if(alphabet[c-'a'] == 1) return false;
            else{
                alphabet[c-'a'] = 1;
            }
        }
    }
    return true;
}

}  // namespace isogram
