#include "yacht.h"
#include <algorithm>
#include <array>
#include <numeric>


namespace yacht {

// Sum all dice
static int calculate_sum(const std::vector<int>& dice){
    return std::accumulate(dice.begin(), dice.end(), 0);
}
    
int score(const std::vector<int>& dice, std::string_view category) {
    // Create a frequency map for dice 1-6
    std::array<int, 7> face_counts{0};
    for(int die : dice){
        ++face_counts[die];
    }
    
    if(category == "ones") return face_counts[1] * 1;
    if(category == "twos") return face_counts[2] * 2;
    if(category == "threes") return face_counts[3] * 3;
    if(category == "fours") return face_counts[4] * 4;
    if(category == "fives") return face_counts[5] * 5;
    if(category == "sixes") return face_counts[6] * 6;
    
    
    if(category == "full house"){
        bool has_two = false, has_three = false;
        for(int count : face_counts){
            if(count == 2) has_two = true;
            if(count == 3) has_three = true;
            
        }
        return (has_two && has_three) ? calculate_sum(dice) : 0;
    }
    if(category == "four of a kind"){
        for(std::size_t face{1}; face < face_counts.size(); ++face){
            if(face_counts[face] >= 4) return face * 4;
        }
        return 0;
    }
    if(category == "little straight"){
        for(int face{1}; face < 6; ++face){
            if(face_counts[face] != 1) return 0;
        }
        return 30;
    }
    if(category == "big straight") {
        for(int face{2}; face <= 6; ++face){
            if(face_counts[face] != 1) return 0;
        }
        return 30;        
    }
    if(category == "choice"){
        return calculate_sum(dice);
    }
    if(category == "yacht"){
        for(int count : face_counts){
            if(count == 5) return 50;
        }
        return 0;                  
    }
    return 0;
}

}  // namespace yacht
