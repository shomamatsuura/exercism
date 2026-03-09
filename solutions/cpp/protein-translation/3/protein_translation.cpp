#include "protein_translation.h"
#include <map>
namespace protein_translation {

static const std::map<std::string_view, std::string_view> translation_map = {
    {"AUG", "Methionine"},
    {"UUU", "Phenylalanine"}, {"UUC", "Phenylalanine"},
    {"UUA",	"Leucine"},
    {"UUG", "Leucine"},
    {"UCU", "Serine"},
    {"UCC", "Serine"},
    {"UCA", "Serine"},
    {"UCG", "Serine"},
    {"UAU", "Tyrosine"},
    {"UAC", "Tyrosine"},  
    {"UGU", "Cysteine"},
    {"UGC", "Cysteine"},   
    {"UGG", "Tryptophan"},
    {"UAA", "STOP"},
    {"UAG", "STOP"},
    {"UGA", "STOP"}
};
std::vector<std::string> proteins(std::string_view rna){
    std::vector<std::string> result;
    for(size_t i{0}; i + 2 < rna.length(); i += 3){
        std::string_view condon = rna.substr(i, 3);
        
        auto it = translation_map.find(condon);
        if(it != translation_map.end()){
            std::string_view amino_acid = it->second;
            if(amino_acid == "STOP") {
                break;
            }
            result.emplace_back(amino_acid);
        }
    }
    return result;
    
}

}  // namespace protein_translation
