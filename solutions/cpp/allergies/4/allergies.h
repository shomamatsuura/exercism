#pragma once
#include <string>
#include <string_view>
#include <unordered_set>
#include <vector>

namespace allergies {

class allergy_test{
    private:
        int total_score;
        const std::vector<std::string> items = {"eggs", "peanuts", "shellfish", "strawberries", "tomatoes", "chocolate", "pollen", "cats"};
    public:
        allergy_test(int score){
            total_score = score;
        }
        int find_closest_power(int num);
        bool is_allergic_to(std::string_view item);
        std::unordered_set<std::string> get_allergies();
        
};

}  // namespace allergies
