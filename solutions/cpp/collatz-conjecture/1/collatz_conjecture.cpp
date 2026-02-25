#include "collatz_conjecture.h"
#include <stdexcept>
namespace collatz_conjecture {

unsigned int steps(int num){
    if(num <= 0) throw std::domain_error("num should be greater than 0");
    unsigned int count{0};
    while(num > 1){
        if(num % 2 == 0) {
            num /= 2;
        } else {
            num = (num * 3) + 1;
        }
        ++count;
    }
    return count;
}

}  // namespace collatz_conjecture
