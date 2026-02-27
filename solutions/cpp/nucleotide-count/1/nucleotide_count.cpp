#include "nucleotide_count.h"
#include <stdexcept>

namespace nucleotide_count {

std::map<char, int> count(const std::string& dna_sequence){
    std::map<char, int> result = {{'A', 0}, {'C', 0}, {'G', 0}, {'T', 0}};
    for(auto ch: dna_sequence){
        auto it = result.find(ch);
        if(it == result.end()){
            throw std::invalid_argument("invalid argument");
        }
        ++it->second;
        
    }
    return result;
}

}  // namespace nucleotide_count
