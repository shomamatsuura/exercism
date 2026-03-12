#include "doctor_data.h"

namespace heaven{
    heaven::Vessel Vessel::replicate(std::string new_name){
        // this->name = new_name;
        // ++this->generation;
        
        return heaven::Vessel(new_name, this->generation + 1);
    }
    bool Vessel::shoot_buster(){
        bool do_success = this->busters > 0 ? true : false;
        if(do_success) --this->busters;
        return do_success;
    }
    std::string get_older_bob(Vessel vessel1, Vessel vessel2){
        return vessel1.generation < vessel2.generation ? vessel1.name : vessel2.name;
    }
    bool in_the_same_system(Vessel vessel1, Vessel vessel2){
        return vessel1.current_system == vessel2.current_system;
    }
}