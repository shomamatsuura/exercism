#include "difference_of_squares.h"

namespace difference_of_squares {

unsigned int square_of_sum(unsigned int num){
    unsigned int sum{0};
    for(unsigned int i{1}; i <= num; ++i){
        sum += i;
    }
    return sum * sum;
}
unsigned int sum_of_squares(unsigned int num){
    unsigned int result{0};

    for(unsigned int i{1}; i <= num; ++i){
        result += i * i;
    }
    return result;
}
unsigned int difference(unsigned int num){
    return square_of_sum(num) - sum_of_squares(num);
}

}  // namespace difference_of_squares
