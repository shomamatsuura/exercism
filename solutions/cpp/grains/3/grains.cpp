#include "grains.h"

namespace grains {

unsigned long long square(unsigned int num){
    unsigned long long result{1};
    for(unsigned int i{0}; i < num - 1; ++i){
        result *= 2;
    }
    return result;
}
unsigned long long total(){
    return square(64) * 2 -1;
}


}  // namespace grains
