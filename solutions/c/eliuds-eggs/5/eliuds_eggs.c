#include "eliuds_eggs.h"

int egg_count(int num){
    int eggs = 0;
    while(num != 0){
        if((num & 1) == 1) ++eggs;
        num = num >> 1;
    }
    return eggs;
}