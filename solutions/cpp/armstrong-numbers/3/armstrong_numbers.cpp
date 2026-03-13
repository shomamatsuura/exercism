#include "armstrong_numbers.h"
#include <vector>
namespace armstrong_numbers {

bool is_armstrong_number(const int num){
    int sum{0};
    std::vector<int> digits{};
    int digit_count{0};
    int calculated_num = num;
    while(calculated_num > 0){
        digits.emplace_back(calculated_num % 10);
        ++digit_count;
        calculated_num /= 10;
    }
    for(auto digit : digits){
        int currenct_num{1};
        for(int i{0}; i < digit_count; ++i){
            currenct_num *= digit;
        }
        sum += currenct_num;
    }
    return sum  == num;
}

}  // namespace armstrong_numbers
