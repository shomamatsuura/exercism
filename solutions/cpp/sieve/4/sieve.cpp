#include "sieve.h"
namespace sieve {

std::vector<int> primes(const int  limit){
    std::vector<int> result{};
    result.reserve(limit / 2);
    if(limit < 2) return result;    
    
    std::vector<bool> is_prime(limit + 1, true);
    for(long long p{2}; p <= limit; ++p){
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
