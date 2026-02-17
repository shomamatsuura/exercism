#include "protein_translation.h"

namespace protein_translation {
    std::vector<std::string> proteins(std::string codon_pair){
        std::vector<std::string> acid_pair = {};
        std::string codon = "";
        for(long unsigned int i{0}; i < codon_pair.length(); i++){
            codon += codon_pair.at(i);
            if(codon.size() == 3){
                if(codon == "UAA" || codon == "UAG" || codon == "UGA") return acid_pair;
                if(codon == "AUG") acid_pair.emplace_back("Methionine");
                else if(codon == "UUU" || codon == "UUC") acid_pair.emplace_back("Phenylalanine");
                else if(codon == "UUA" || codon == "UUG") acid_pair.emplace_back("Leucine");
                else if(codon == "UCU" || codon == "UCC" || codon == "UCA" || codon == "UCG") acid_pair.emplace_back("Serine");
                else if(codon == "UAU" || codon == "UAC") acid_pair.emplace_back("Tyrosine");
                else if(codon == "UGU" || codon == "UGC") acid_pair.emplace_back("Cysteine");
                else if(codon == "UGG") acid_pair.emplace_back("Tryptophan");

                codon = "";
            }
        }
        return acid_pair;
    }
}  // namespace protein_translation
