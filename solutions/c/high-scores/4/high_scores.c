#include "high_scores.h"

enum {MAX_TOP_SCORES = 3};

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
    size_t num_top_scores = 0;
    for(size_t i = 0; i < scores_len; ++i){
        int32_t current_score = scores[i];
    
        if(num_top_scores < MAX_TOP_SCORES){
            ++num_top_scores;
        } else if(current_score <= output[num_top_scores - 1]){
            continue;
        }

        size_t insertion_idx = num_top_scores - 1;
        while(insertion_idx > 0 && output[insertion_idx - 1] < current_score){
            output[insertion_idx] = output[insertion_idx - 1];
            --insertion_idx;
        }
        output[insertion_idx] = current_score;
    }

    
    return num_top_scores;
}
