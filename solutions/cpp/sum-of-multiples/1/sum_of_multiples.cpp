#include "sum_of_multiples.h"
#include <map>
namespace sum_of_multiples {

unsigned int to(std::vector<unsigned int> base_values, unsigned int level){
    if(base_values.empty()) return 0;
    unsigned int result{0};
    std::map<unsigned int, unsigned int> multiples{};
    for(auto base : base_values){
        unsigned int multiple = base;
        while(multiple < level){
            if(multiples.count(multiple) == 0){
                multiples.insert({multiple, multiple});
                result += multiple;
            }
            multiple+= base;
        }
    }    
    return result;
}


}  // namespace sum_of_multiples
