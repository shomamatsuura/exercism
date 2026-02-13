#include "eliuds_eggs.h"

int egg_count(int num){
    int eggs = 0;
    while(num){
        num = num & (num - 1);
        ++eggs;
    }
    return eggs;
}