#include "pangram.h"
#include <bitset>
#include <cctype>
namespace pangram {

bool is_pangram(std::string_view sentence){
    std::bitset<26> letters;
    for(const auto c : sentence){
        if(std::isalpha(c)){
            letters.set(std::tolower(c) - 'a');
        }
    }
    return letters.all();
}

}  // namespace pangram
