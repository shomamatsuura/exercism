#include "resistor_color_trio.h"

resistor_value_t color_code(resistor_band_t *colors){
    uint16_t first_color = colors[0];
    uint16_t second_color = colors[1];
    uint16_t third_color = colors[2];

    uint32_t digits;
    if(first_color == BLACK) {
        if(second_color == BLACK){
            resistor_value_t resistor_value = {
                resistor_value.value = 0,
                resistor_value.unit = OHMS
            };
            return resistor_value;
        } else{
            digits = 1 + third_color;
        }
    } else{
        digits = 2 + third_color;
    }

    uint64_t total_value = 0;
    int power = digits - 1;
    for(int i = 0; i < 2; ++i){
        uint64_t multiplier = 1;
        for(int j = 0; j < power; ++j ){
            multiplier *= 10;
        }
        total_value += (colors[i] * multiplier);
        --power;
    }

    uint32_t num_zeros;
    if(second_color == BLACK){
        num_zeros = digits - 1;
    } else if(third_color == BLACK){
        num_zeros = digits;
    } else{
        num_zeros = digits - 2;
    }
    uint8_t unit = num_zeros / 3;
    uint64_t value = total_value;
    for(int i = 0; i < (unit * 3); ++i){
        value /= 10;
    }
    
    resistor_value_t resistor_value = {
        resistor_value.value = value,
        resistor_value.unit = unit
    };
    return resistor_value;
}