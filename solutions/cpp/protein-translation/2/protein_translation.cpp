#include "protein_translation.h"
#include <unordered_map>

namespace protein_translation {
    std::vector<std::string> proteins(const std::string& rna){
        static const std::unordered_map<std::string, std::string> condon_map = {
            {"AUG", "Methionine"},
            {"UUU", "Phenylalanine"}, {"UUC", "Phenylalanine"},
            {"UUA", "Leucine"}, {"UUG", "Leucine"},
            {"UCU", "Serine"}, {"UCC", "Serine"}, {"UCA", "Serine"}, {"UCG", "Serine"},
            {"UAU", "Tyrosine"}, {"UAC", "Tyrosine"},
            {"UGU", "Cysteine"}, {"UGC", "Cysteine"},
            {"UGG", "Tryptophan"}
        };
        std::vector<std::string> acid_pair = {};
        for(size_t i{0}; i < rna.size(); i += 3){
            std::string condon = rna.substr(i, 3);
            if(condon == "UAA" || condon == "UAG" || condon == "UGA") break;
            if(condon_map.count(condon)){
                acid_pair.emplace_back(condon_map.at(condon));
            }

        }
        return acid_pair;
    }
}  // namespace protein_translation
