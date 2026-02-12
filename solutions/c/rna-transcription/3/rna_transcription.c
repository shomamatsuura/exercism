#include "rna_transcription.h"
#include <string.h>
#include <stdlib.h>

char *to_rna(const char *dna){
    if(dna == NULL) return "";
    size_t dna_len = strlen(dna);
    char* rna = (char*)malloc(dna_len + 1);
    for(size_t i = 0; i < dna_len; ++i){
        char c = dna[i];
        switch(c){
            case 'G':
                rna[i] = 'C';
                break;
            case 'C':
                rna[i] = 'G';
                break;
            case 'T':
                rna[i] = 'A';                
                break;
            case 'A':
                rna[i] = 'U';
                break;
            default:
                free(rna);
                return "";
        }
    }
    rna[dna_len] = '\0';
    return rna;
}