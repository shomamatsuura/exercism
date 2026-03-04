#include "perfect_numbers.h"
#include <stdexcept>
namespace perfect_numbers {
    classification classify(int num){
        if(num <= 0) throw std::domain_error("The input number should be postivie integer.");
        if(num == 1) return classification::deficient;
        int aliquot_sum{1};
        for(int i{2}; i * i <= num; ++i){
            if(num % i == 0){
                aliquot_sum += i;
                if(i != num / i){
                    aliquot_sum += num / i;
                }
            }
        }
        if(num == aliquot_sum) return classification::perfect;
        else if(num < aliquot_sum) return classification::abundant;
        else return classification::deficient;
    }
        
}  // namespace perfect_numbers
