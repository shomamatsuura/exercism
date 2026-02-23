#pragma once
#include <string>
#include <vector>
#include <unordered_set>
#include <unordered_map>


namespace allergies {
    static const std::unordered_map<std::string, unsigned int> item_map = {
        {"eggs", 1},
        {"peanuts", 2},
        {"shellfish", 4},
        {"strawberries", 8},
        {"tomatoes", 16},
        {"chocolate", 32},
        {"pollen", 64},
        {"cats", 128}
    };
    class allergy_test{
        private:
            unsigned int score;
        public:
            allergy_test(unsigned int s){
                 score = s;
            }
            bool is_allergic_to(std::string item);
            std::unordered_set<std::string> get_allergies();
    };

}  // namespace allergies
