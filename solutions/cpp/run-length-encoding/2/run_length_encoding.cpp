#include "run_length_encoding.h"

namespace run_length_encoding {

std::string encode(std::string_view plain_text){
    if(plain_text.empty()) return "";
    
    std::string encoded_text;
    std::size_t text_length = plain_text.length();
    for(std::size_t i{0}; i < text_length; ++i){
        char current_char = plain_text[i];
        int run_length{1};

        // Count consecutive identical characters
        while(i + 1 < text_length && current_char == plain_text[i+1]){
            ++run_length;
            ++i;
        }
        // Only prepend the number if the count is greater than 1
        if(run_length > 1){
            encoded_text += std::to_string(run_length);
        }
        encoded_text += current_char;
    }
    return encoded_text;
}
std::string decode(std::string_view encoded_text){
    std::string decoded_text;
    int repeat_count{0};
    for(auto c : encoded_text){
        if(std::isdigit(static_cast<unsigned char>(c))){
            // Build the multi-digit number (e.g., "12")
            repeat_count = (repeat_count * 10) + (c - '0');
        } else {
            // If no number preceded the char, count is 1
            int actual_repeats = (repeat_count == 0) ? 1 : repeat_count;

            decoded_text.append(actual_repeats, c);
            repeat_count = 0;    // Reset for next character
        }
    }
    return decoded_text;
}
    

}  // namespace run_length_encoding
