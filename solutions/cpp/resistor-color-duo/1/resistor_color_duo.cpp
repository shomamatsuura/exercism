#include "resistor_color_duo.h"

namespace resistor_color_duo {

const static std::vector<std::string> resistor_colors {
    "black", "brown", "red", "orange", "yellow", "green", "blue", "violet", "grey", "white"
};

int value(std::vector<std::string> colors){
    int first_value{0};
    int second_value{0};
    
    for(size_t i{0}; i < resistor_colors.size(); ++i){
        if(colors.at(0) == resistor_colors.at(i)){
            first_value = i;
        }
        if(colors.at(1) == resistor_colors.at(i)){
            second_value = i;
        }
    }
    return first_value * 10 + second_value; 
}

}  // namespace resistor_color_duo
