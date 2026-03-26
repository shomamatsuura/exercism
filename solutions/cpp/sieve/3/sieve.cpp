#include "sieve.h"
namespace sieve {

std::vector<int> primes(const unsigned int  num){
    std::vector<int> result{};
    if(num < 2) return result;
    
    std::vector<bool> prime_vector{};
    for(unsigned int  i{0}; i < num + 1; ++i){
        prime_vector.emplace_back(true);
    }
    
    for(unsigned int i{2}; i < prime_vector.size(); ++i){
        if(prime_vector.at(i) == false){
            continue;
        }

        unsigned int j{2};
        while(i * j < prime_vector.size()){
            prime_vector.at(i * j) = false;
            ++j;
        }
        
    }
    for(unsigned int i{2}; i < prime_vector.size(); ++i){
        if(prime_vector.at(i)) result.emplace_back(i);
    }
    return result;
}

}  // namespace sieve
