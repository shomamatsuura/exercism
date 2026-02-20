#include "eliuds_eggs.h"

namespace chicken_coop {

unsigned int positions_to_quantity(unsigned int decimal_number){
    if(decimal_number == 0) return 0;
    unsigned int eggs{0};
    while(decimal_number != 0){
        if((decimal_number & 1) == 1) ++eggs;
        decimal_number = decimal_number >> 1;
    }
    return eggs;
}

}  // namespace chicken_coop
