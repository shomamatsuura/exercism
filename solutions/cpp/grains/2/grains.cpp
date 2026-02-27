#include "grains.h"
#include <stdexcept>
namespace grains {
    unsigned long long square(int num){
        if(num < 1 || num > 64){
            throw std::domain_error("square must be between 1 and 64");
        }
        
        // Shift the bit left by (num - 1) places
        return 1ULL << (num - 1);
    }
    unsigned long long total(){
        // Sum of geometric series: 2^64 - 1
        return (1ULL << 63) * 2 - 1;
    }

}  // namespace grains
