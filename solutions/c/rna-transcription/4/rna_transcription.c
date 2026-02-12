#include "rna_transcription.h"
#include <string.h>
#include <stdlib.h>

static inline char convert_nucleotide(char nuc){
    switch(nuc){
        case 'G':
            return 'C';
        case 'C':
            return 'G';
        case 'T':
            return 'A';                
        case 'A':
            return 'U';
        default:
            return '\0';
    }
}

char *to_rna(const char *dna){
    size_t dna_len = strlen(dna);
    char* rna = (char*)malloc(dna_len + 1);
    memset(rna, '\0', dna_len + 1);
    for(size_t i = 0; i < dna_len; ++i){
        char c = dna[i];
        rna[i] = convert_nucleotide(c);
    }
    return rna;
}