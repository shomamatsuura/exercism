#include "rna_transcription.h"
#include <stdexcept>
#include <algorithm>
namespace rna_transcription {
    
    char to_rna(char dna){
        switch(dna){
            case 'G':
                return 'C';
            case 'C':
                return 'G';
            case 'T':
                return 'A';
            case 'A':
                return 'U';
            default:
                throw std::invalid_argument("invalid argument");
        };
    }
    std::string to_rna(const std::string& dna){
        std::string result;
        result.reserve(dna.size());
        
        std::transform(dna.begin(), dna.end(), std::back_inserter(result), [](char ch){return to_rna(ch);});
        return result;
    }

}  // namespace rna_transcription

