#include "pascals_triangle.h"

namespace pascals_triangle {

std::vector<std::vector<int>> generate_rows(unsigned int row_count){
    std::vector<std::vector<int>> rows;
    if(row_count == 0) return rows;
    
    rows = {{1}};
    for(unsigned int i{1}; i < row_count; ++i){
        std::vector<int> previous_row = rows.at(i-1);
        previous_row.insert(previous_row.begin(), 0);
        previous_row.emplace_back(0);
        
        std::vector<int> new_row;
        for(unsigned int j{0}; j < previous_row.size() - 1; ++j){
            new_row.emplace_back(previous_row.at(j) + previous_row.at(j+1));
        }
        rows.emplace_back(new_row);
    }

    return rows;
}

}  // namespace pascals_triangle
