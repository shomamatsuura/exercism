#pragma once
#include <cmath>
#include <cstdlib>
namespace dnd_character {
    class Character{
        public:
            int strength;
            int dexterity;
            int constitution;
            int intelligence;
            int wisdom;
            int charisma;
            int hitpoints;    
            Character();
            
    };
    int modifier(int constitution);
    int ability();


    

}  // namespace dnd_character
