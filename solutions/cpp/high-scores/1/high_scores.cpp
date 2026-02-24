#include "high_scores.h"

#include <algorithm>

namespace arcade {

std::vector<int> HighScores::list_scores() {
    return scores;
}

int HighScores::latest_score() {
    // TODO: Return the latest score for this session.
    return scores.back();
}

int HighScores::personal_best() {
    // TODO: Return the highest score for this session.
    int highest{0};
    for(auto score: scores){
        if(highest < score) highest = score;
    }
    return highest;
}

std::vector<int> HighScores::top_three() {
    // TODO: Return the top 3 scores for this session in descending order.
    std::vector<int> top_trhee_scores{};
    bool order_check = false;
    for(auto score: scores){
        if(top_trhee_scores.size() < 3){
            top_trhee_scores.emplace_back(score);
            order_check = true;
        } else if(top_trhee_scores.back() < score){
            top_trhee_scores.back() =  score;
            order_check = true;
        }
        if(order_check){
            for(size_t i = top_trhee_scores.size() - 1; i > 0; --i){
                if(top_trhee_scores.at(i) > top_trhee_scores.at(i-1)){
                    std::swap(top_trhee_scores.at(i), top_trhee_scores.at(i-1));
                }
            }
        }
    }
    
    
    return top_trhee_scores;
}

}  // namespace arcade
