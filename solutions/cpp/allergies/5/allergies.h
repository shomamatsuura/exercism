#pragma once
#include <string>
#include <string_view>
#include <unordered_set>
#include <vector>

namespace allergies {

class allergy_test{
    private:
        int score_;
    public:
        explicit allergy_test(unsigned int score);
        bool is_allergic_to(std::string_view item) const;
        std::unordered_set<std::string> get_allergies() const ;
        
};

}  // namespace allergies
