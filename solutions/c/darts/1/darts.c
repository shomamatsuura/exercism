#include "darts.h"
#include <math.h>
#include <stdio.h>

uint8_t score(coordinate_t landing_position){
    uint8_t resultScore = 0;
    double distance = sqrt(pow(landing_position.x, 2) + pow(landing_position.y, 2));
    if(distance <= 1) {
        resultScore = 10;
    } else if(distance <= 5){
        resultScore = 5;
    } else if(distance <= 10){
        resultScore = 1;
    }
    return resultScore;
}