#include "scrabble_score.h"
#include <map>
#include <cctype>
namespace scrabble_score {

static const std::map<unsigned char, unsigned int> letter_value{
    {'A', 1}, {'E', 1}, {'I', 1}, {'O', 1}, {'U', 1}, {'L', 1}, {'N', 1}, {'R', 1}, {'S', 1}, {'T', 1}, {'D', 2}, {'G', 2}, {'B', 3}, {'C', 3}, {'M', 3}, {'P', 3}, {'F', 4}, {'H', 4}, {'V', 4}, {'W', 4}, {'Y', 4}, {'K', 5},{'J', 8},{'X', 8},{'Q', 10},{'Z', 10}
};

unsigned int score(std::string_view word){
    unsigned int result{0};
    for(unsigned char c : word){
        c = std::toupper(c);
        result += letter_value.at(c);

        // if(std::isalpha(c)){
        //     c = std::isupper(c);
        //     result += letter_value.at(c);

        //     if(letter_value.find(c) != letter_value.end()){
        //         result += letter_value.at(c);
        //     }            
        // }

    }
    return result;
}

}  // namespace scrabble_score
