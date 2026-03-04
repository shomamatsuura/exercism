#include "diamond.h"
#include <cctype>
namespace diamond {

std::vector<std::string> rows(char target_letter){
    // How far the target letter is from 'A' (e.g., 'C' is 2)
    const int letter_offset = target_letter - 'A'; 
    const int diamond_size = 2 * letter_offset + 1;
    const int center_index = letter_offset;

    std::vector<std::string> diamond_rows(diamond_size);
    for(int row_index{0}; row_index <= letter_offset; ++row_index){
        // Initialize a row full of spaces
        std::string current_row(diamond_size, ' ');

        const char row_letter = 'A' + row_index;

        // Calculate mirroring positions from the center
        const int left_pos = center_index - row_index;
        const int right_pos = center_index + row_index;

        current_row[left_pos] = row_letter;
        current_row[right_pos] = row_letter;

        // Apply Vertical Symmetry: Fill the top and the mirrored bottom row
        diamond_rows[row_index] = current_row;
        diamond_rows[diamond_size - 1 - row_index] = current_row;
    }
    return diamond_rows;
}

}  // namespace diamond
