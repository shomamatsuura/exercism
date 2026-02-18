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
    public:
            int generation{};
            int busters{0};
            star_map::System current_system{};
            Vessel(std::string name, int generation, star_map::System current_system = star_map::System::Sol);

            std::string getName() const {return this->name;};
            Vessel replicate(const std::string new_name);
            void make_buster();
            bool shoot_buster();
    
    };
    std::string get_older_bob(const Vessel& v1, const Vessel& v2);
    bool in_the_same_system(const Vessel& v1, const Vessel& v2);
}

