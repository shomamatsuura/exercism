#include "eliuds_eggs.h"

namespace chicken_coop {

int positions_to_quantity(int decimal_num){
    int count{0};
    while(decimal_num != 0){
        if((decimal_num & 1 )== 1){
            ++count;
        }
        decimal_num >>= 1;
    }
    return count;
}

}  // namespace chicken_coop
