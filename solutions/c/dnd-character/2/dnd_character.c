#include "dnd_character.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>



int ability(void){
    srand((unsigned)time(NULL));

    int min = 7;
    int sum = 0;
    for(int i = 0; i < 4; i++){
        int diceNum = rand() % 6 + 1;
        sum += diceNum;
        if(diceNum > min) min = diceNum;
    }
    sum -= min;
    return sum;
}
int modifier(int score){
    return floor((score - 10) / 2.0);
}
dnd_character_t make_dnd_character(void){
    dnd_character_t hero;
    hero.strength = ability();
    hero.dexterity = ability();
    hero.constitution = ability();
    hero.intelligence = ability();
    hero.wisdom = ability();
    hero.charisma = ability();
    hero.hitpoints = 10 + modifier(hero.constitution);
    return hero;
}