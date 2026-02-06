#include "rna_transcription.h"
#include <string.h>
#include <stdlib.h>

char *to_rna(const char *dna){
    int len = strlen(dna);
    char* rna = (char*) malloc(len+1) ;
    if(len == 0) {
        rna[0] = '\0';        
        return rna;
    }
    
    for(int i = 0; i < len; i++){
        switch(dna[i]){
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
        }
    }
    rna[len] = '\0';
    return rna;
}