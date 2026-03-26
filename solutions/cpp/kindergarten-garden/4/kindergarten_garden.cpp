#include "kindergarten_garden.h"
#include <map>
#include <stdexcept>
namespace kindergarten_garden {
    const std::array<std::string_view, 12> children = {"Alice", "Bob", "Charlie", "David", "Eve", "Fred", "Ginny", "Harriet", "Ileana", "Joseph", "Kincaid", "Larry"};
    const std::map<char, Plants> plant_encoding = {
        {'C', Plants::clover},
        {'G', Plants::grass},
        {'V', Plants::violets},
        {'R', Plants::radishes}
    };
    std::array<Plants, 4> plants(std::string_view cups, std::string_view child){
        int child_index{-1};
        
        for(unsigned int i{0}; i < children.size(); ++i){
            if(child == children.at(i)) child_index = i;
        }
        
        if(child_index == -1) throw std::domain_error("The child name is invalid");
        unsigned int first_row = 2 * child_index;
        unsigned int second_row = cups.find('\n') + 1 + first_row;

        return {plant_encoding.at(cups.at(first_row)), plant_encoding.at(cups.at(first_row + 1)),
            plant_encoding.at(cups.at(second_row)), plant_encoding.at(cups.at(second_row + 1))};
    }

}  // namespace kindergarten_garden
