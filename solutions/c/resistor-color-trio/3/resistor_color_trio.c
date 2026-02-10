#include "resistor_color_trio.h"

static resistor_unit_t get_unit(resistor_band_t band){
    return band / 3;
}

static uint16_t get_multiplier(resistor_band_t band){
    switch (band %3){
        case 0: return 1;
        case 1: return 10;
        default: return 100;    // case 2
    }
}

resistor_value_t color_code(resistor_band_t *colors){
    resistor_value_t result;
    result.value = (colors[0] * 10 + colors[1]) * get_multiplier(colors[2]);
    result.unit = get_unit(colors[2]);

    if(result.value != 0 && result.value % 1000 == 0){
        result.value /= 1000;
        ++result.unit;
    }
    return result;
}