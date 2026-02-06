#include "resistor_color_duo.h"


uint16_t color_code(resistor_band_t *pResistorBand){
    return pResistorBand[0] * 10 + pResistorBand[1];
}