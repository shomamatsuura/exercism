#include "rna_transcription.h"
#include <string.h>
#include <stdlib.h>

char convert_nucleotide(char nuc);
char convert_nucleotide(char nuc){
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
    int len = strlen(dna);
    char* rna = (char*) malloc(len + 1) ;
    memset(rna, '\0', len + 1);
        
    for(int i = 0; i < len; i++){
        rna[i] = convert_nucleotide(dna[i]);
        if(!rna[i]){
            free(rna);
            return NULL;
        }
    }
    return rna;
}