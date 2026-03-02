#include "perfect_numbers.h"
#include <stdexcept>
namespace perfect_numbers {
    classification classify(int num){
        if(num <= 0) throw std::domain_error("Input must be a postivie integer.");
        if(num == 1) return classification::deficient;
        
        long long aliquot_sum{1};
        for(int i{2}; i * i <= num; ++i){
            if(num % i == 0){
                aliquot_sum += i;
                if(i * i != num){
                    aliquot_sum += num / i;
                }
            }
        }
        if(num == aliquot_sum) return classification::perfect;
        return (num < aliquot_sum) ? classification::abundant : classification::deficient;

    }
        
}  // namespace perfect_numbers
