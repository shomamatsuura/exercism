#include "allergies.h"

namespace allergies {

    bool allergy_test::is_allergic_to(std::string item){
        score -= item_map.at(item);
        if(score == 0) return true;

        unsigned int count = 0;
        std::unordered_set<int> score_binary_set{};
        while(score != 0){
            if((score & 1 )== 1){
                score_binary_set.emplace(count);
            }
            ++count;
            score >>= 1;
        }
        
        for(auto score_binary: score_binary_set){
            bool value_exist = false;
            unsigned int item_value{1};
            
            for(int i = 0; i < score_binary; ++i){
                 item_value *= 2;
            }
            for(auto iter : item_map){
                if(iter.first != item && iter.second == item_value) value_exist = true;
            }
            if(!value_exist) return false;
        }
        return true;
    }
    std::unordered_set<std::string> allergy_test::get_allergies(){
        std::unordered_set<std::string> allergy_set{};

        unsigned int count = 0;
        std::unordered_set<int> score_binary_set{};
        while(score != 0){
            if((score & 1 )== 1){
                score_binary_set.emplace(count);
            }
            ++count;
            score >>= 1;
        }
        
        for(auto score_binary: score_binary_set){
            unsigned int item_value{1};
            
            for(int i = 0; i < score_binary; ++i){
                 item_value *= 2;
            }
            for(auto iter : item_map){
                if(iter.second == item_value){
                    allergy_set.emplace(iter.first);
                }
            }
        }
        
        return allergy_set;
    }


}  // namespace allergies
