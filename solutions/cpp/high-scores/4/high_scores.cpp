#include "high_scores.h"

#include <algorithm>

namespace arcade {

std::vector<int> HighScores::list_scores() {
    // TODO: Return all scores for this session.
    return scores;
}

int HighScores::latest_score() {
    // TODO: Return the latest score for this session.
    return scores.back();
}

int HighScores::personal_best() {
    // TODO: Return the highest score for this session.
    return *std::max_element(scores.begin(), scores.end());
}

std::vector<int> HighScores::top_three() {
    // TODO: Return the top 3 scores for this session in descending order.
    size_t count = std::min(scores.size(), size_t{3});
    std::vector<int> result(count);
    std::partial_sort_copy(scores.begin(), scores.end(), result.begin(), result.end(), std::greater<int>());
        
    return result;
}

}  // namespace arcade
