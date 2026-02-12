#include "eliuds_eggs.h"


int egg_count(int decimal_num){
    int eggs = 0;
    while(decimal_num){
        decimal_num &= (decimal_num - 1);
        eggs++;
    }
    return eggs;
}