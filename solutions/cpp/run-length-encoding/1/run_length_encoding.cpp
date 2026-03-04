#include "run_length_encoding.h"
#include <cctype>

namespace run_length_encoding {

std::string encode(std::string_view data){
    if(data == "") return "";
    std::string encoded_data{""};
    char current_c{'\0'};
    std::size_t count{0};
    for(auto c : data){
        if(current_c == '\0'){
            current_c = c;
            count = 1;
        } else if(current_c == c){
            ++count;
        } else if(current_c != c){
            if(count > 1){
                encoded_data += (std::to_string(count) + current_c);
            } else{
                encoded_data += current_c;
            }
            current_c = c;
            count = 1;
        }
    }
    if(count > 1){
        encoded_data += (std::to_string(count) + current_c);
    } else{
        encoded_data += current_c;
    }

    return encoded_data;
}
std::string decode(std::string_view encoded_data){
    std::string decoded_data{""};
    std::string repeat_count_str{""};
    for(auto c : encoded_data){
        if(std::isalpha(c) || c == ' '){
            if(repeat_count_str != ""){
                int repeat_count = std::stoi(repeat_count_str);
                while(repeat_count > 0){
                    decoded_data += c;
                    --repeat_count;
                }
                repeat_count_str = "";                
            } else{
                decoded_data += c;
            }

        } else if(std::isdigit(c)){
            repeat_count_str += c;
        }
    }
    return decoded_data;
}
    

}  // namespace run_length_encoding
