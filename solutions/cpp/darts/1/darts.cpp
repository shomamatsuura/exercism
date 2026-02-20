#include "darts.h"

namespace darts {

float score(float x, float y){
    float squared_postion = x * x + y * y;
    if(squared_postion > 10 * 10) return 0;
    else if(squared_postion > 5 * 5) return 1;
    else if(squared_postion > 1 * 1) return 5;
    else return 10;
}

}  // namespace darts
