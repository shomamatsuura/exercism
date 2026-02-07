#include "darts.h"
#include <math.h>
#include <stdio.h>

uint8_t score(coordinate_t landing_position){
    uint8_t resultScore = 0;
    double x = landing_position.x;
    double y = landing_position.y;
    double dist2 = x * x + y * y;
    
    if(dist2 <= 1.0 * 1.0) {
        resultScore = 10;
    } else if(dist2 <= 5 * 5){
        resultScore = 5;
    } else if(dist2 <= 10 * 10){
        resultScore = 1;
    }
    return resultScore;
}