#include "prime_factors.h"

namespace prime_factors {

std::vector<long long> of(unsigned long long num){
    if(num < 2) return {};
    std::vector<long long> result{};
    for(unsigned long long i{2}; i <= num; ++i){
        while(num % i == 0){
            result.emplace_back(i);
            num /= i;
        }
    }
    return result;
    
}

}  // namespace prime_factors
