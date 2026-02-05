#include "resistor_color.h"
#include <stdio.h>


int color_code(resistor_band_t color){
    return color;
}

resistor_band_t* colors(void){
    static resistor_band_t allColors[] = {BLACK, BROWN, RED, ORANGE, YELLOW, GREEN, BLUE, VIOLET, GREY, WHITE};
    return allColors;
}

