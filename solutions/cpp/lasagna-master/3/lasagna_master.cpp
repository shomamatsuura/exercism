#include "lasagna_master.h"

namespace lasagna_master {

int preparationTime(const std::vector<std::string>& layers, int preparation_time){
    return layers.size() * preparation_time;
}
amount quantities(const std::vector<std::string>& layers){
    amount result{0, 0.0};

    for(auto layer : layers){
        if(layer == "noodles") result.noodles += 50;
        if(layer == "sauce") result.sauce += 0.2;
        
    }
    return result;
}
void addSecretIngredient(std::vector<std::string>& myList, const std::vector<std::string>& friendsList){
    myList.back() = friendsList.back();
}
std::vector<double> scaleRecipe(const std::vector<double>& quantities, int portions){
    std::vector<double> result;
    for(auto quantity : quantities){
        result.emplace_back(quantity * portions / 2);
    }
    return result;
}
void addSecretIngredient(std::vector<std::string>& myList, const std::string& secret_ingredient){
    myList.back() = secret_ingredient;
}
    
}  // namespace lasagna_master
