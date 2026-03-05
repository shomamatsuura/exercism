#include "resistor_color.h"


namespace resistor_color {

static const std::vector<std::string> resistor_color{"black", "brown", "red", "orange", "yellow", "green", "blue", "violet", "grey", "white"};

int color_code(std::string_view color){
    for(std::size_t i{0}; i < resistor_color.size(); ++i){
        if(color == resistor_color.at(i)){
            return i;
        }
    }
    return -1;
    
}
std::vector<std::string> colors(){
 
    return resistor_color;
}
}  // namespace resistor_color
