#include "pascals_triangle.h"

namespace pascals_triangle {
using Triangle = std::vector<std::vector<int>>;
std::vector<std::vector<int>> generate_rows(unsigned int row_count){
    if(row_count == 0) return {};
    Triangle triangle(row_count);
    for(std::size_t y = 0; y < row_count; ++y){
        triangle[y].resize(y+1, 1);
        for(std::size_t x = 1; x < y; ++x){
            triangle[y][x] = triangle[y-1][x-1] + triangle[y-1][x];
        }
    }
    return triangle;
}

}  // namespace pascals_triangle
