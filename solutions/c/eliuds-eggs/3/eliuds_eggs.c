#include "eliuds_eggs.h"


int egg_count(int decimal_num){
    int count = 0;
    while(decimal_num){
        if((decimal_num & 1) == 1) count++;
        decimal_num = decimal_num >> 1;
    }
    return count;
}