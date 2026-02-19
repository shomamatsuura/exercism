#include "difference_of_squares.h"

namespace difference_of_squares {

unsigned int square_of_sum(int num){
    unsigned int sum{0};
    for(int i = 1; i <= num; ++i){
        sum += i;
    }
    return sum * sum;
    
}
unsigned int sum_of_squares(int num){
    unsigned int result{0};
    for(int i = 1; i <= num; ++i){
        result += (i * i);
    }

    return result;
}
long int difference(int num){
    return  square_of_sum(num) - sum_of_squares(num);
}

}  // namespace difference_of_squares
