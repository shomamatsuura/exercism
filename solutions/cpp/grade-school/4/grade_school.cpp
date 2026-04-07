#include "grade_school.h"
#include <algorithm>

namespace grade_school {

    bool school::add(std::string_view name, int score){
        for(const auto& grade_pair : students_map){
            const auto& students = grade_pair.second;
            if(find(students.begin(), students.end(), name) != students.end()){
                return false;
            }
        }
        students_map[score].emplace_back(name);
        std::sort(students_map.at(score).begin(), students_map.at(score).end());
        return true;        
    }
    const std::map<int, std::vector<std::string>>& school::roster() const{
        return students_map;
    }
    const std::vector<std::string>& school::grade(int score) const{
        auto it = students_map.find(score);
        if(it != students_map.end()){
            return it->second;
        }
        static const std::vector<std::string> empty_grade;
        return empty_grade;
    }

}  // namespace grade_school
