#include "etl.h"
#include <cctype>
namespace etl {

std::map<char, int> transform(const std::map<int, std::vector<char>>& old){
    std::map<char, int> new_map{};
    for(const auto& one_to_many_mapping : old){
        for(const auto& letter : one_to_many_mapping.second){
            new_map.insert({std::tolower(letter),  one_to_many_mapping.first});
        }
    }
    return new_map;
}

}  // namespace etl
