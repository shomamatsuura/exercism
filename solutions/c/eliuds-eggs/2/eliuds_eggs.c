#include "eliuds_eggs.h"


int egg_count(int displayValue){
    int eggs = 0; 
    while(displayValue) {
        eggs += (displayValue & 1);
        displayValue >>= 1;
    }

    return eggs;
}