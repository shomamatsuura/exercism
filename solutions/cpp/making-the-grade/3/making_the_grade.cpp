#include <array>
#include <string>
#include <vector>

// Round down all provided student scores.
std::vector<int> round_down_scores(std::vector<double> student_scores) {
    // TODO: Implement round_down_scores
    std::vector<int> result;
    for(auto score : student_scores){
        result.emplace_back(static_cast<int>(score));
    }
    return result;
}

// Count the number of failing students out of the group provided.
int count_failed_students(std::vector<int> student_scores) {
    // TODO: Implement count_failed_students
    int failed_students{0};
    for(auto score : student_scores){
        if(score <= 40) ++failed_students;
    }
    
    return failed_students;
}

// Create a list of grade thresholds based on the provided highest grade.
std::array<int, 4> letter_grades(int highest_score) {
    // TODO: Implement letter_grades
    std::array<int, 4> grade_thresholds;
    grade_thresholds.at(0) = 41;
    int interval = (highest_score - 40) / 4;
    grade_thresholds.at(1) = grade_thresholds.at(0) + interval;
    grade_thresholds.at(2) = grade_thresholds.at(1) + interval;
    grade_thresholds.at(3) = grade_thresholds.at(2) + interval;
    
    
    return grade_thresholds;
}

// Organize the student's rank, name, and grade information in ascending order.
std::vector<std::string> student_ranking(
    std::vector<int> student_scores, std::vector<std::string> student_names) {
    // TODO: Implement student_ranking
    std::vector<std::string> result;
    for(auto i{0}; i < student_scores.size(); ++i){
        result.emplace_back(std::to_string(i+1) + ". " + student_names.at(i) + ": " + std::to_string(student_scores.at(i)));
    }
    return result;
}

// Create a string that contains the name of the first student to make a perfect
// score on the exam.
std::string perfect_score(std::vector<int> student_scores,
                          std::vector<std::string> student_names) {
    // TODO: Implement perfect_score
    for(std::size_t i{0}; i < student_scores.size(); ++i){
        if(student_scores.at(i) == 100){
            return student_names.at(i);
        }
    }
    return "";
}
