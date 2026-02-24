#include "kindergarten_garden.h"

namespace kindergarten_garden {
    static const std::unordered_map<std::string, unsigned int> students = {
        {"Alice", 0},
        {"Bob", 2},
        {"Charlie", 4},
        {"David", 6},
        {"Eve", 8},
        {"Fred", 10},
        {"Ginny", 12},
        {"Harriet",  14},
        {"Ileana",  16},
        {"Joseph", 18},
        {"Kincaid", 20},
        {"Larry",  22}
    };
    // static const std::unordered_map<char, Plants>  plant_pair = {
    //     {'G', Plants::grass},
    //     {'C', Plants::clover},
    //     {'R', Plants::radishes},
    //     {'V', Plants::violets}
    // };
    static const std::unordered_map<std::string, Plants>  plant_pair = {
        {"G", Plants::grass},
        {"C", Plants::clover},
        {"R", Plants::radishes},
        {"V", Plants::violets}
    };    
    std::array<kindergarten_garden::Plants, 4> plants(const std::string& garden, const std::string& name){
        std::array<kindergarten_garden::Plants, 4> result;
        unsigned int start_idx = students.at(name);
        
        result.at(0) = plant_pair.at(garden.substr(start_idx, 1));
        result.at(1) = plant_pair.at(garden.substr(start_idx + 1, 1));
        
        unsigned int start_idx_second_row = garden.find("\n") + 1 + students.at(name);
        result.at(2) = plant_pair.at(garden.substr(start_idx_second_row, 1));
        result.at(3) = plant_pair.at(garden.substr(start_idx_second_row + 1, 1));
        return result;
            
    }
}  // namespace kindergarten_garden
