#include "space_age.h"
#include <math.h>

float age(planet_t planet, int64_t seconds){
    if(planet < 0 || planet > 7) return -1;
    float orbitalInEarthYearArray[] = {0.2408467f, 0.61519726f, 1.0f, 1.8808158f, 11.862615f, 29.447498f, 84.016846f, 164.79132f};
    float orbitalInEarthYear = orbitalInEarthYearArray[planet];
    const int EARTHEARYSECONDS = 31557600;
    return round((seconds / orbitalInEarthYear / EARTHEARYSECONDS) * 100) / 100;
    
}

