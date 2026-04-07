#pragma once
#include <map>
#include <string>
#include <string_view>
#include <vector>
namespace grade_school {

class school{
    private:
        std::map<int, std::vector<std::string>> students_map;
    public:
        void add(std::string_view name, int score);  
        std::map<int, std::vector<std::string>> roster() const;
        std::vector<std::string> grade(int score) const;
    
};

}  // namespace grade_school
