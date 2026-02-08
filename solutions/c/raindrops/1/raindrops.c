#include "raindrops.h"
#include <stdio.h>
#include <stdbool.h>
#include <string.h>
void convert(char result[], int drops){
    bool divisible[3] = {0};
    if(drops % 3 == 0){
        divisible[0] = true;
    }
    if(drops % 5 == 0){
        divisible[1] = true;
    }
    if(drops % 7 == 0){
        divisible[2] = true;
    }

    if(!divisible[0] && !divisible[1] && !divisible[2]){
        sprintf(result, "%d", drops);
    }


    if(divisible[0]){
        sprintf(result, "Pling");
    }
    if(divisible[1]){
        if(result == NULL){
            sprintf(result, "Plang");
        } else{
            char plang[] = "Plang";
            result = strcat(result, plang);
        }
    }    
    if(divisible[2]){
        if(result == NULL){
            sprintf(result, "Plong");
        } else{
            char plong[] = "Plong";
            result = strcat(result, plong);
        }
    }    
    
}