#include "sum_of_multiples.h"
#include <vector>
namespace sum_of_multiples {

unsigned int to(const std::vector<unsigned int>& base_values, unsigned int level){
    if(level == 0) return 0;
    unsigned int sum{0};

    std::vector<bool> found(level, false);
    
    for(auto base : base_values){
        if(base == 0) continue;
        for(unsigned int multiple = base; multiple < level; multiple += base){
            if(!found[multiple]){
                sum += multiple;
                found[multiple] = true;
            }

        }
    }    
    return sum;
}


}  // namespace sum_of_multiples
