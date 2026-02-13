#include "resistor_color_trio.h"
resistor_value_t color_code(resistor_band_t *resistor_bands){
    uint16_t value = resistor_bands[0] * 10 + resistor_bands[1];

    resistor_unit_t unit = resistor_bands[2] / 3; 

    if(resistor_bands[2] % 3 == 1) value *= 10;
    else if(resistor_bands[2] % 3 == 2) value *= 100;

    if(value > 0 && value % 1000 == 0){
        value /= 1000;
        ++unit;
    }
        
    resistor_value_t trio = {.value = value, .unit = unit};
    return trio;
    
}