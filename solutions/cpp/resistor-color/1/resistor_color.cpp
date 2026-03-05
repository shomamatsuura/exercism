#include "resistor_color.h"
#include <map>

namespace resistor_color {

// enum class encoded_colors{
//     black = 0,
//     brown = 1,
//     red = 2,
//     orange = 3,
//     yellow = 4,
//     green = 5,
//     blue = 6,
//     violet = 7,
//     grey = 8,
//     white = 9
// };
static const std::map<int, std::string> encoded_colors{
    // {"black", 0},
    // {"brown", 1},
    // {"red", 2},
    // {"orange", 3},
    // {"yellow", 4},
    // {"green", 5},
    // {"blue", 6},
    // {"violet", 7},
    // {"grey", 8},
    // {"white", 9}
    {0, "black"},
    {1, "brown"},
    {2, "red"},
    {3, "orange"},
    {4, "yellow"},
    {5, "green"},
    {6, "blue"},
    {7, "violet"},
    {8, "grey"},
    {9, "white"}
};

int color_code(const std::string& color){
    for(auto it = encoded_colors.begin(); it != encoded_colors.end(); ++it){
        if(it->second == color) return it->first;
    }
    return -1;
    
}
std::vector<std::string> colors(){
    std::vector<std::string> result;
    for(auto it = encoded_colors.begin(); it != encoded_colors.end(); ++it){
        result.emplace_back(it->second);  
    }
    // for(auto it : encoded_colors){
    //     result.emplace_back(it.first);    
    // }
    return result;
}
}  // namespace resistor_color
