#include "doctor_data.h"

namespace heaven {

    Vessel::Vessel(std::string name, int generation, star_map::System current_system): name{name}, generation{generation}, current_system{current_system}{}
    
    Vessel Vessel::replicate(const std::string new_name){
        Vessel new_vessel{new_name, generation + 1, current_system};
        return new_vessel;
    }    

    void Vessel::make_buster(){
        ++busters;
    }
    bool Vessel::shoot_buster(){
        if(busters > 0){
            --busters;
            return true;
        } else {
             return false;   
        }
    }
    std::string get_older_bob(const Vessel& v1, const Vessel& v2){
        return v1.generation < v2.generation ? v1.getName() : v2.getName();
    }
    bool in_the_same_system(const Vessel& v1, const  Vessel& v2){
        return v1.current_system == v2.current_system;
     
    }
}

