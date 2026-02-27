#include "etl.h"
#include <cctype>
namespace etl {

std::map<char, int> transform(std::map<int, std::vector<char>> old){
    std::map<char, int> new_map{};
    for(std::pair<int, std::vector<char>> one_to_many_mapping : old){
        for(char letter : one_to_many_mapping.second){
            new_map.insert({std::tolower(letter),  one_to_many_mapping.first});
        }
    }
    return new_map;
}

}  // namespace etl
