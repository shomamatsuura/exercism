#include "dnd_character.h"
#include <algorithm>
#include <array>
#include <cmath>
#include <numeric>
#include <random>
namespace dnd_character {

    int modifier(int score){
        return std::floor((score - 10) / 2.0);
    }
    int ability(){
        static std::random_device rd;
        static std::mt19937 gen(rd());
        std::uniform_int_distribution<> die(1, 6);

        std::array<int, 4> rolls;
        for(int &die_roll : rolls){
            die_roll = die(gen);
        }

        int lowest = *std::min_element(rolls.begin(), rolls.end());
        int sum = std::accumulate(rolls.begin(), rolls.end(), 0);
        return sum - lowest;
    }
    Character::Character(){
        strength = ability();
        dexterity = ability();
        constitution = ability();
        intelligence = ability();
        wisdom = ability();
        charisma = ability();
        hitpoints = 10 + modifier(constitution);  
    }
}  // namespace dnd_character
