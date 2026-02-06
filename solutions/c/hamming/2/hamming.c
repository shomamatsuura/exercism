#include "hamming.h"
#include <string.h>

int compute(const char *lhs, const char *rhs){
    if(lhs == NULL || rhs ==NULL) return -1;
    
    size_t len = strlen(lhs);
    if(len != strlen(rhs)) return -1;
    
    int hammingDistance = 0; 
    for(size_t i = 0; i < len; i++){
        if(lhs[i] != rhs[i]) hammingDistance++;
    }
    return hammingDistance;
}