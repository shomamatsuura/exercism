#include "rna_transcription.h"
#include <stdexcept>
namespace rna_transcription {

char change_dna_to_rna(char ch){
    switch(ch){
        case 'G':
            return 'C';
            break;
        case 'C':
            return 'G';
            break;            
        case 'T':
            return 'A';
            break;
        case 'A':
            return'U';
            break;
        default:
            throw std::invalid_argument("invalid argument");
    }
}
    
char to_rna(char dna){
        return change_dna_to_rna(dna);
}
    
std::string to_rna(std::string_view dna){
    std::string rna;
    for(auto ch: dna){
        rna += change_dna_to_rna(ch);
    }
    return rna;
}

}  // namespace rna_transcription
