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
            bool is_allergic_to(const std::string& item) const;
            std::unordered_set<std::string> get_allergies() const;
    };

}  // namespace allergies
