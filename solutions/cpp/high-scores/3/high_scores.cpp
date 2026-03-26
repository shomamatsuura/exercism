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
    std::vector<int> temp = scores;
    std::sort(temp.begin(), temp.end(), std::greater<>());
    std::vector<int> result;
    int limit = temp.size() < 3 ? temp.size() : 3;
    for(int i{0}; i < limit; ++i){
        result.emplace_back(temp[i]);
    }
    return result;
}

}  // namespace arcade
