#include "diamond.h"
#include <cctype>
namespace diamond {

std::vector<std::string> rows(char letter){
    if(!std::isupper(letter)) return {};
    if(letter == 'A') return {"A"};
    
    std::size_t length = (letter - 'A' + 1) * 2 - 1;  
    std::vector<std::string> result(length, "");

    for(std::size_t i{0}; i <= static_cast<std::size_t>(letter - 'A'); ++i){
        std::string horizon{""};
        std::size_t space_count = (i == 0 )? length - 1 : length - 2;
        
        std::size_t center_space_count = (i == 0 )? 0 : 2 * i - 1;
        std::size_t side_space_count = (space_count - center_space_count) / 2;
        for(std::size_t j{0}; j < side_space_count; ++j){
            horizon += " ";
        }
        horizon += (i + 'A');
        
        for(std::size_t j{0}; j < center_space_count; ++j){
            horizon += " ";
        }
        
        if(i != 0) horizon += (i + 'A');
        for(std::size_t j{0}; j < side_space_count; ++j){
            horizon += " ";
        }
        result.at(i) = horizon;
        result.at(length - 1 - i) = horizon;
        
    }

    return result;
}

}  // namespace diamond
