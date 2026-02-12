#include "dnd_character.h"
#include <stdlib.h>
#include <math.h>

int ability(void){
    int sum = 0;
    int min = 7;
    for(int i = 0; i< 4; i ++){
        int num = rand() % 6 + 1;
        sum += num;
        if(min > num) min = num;
    }
    sum -= min;
    return sum;
}
int modifier(int score){
    return floor((score - 10) / 2.0);
}
dnd_character_t make_dnd_character(void){
    dnd_character_t hero = {
        .strength = ability(),
        .dexterity = ability(),
        .constitution = ability(),
        .intelligence = ability(),
        .wisdom = ability(),
        .charisma = ability(),
        .hitpoints = 10 + modifier(hero.constitution)
    };
    return hero;
}