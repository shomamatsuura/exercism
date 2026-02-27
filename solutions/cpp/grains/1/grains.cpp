#include "grains.h"

namespace grains {
    unsigned long long square(int num){
        if(num == 0) return 0;
        unsigned long long result{1};
        for(int i = 1; i < num; ++i){
            result *= 2;
        }
        return result;
    }
    unsigned long long total(){
        unsigned long long total_grains{0};
        for(int i = 1; i <= 64; ++i){
            total_grains += square(i);
        }
        return total_grains;
    }

}  // namespace grains
