#pragma once
#include <string>
#include <unordered_set>
#include <vector>

namespace allergies {

    class allergy_test{
        private:
            unsigned int score_;
        public:
            explicit allergy_test(unsigned int score);
            // Returns if the person is allergic to a specific item
            bool is_allergic_to(const std::string& item) const;
            // Returns the full set of allergies
            std::unordered_set<std::string> get_allergies() const;
    };

}  // namespace allergies
