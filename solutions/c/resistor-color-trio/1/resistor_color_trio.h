#ifndef RESISTOR_COLOR_TRIO_H
#define RESISTOR_COLOR_TRIO_H
#include <stdint.h>
typedef enum {
    BLACK,
    BROWN,
    RED,
    ORANGE,
    YELLOW,
    GREEN,
    BLUE,
    VIOLET,
    GREY,
    WHITE
} resistor_band_t;

typedef enum {
    OHMS = 0,
    KILOOHMS = 1,
    MEGAOHMS = 2,
    GIGAOHMS = 3
} ohm_unit;

typedef struct {
    uint16_t value;
    ohm_unit unit;
} resistor_value_t;

resistor_value_t color_code(resistor_band_t *colors);
#endif
