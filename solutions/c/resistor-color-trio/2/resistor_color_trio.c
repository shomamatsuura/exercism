#include "resistor_color_trio.h"

resistor_value_t color_code(resistor_band_t *colors){
    uint8_t second_color = colors[1];
    uint8_t third_color = colors[2];
    
    uint32_t num_zeros = second_color == BLACK ? third_color + 1 : third_color;
    uint8_t unit = num_zeros / 3;

    uint8_t power = second_color == BLACK ? num_zeros % 3 : num_zeros % 3 + 1;
    uint64_t value = 0;
    for(int i = 0; i < 2; i++){
        uint64_t muliplier = 1;
        for(int i = 0; i < power; i++){
            muliplier *= 10;
        }
        value += (muliplier * colors[i]);
        --power;
    }
    
    resistor_value_t resistor_value = {
        resistor_value.value = value,
        resistor_value.unit = unit
    };
    return resistor_value;
}