#pragma once
#include <string>
namespace star_map {
    enum class System {
        BetaHydri,
        Sol,
        EpsilonEridani,
        AlphaCentauri,
        DeltaEridani,
        Omicron2Eridani
    };
}

namespace heaven {
    class Vessel {
        public:
            std::string name;
            int generation;
            int busters;
            star_map::System current_system;
            Vessel(std::string name, int generation, star_map::System current_system = star_map::System::Sol){
                this->name = name;
                this->generation = generation;
                this->current_system = current_system;
                this->busters = 0;
            };
            Vessel replicate(std::string new_name);
            void make_buster(){++this->busters;};
            bool shoot_buster();

    };
    std::string get_older_bob(Vessel vessel1, Vessel vessel2);
    bool in_the_same_system(Vessel vessel1, Vessel vessel2);
}

