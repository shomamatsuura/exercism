#include "space_age.h"
#include <math.h>

float age(planet_t planet, int64_t seconds){
    if(planet < 0 || planet > 7) return -1;
    double orbitalInEarthYearArray[] = {0.2408467, 0.61519726, 1.0, 1.8808158, 11.862615, 29.447498, 84.016846, 164.79132};
    double orbitalInEarthYear = orbitalInEarthYearArray[planet];
    const int EARTHEARYSECONDS = 31557600;
    return round((seconds / orbitalInEarthYear / EARTHEARYSECONDS) * 100) / 100;
    
}

