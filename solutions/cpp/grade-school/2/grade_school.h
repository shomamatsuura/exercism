#pragma once
#include <map>
#include <string>
#include <vector>

using namespace std;

namespace grade_school {
    class school{
        private:
            map<int, vector<string>> roster_;
        public:
            school() = default;
            bool add(const string& name, int grade);
            const map<int, vector<string>>& roster() const;
            const vector<string>& grade(int grade) const;
    };

}  // namespace grade_school
