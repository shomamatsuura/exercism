#include "power_of_troy.h"

namespace troy {
    void give_new_artifact(human& person, std::string item){
        person.possession = std::make_unique<artifact>(item);
    }
    
    void exchange_artifacts(std::unique_ptr<artifact>& item1, std::unique_ptr<artifact>& item2){
        std::swap(item1, item2);
    }
    void manifest_power(human& person, std::string effect){
        person.own_power = std::make_shared<power>(effect);
    }
    void use_power(human& caster, human& target){
        target.influenced_by = caster.own_power;
    }
    int power_intensity(human& person){
        return person.own_power.use_count();
    }
    
    
}  // namespace troy
