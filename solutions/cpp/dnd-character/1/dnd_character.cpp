#include "dnd_character.h"


namespace dnd_character {

    int modifier(int constitution){
        return std::floor((constitution - 10) / 2.0);
    }
    int ability(){
        return 3;
    }
    Character::Character(){
        strength = (rand() % 16) + 3;
        dexterity = (rand() % 16) + 3;
        constitution = (rand() % 16) + 3;
        intelligence = (rand() % 16) + 3;
        wisdom = (rand() % 16) + 3;
        charisma = (rand() % 16) + 3;
        hitpoints = 10 + modifier(constitution);  
    }
}  // namespace dnd_character
