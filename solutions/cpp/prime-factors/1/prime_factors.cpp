#include "prime_factors.h"

namespace prime_factors {

std::vector<long long> of(long num){
    std::vector<long long> result;
    if(num <= 1) return {};
    for(long i = 2; i <= num; ++i){
        while(num % i == 0){
            num /= i;
            result.emplace_back(i);
        }
    }
    return result;
}

}  // namespace prime_factors
