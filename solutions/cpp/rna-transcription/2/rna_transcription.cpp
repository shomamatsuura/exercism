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
            return'U';
        default:
            throw std::invalid_argument("invalid argument");
    }
}
    
std::string to_rna(std::string_view dna){
    std::string rna;
    rna.reserve(dna.size()); // Pre-allocate memory

    std::transform(dna.begin(), dna.end(), std::back_inserter(rna), [](char ch){return to_rna(ch);});

    return rna;
}

}  // namespace rna_transcription
