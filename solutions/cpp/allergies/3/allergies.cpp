#include "allergies.h"

namespace allergies {
    // Define the items and their bit values in a fixed list
    static const std::vector<std::pair<unsigned int, std::string>> ALLERGENS = {
        {1, "eggs"},
        {2, "peanuts"},
        {4, "shellfish"},
        {8, "strawberries"},
        {16, "tomatoes"},
        {32, "chocolate"},
        {64, "pollen"},
        {128, "cats"}
    };
    allergy_test::allergy_test(unsigned int score): score_(score){}
    
    bool allergy_test::is_allergic_to(const std::string& item) const {
        for(const auto& allergen : ALLERGENS){
            if(allergen.second == item){
                // Check if the bit for this allergen is set in the score
                return (score_ & allergen.first) != 0;
            }
        }
        return false;
    }
    
    std::unordered_set<std::string> allergy_test::get_allergies() const {
        std::unordered_set<std::string> result;
        for(const auto& allergen : ALLERGENS){
            // Bitwise check: ignores bits 256, 512, etc. automatically
            // because we only iterate through the know 1-128 values.
            if((score_ & allergen.first) != 0){
                result.emplace(allergen.second);
            }
        }
        return result;
    }


}  // namespace allergies
