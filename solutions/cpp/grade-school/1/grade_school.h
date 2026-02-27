#pragma once
#include <string>
#include <vector>
#include <map>

using namespace std;

namespace grade_school {
    class school{
        private:
            map<int, vector<string>> students;
        public:
            void add(const string& name, int score);
            map<int, vector<string>> roster()  const;
            vector<string> grade(int score) const;
    };

}  // namespace grade_school
