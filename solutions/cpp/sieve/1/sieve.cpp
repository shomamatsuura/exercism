#include "sieve.h"
namespace sieve {

std::vector<int> primes(const size_t num){
    if(num < 2) return {};
    std::vector<bool> is_prime_array(num + 1, true);
    
    for(size_t i = 2; i <= num; ++i){
        if(is_prime_array.at(i)) {
            int j = 2;
            while(i * j <= num){
                is_prime_array.at(i * j) = false;
                ++j;
            }
        }
    }
    std::vector<int> result;
    for(size_t i = 2; i <= num; ++i){
        if(is_prime_array.at(i)){
            result.emplace_back(i);
        }
    }
    return result;
}

}  // namespace sieve
