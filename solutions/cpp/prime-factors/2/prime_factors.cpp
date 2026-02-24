#include "prime_factors.h"

namespace prime_factors {

std::vector<long long> of(long num){
    std::vector<long long> result;
    if(num <= 1) return {};
    while(num % 2 == 0){
        result.emplace_back(2);
        num /= 2;
    }
    for(long long i = 3; i * i <= num; i +=2){
        while(num % i == 0){
            result.emplace_back(i);
            num /= i;
        }
    }
    if(num > 2){
        result.emplace_back(num);
    }
    return result;
}

}  // namespace prime_factors
