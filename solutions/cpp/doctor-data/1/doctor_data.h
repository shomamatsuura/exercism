#pragma once
#include <string>
namespace star_map{
    enum class System{
        BetaHydri,
        Sol,
        EpsilonEridani,
        AlphaCentauri,
        DeltaEridani,
        Omicron2Eridani
    };
}

namespace heaven{
    class Vessel{
        private:
            std::string name{};
            int num{};
        public:
            int busters{0};
            star_map::System current_system = star_map::System::Sol;
            int generation{1};
            Vessel(std::string name, int num);
            Vessel(std::string name, int num, star_map::System current_system);
            heaven::Vessel replicate(std::string name);
            void make_buster();
            bool shoot_buster();
            std::string getName(){return this->name;};
            int getNum(){return this->num;};
            
    };
    std::string get_older_bob(heaven::Vessel v1, heaven::Vessel v2);
    bool in_the_same_system(heaven::Vessel v1, heaven::Vessel v2);
}

