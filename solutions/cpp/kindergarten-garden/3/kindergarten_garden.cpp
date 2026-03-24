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
        std::array<kindergarten_garden::Plants, 4> result;
        int child_index{-1};
        
        for(unsigned int i{0}; i < children.size(); ++i){
            if(child == children.at(i)) child_index = i;
        }
        
        if(child_index == -1) throw std::domain_error("The child name is invalid");
        unsigned int first_row = 2 * child_index;
        unsigned int second_row = cups.find('\n') + 1 + first_row;

         
        for(unsigned int i{0}; i < cups.size(); ++i){
            if(i == first_row){
                result.at(0) = plant_encoding.at(cups.at(i));
                result.at(1) = plant_encoding.at(cups.at(i+1)); 
            } else if(i == second_row){
                result.at(2) = plant_encoding.at(cups.at(i));
                result.at(3) = plant_encoding.at(cups.at(i+1));
            }
        }
        
        return result;
    }

}  // namespace kindergarten_garden
