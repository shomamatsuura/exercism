#include "eliuds_eggs.h"

namespace chicken_coop {

unsigned int positions_to_quantity(int decimal_num){
    if(decimal_num == 0) return 0;
    unsigned int eggs{0};
    while(decimal_num != 0){
        eggs += (decimal_num & 1);
        decimal_num >>= 1;
    }
    return eggs;
}

}  // namespace chicken_coop
