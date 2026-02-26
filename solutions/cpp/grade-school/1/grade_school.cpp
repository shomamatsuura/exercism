#include "grade_school.h"
#include <algorithm>
namespace grade_school {

    void school::add(const string& name, int score){
        if(students.count(score) == 0){
            // Insert new score
            students.insert({score, {name}});
            
        } else{
            // Update exsisting score
            students.find(score)->second.emplace_back(name);
            sort(students.find(score)->second.begin(), students.find(score)->second.end());
        }
    }
    map<int, vector<string>> school::roster() const{
        return students;
    }
    
    vector<string> school::grade(int score) const{
        auto it = students.find(score);
        if(it == students.end()){
            return {};
        }
        return it->second;
    }

}  // namespace grade_school
