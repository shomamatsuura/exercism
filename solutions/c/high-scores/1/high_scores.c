#include "high_scores.h"
void swap(int32_t *output, int idx1, int idx2);

int32_t latest(const int32_t *scores, size_t scores_len){
    return scores[scores_len - 1];
}

int32_t personal_best(const int32_t *scores, size_t scores_len){
    int max = 0;
    for(size_t i = 0; i < scores_len; i++){
        if(max < scores[i]) max = scores[i];
    }
    return max;
}

size_t personal_top_three(const int32_t *scores, size_t scores_len,
                          int32_t *output){
    size_t actual_len = scores_len < 3 ? scores_len : 3;

    int32_t sortedScores[scores_len];
    for(size_t i = 0; i < scores_len; i++){
        sortedScores[i] = scores[i];
        for(size_t j = i; j > 0; j--){
            if(sortedScores[j] > sortedScores[j-1]){
                swap(sortedScores, j, j-1);
            } else{
                break;
            }
        }
    }
    for(size_t i = 0; i < actual_len; i++){
        output[i] = sortedScores[i];
    }
    
    return actual_len;
}

void swap(int32_t *output, int idx1, int idx2){
    int32_t temp = output[idx1];
    output[idx1] = output[idx2];
    output[idx2] = temp;
}