#include "doctor_data.h"



heaven::Vessel::Vessel(std::string name, int num){
    this->name = name;
    this->num = num;
}
heaven::Vessel::Vessel(std::string name, int num, star_map::System current_system){
    this->name = name;
    this->num = num;
    this->current_system = current_system;
}
heaven::Vessel heaven::Vessel::replicate(std::string name){
    heaven::Vessel new_vessel{name, this->num, this->current_system};
    new_vessel.generation++;
    return new_vessel;
}

void heaven::Vessel::make_buster(){
    this->busters++;
}
bool heaven::Vessel::shoot_buster(){
    if(this->busters > 0){
        this->busters--;
        return true;
    } else {
         return false;   
    }
}

std::string heaven::get_older_bob(heaven::Vessel v1, heaven::Vessel v2){
    return v1.getNum() < v2.getNum() ? v1.getName() : v2.getName();
}
bool heaven::in_the_same_system(heaven::Vessel v1, heaven::Vessel v2){
    return v1.current_system == v2.current_system;
 
}