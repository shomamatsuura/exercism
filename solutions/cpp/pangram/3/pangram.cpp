#include "pangram.h"
#include <cctype>
namespace pangram {

bool is_pangram(std::string_view sentence){
    int alphabet{0};
    const int ALL_ONE = (1 << 26) - 1;
    for(auto c : sentence){
        if(std::isalpha(c)){
            c = std::tolower(c);
            alphabet |= (1 << (c - 'a'));
        }
    }
    return alphabet == ALL_ONE;
}

}  // namespace pangram
