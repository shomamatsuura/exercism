#include "resistor_color_duo.h"


uint16_t color_code(resistor_band_t *pResistorBand){
    uint16_t firstDigit = (uint16_t)pResistorBand[0];
    uint16_t secondDigit = (uint16_t)pResistorBand[1];
    return firstDigit * 10 + secondDigit;
}