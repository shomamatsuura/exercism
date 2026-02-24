#include "matching_brackets.h"
#include <vector>

namespace matching_brackets {

bool check(const std::string& str){

    std::vector<char> brackets;
    for(const auto& ch : str){
        switch(ch){
            case '[':
                brackets.push_back(']');
                break;
            case '{':
                brackets.push_back('}');
                break;
            case '(':
                brackets.push_back(')');
                break;
            case ']':
            case '}':
            case ')':
                if(!brackets.empty() && brackets.back() == ch){
                    brackets.pop_back();
                } else return false;
        }
    }
    return brackets.empty();
}

}  // namespace matching_brackets
