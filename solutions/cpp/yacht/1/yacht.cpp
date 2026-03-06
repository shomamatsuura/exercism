#include "yacht.h"
#include <map>
namespace yacht {

static unsigned int score_specific_num(std::vector<unsigned int> dice, unsigned int target_num){
    int count{0};
    for(auto die : dice){
        if(die == target_num) ++count;
    }
    return count * target_num;
}
static unsigned int score_full_house(std::vector<unsigned int> dice){
    std::map<unsigned int, unsigned int> dice_count = {{1, 0}, {2, 0}, {3, 0}, {4, 0}, {5, 0}, {6, 0}};
    unsigned int total{0};
    for(auto die : dice){
        ++dice_count.at(die);
        total += die;
    }
    unsigned int three_num{0};
    unsigned int two_num{0};
    for(const auto& [die_num, count] : dice_count){
        if(count == 2){
            two_num = die_num;
        }
        if(count == 3){
            three_num = die_num;
        } 
    }
    return (three_num != 0 && two_num != 0) ? total : 0;
}
static unsigned int score_four_of_a_kind(std::vector<unsigned int> dice){
    std::map<unsigned int, unsigned int> dice_count = {{1, 0}, {2, 0}, {3, 0}, {4, 0}, {5, 0}, {6, 0}};
    for(auto die : dice){
        ++dice_count.at(die);
    }

    for(const auto& [die_num, count] : dice_count){
        if(count== 4 || count== 5){
            return 4 * (die_num);
        }

    }
    return 0;
}
static unsigned int score_little_straight(std::vector<unsigned int> dice){
    std::map<unsigned int, unsigned int> dice_count = {{1, 0}, {2, 0}, {3, 0}, {4, 0}, {5, 0}, {6, 0}};
    for(auto die : dice){
        if(die == 6) return 0;
        if(dice_count.at(die) == 1) return 0;
        ++dice_count.at(die);
    }
    return 30;
}
static unsigned int score_big_straight(std::vector<unsigned int> dice){
    std::map<unsigned int, unsigned int> dice_count = {{1, 0}, {2, 0}, {3, 0}, {4, 0}, {5, 0}, {6, 0}};
    for(auto die : dice){
        if(die == 1) return 0;
        if(dice_count.at(die) == 1) return 0;
        ++dice_count.at(die);
    }
    return 30;
}
static unsigned int score_choice(std::vector<unsigned int> dice){
    unsigned int sum{0};
    for(auto die : dice){
        sum += die;
    }
    return sum;
} 
static unsigned int score_yacht(std::vector<unsigned int> dice){
    unsigned int num = dice.at(0);
    for(std::size_t i{1}; i < dice.size(); ++i){
        if(num != dice.at(i)) return 0;
    }
    return 50;
} 
    
unsigned int score(std::vector<unsigned int> dice, std::string_view category){
    if(category == "ones") return score_specific_num(dice, 1);
    else if(category == "twos") return score_specific_num(dice, 2);
    else if(category == "threes") return score_specific_num(dice, 3);
    else if(category == "fours") return score_specific_num(dice, 4);
    else if(category == "fives") return score_specific_num(dice, 5);
    else if(category == "sixes") return score_specific_num(dice, 6);
    else if(category == "full house") return score_full_house(dice);
    else if(category == "four of a kind") return score_four_of_a_kind(dice);
    else if(category == "little straight") return score_little_straight(dice);
    else if(category == "big straight") return score_big_straight(dice);
    else if(category == "choice") return score_choice(dice);
    else if(category == "yacht") return score_yacht(dice);
    else return 0;
}

}  // namespace yacht
