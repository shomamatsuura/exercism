#include "allergies.h"
#include <cmath>
#include <stdexcept>
namespace allergies {
    int allergy_test::find_closest_power(int num){
        int power = 0;
        while(std::pow(2, power) <= num){
            ++power;
        }
        return power - 1;
    }
    bool allergy_test::is_allergic_to(std::string_view item){
        int item_index{-1};
        for(unsigned int i{0}; i < items.size(); ++i){
            if(item == items.at(i)) item_index = i;
        }
        if(item_index == -1) throw std::domain_error("Invalid parameter.");
        int value = std::pow(2, item_index);
        if(total_score == value) return true;
        else if(total_score < value) return false;
        else{
            int remain = total_score - value;
            int power = find_closest_power(remain);
            if(power == item_index){
                --power;
            }
            if(power < 0) return false;            
            for(int i{power}; i >= 0; --i){                
                if(i == item_index){
                    continue;
                }
                remain -= std::pow(2, i);
                if(remain == 0) return true;
            }
            return remain == 0;
        }
    }

    std::unordered_set<std::string> allergy_test::get_allergies(){
        std::unordered_set<std::string> result{};
        while(total_score != 0){
            int power = find_closest_power(total_score);
            if(power >= 0 && power <= 7){
                result.emplace(items.at(power));
            }
            if(std::pow(2, power) == total_score){
                return result;   
            }
            total_score -= std::pow(2, power);
        }
        
        return result;
    }


}  // namespace allergies

