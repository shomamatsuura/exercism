#include "matching_brackets.h"
#include <unordered_map>
#include <vector>

namespace matching_brackets {

bool check(const std::string& str){
    const static std::unordered_map<char, char> bracket_pairs = {
        {']', '['},
        {'}', '{'},
        {')', '('}
    };
    std::vector<char> brackets;
    
    for(char ch : str){
        if(ch == '[' || ch == '{' || ch == '('){
            brackets.emplace_back(ch);
        } else if(ch == ']' || ch == '}' || ch == ')'){
            if(!brackets.empty() && (brackets.back() == bracket_pairs.at(ch))){
                brackets.pop_back();
            } else return false;
        }
    }
    return brackets.empty();
}

}  // namespace matching_brackets
