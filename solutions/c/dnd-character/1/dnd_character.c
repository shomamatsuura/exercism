#include "dnd_character.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>


int ability(void){
    srand((unsigned)time(NULL));
    int min = 6;
    int diceArray[4];
    for(int i = 0; i < 4; i++){
        int diceNum = rand() % 6 + 1;
        diceArray[i] = diceNum;
        if(diceNum < min) min = diceNum;
    }
    int sum = 0;
    for(int i = 0; i < 4; i++){
        if(min == diceArray[i]) continue;
        sum += diceArray[i];
    }
    return sum;
}
int modifier(int score){
    return floor((score - 10) / 2.0);
}
dnd_character_t make_dnd_character(void){
    dnd_character_t character = {ability(), ability(), ability(), ability(), ability(), ability(), 0};
    int hitpoints = 10 + modifier(character.constitution);
    character.hitpoints = hitpoints;
    return character;
}