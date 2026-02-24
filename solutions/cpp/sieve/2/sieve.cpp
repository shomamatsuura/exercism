#include "sieve.h"
namespace sieve {

std::vector<int> primes(int limit){
    // Early exit for invalid limits
    if(limit < 2) return {};
    
    std::vector<bool> is_prime(limit + 1, true);
    std::vector<int> result;

    result.reserve(limit / 2);
    // use long long to prevent integer overflow when calculating p * p
    for(long long p = 2; p <= limit; ++p){
        if(is_prime[p]){
            result.emplace_back(static_cast<int>(p));
            for(long long i = p * p; i <= limit; i += p){
                is_prime[i] = false;
            }
        }
    }
    return result;

}

}  // namespace sieve
