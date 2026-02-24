#include "kindergarten_garden.h"
#include <stdexcept>
namespace kindergarten_garden {
    Plants char_to_plant(char c){
        switch(c){
            case 'G': 
                return Plants::grass;
            case 'C': 
                return Plants::clover;
            case 'R': 
                return Plants::radishes;
            case 'V': 
                return Plants::violets;
            default:
                throw std::invalid_argument("Unknown plant code");
        }
    }
    
    std::array<Plants, 4> plants(const std::string& garden, const std::string& name){
        int student_index = name[0] - 'A';
        
        // Each student gets 2 plants per row, so multiply index by 2
        int top_row_start = student_index * 2;

        // Find the start of the second row (right after the newline)
        size_t bottom_row_offset = garden.find('\n')  + 1;
        int bottom_row_start = bottom_row_offset + top_row_start;
        return {
            char_to_plant(garden[top_row_start]),
            char_to_plant(garden[top_row_start + 1]),
            char_to_plant(garden[bottom_row_start]),
            char_to_plant(garden[bottom_row_start + 1])
        };
        
    }
        
}  // namespace kindergarten_garden
