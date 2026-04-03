#include "grains.h"
#include <stdexcept>
namespace grains {

unsigned long long square(unsigned int num){
    if(num < 1 || num > 64){
        throw std::domain_error("square must be between 1 and 64");
    }
    return 1ULL << (num - 1);
}
unsigned long long total(){
    return (1ULL << 63) * 2 - 1;
}


}  // namespace grains
