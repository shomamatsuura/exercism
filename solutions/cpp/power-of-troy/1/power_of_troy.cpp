#include "power_of_troy.h"

namespace troy {
    
    void give_new_artifact(human& troy, std::string new_name){
        troy.possession = std::make_unique<artifact>(new_name);
    }
    void exchange_artifacts(std::unique_ptr<artifact>& possession1, std::unique_ptr<artifact>& possession2){
        std::swap(possession1, possession2);
    }
    void manifest_power(human& troy, std::string new_power){
        troy.own_power = std::make_shared<power>(new_power);
    }
    
    void use_power(human& caster, human& target){
        target.influenced_by = caster.own_power;
        
    }
    int power_intensity(human& caster){
        return caster.own_power.use_count();
    }
    

    
}  // namespace troy
