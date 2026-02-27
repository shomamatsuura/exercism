#pragma once
#include <string_view>
#include <string>
namespace rna_transcription {

char to_rna(char dna);
std::string to_rna(std::string_view dna);

}  // namespace rna_transcription
