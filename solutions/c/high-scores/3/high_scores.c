#include "high_scores.h"
#include <string.h>

int32_t latest(const int32_t *scores, size_t scores_len){
    return scores[scores_len - 1];
}

int32_t personal_best(const int32_t *scores, size_t scores_len){
    int32_t highest_score = scores[0];
    for(size_t i = 1; i < scores_len; ++i){
        if(highest_score < scores[i]) highest_score = scores[i];
    }
    return highest_score;
}

/// Write the highest scores to `output` (in non-ascending order).
/// Return the number of scores written.
size_t personal_top_three(const int32_t *scores, size_t scores_len,
                          int32_t *output){

    int32_t temp_scores[scores_len];
    memcpy(temp_scores, scores, scores_len * 4);
    size_t output_len = scores_len < 3? scores_len : 3;
    for(size_t i = 0; i < scores_len; ++i){
        int32_t score = temp_scores[i];
        size_t j = i;
        while(j > 0 && score > temp_scores[j-1]){
            temp_scores[j] = temp_scores[j-1];
            --j;
        }
        temp_scores[j] = score;
    }
    for(size_t k = 0; k< output_len; ++k){
        output[k] = temp_scores[k];
    }
    
    return output_len;
}
