#pragma once
#include <map>
#include <string>

namespace nucleotide_count {
std::map<char, int> count(const std::string& dna_sequence);

}  // namespace nucleotide_count
