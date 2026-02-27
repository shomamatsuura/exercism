#include "grade_school.h"
#include <algorithm>

namespace grade_school {

    bool school::add(const string& name, int grade){
        for(const auto& grade_pair : roster_){
            const auto& students = grade_pair.second;
            if(find(students.begin(), students.end(), name) != students.end()){
                return false;    // Student already exists, indicate failure
            }
        }
        roster_[grade].push_back(name);
        sort(roster_[grade].begin(), roster_[grade].end());
        return true; // Successfully added
    }
    const map<int, vector<string>>& school::roster() const{
        return roster_;
    }
    
    const vector<string>& school::grade(int grade_number) const{
        auto it = roster_.find(grade_number);
        if(it != roster_.end()){
            return it->second;
        }
        // If the grade does not exists, safely return an empty vector
        static const vector<string> empty_grade;
        return empty_grade;
    }

}  // namespace grade_school
