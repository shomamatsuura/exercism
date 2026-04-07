#include "grade_school.h"
#include <algorithm>

namespace grade_school {

    void school::add(std::string_view name, int score){
        if(students_map.count(score) == 1){
            students_map.at(score).emplace_back(name);
            std::sort(students_map.at(score).begin(), students_map.at(score).end());
        } else{
            std::vector<std::string> new_score;
            new_score.emplace_back(name);
            students_map.emplace(score, new_score);
            
        }
    }
    std::map<int, std::vector<std::string>> school::roster() const{
        return students_map;
    }
    std::vector<std::string> school::grade(int score) const{
        if(students_map.count(score) == 1){
            return students_map.at(score);
        }
        return {};
    }

}  // namespace grade_school
