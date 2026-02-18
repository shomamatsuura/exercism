#include "lasagna_master.h"

namespace lasagna_master {
    int preparationTime(const std::vector<std::string>& layers, int prep_time){
        return layers.size() * prep_time;
    }
    amount quantities(const std::vector<std::string>& layers){
        amount needed{0, 0.0};
        for(std::string layer: layers){
            if(layer == "noodles"){
                needed.noodles += 50;
            } else if(layer == "sauce"){
                needed.sauce += 0.2;
            }
        }
        return needed;
    }
    void addSecretIngredient(std::vector<std::string>& myList, const std::vector<std::string>& frinedsList){
        myList.back() = frinedsList.back();
    }
    void addSecretIngredient(std::vector<std::string>& myList, const std::string secretIngredient){
        myList.back() = secretIngredient;
    }
    std::vector<double> scaleRecipe(const std::vector<double>& quantities, const int num_portions){
        std::vector<double> scaled_qunatities{};
        scaled_qunatities.reserve(quantities.size());
        
        for(double quantity: quantities){
            scaled_qunatities.push_back(quantity * num_portions / 2.0);
        }
        return scaled_qunatities;
    }
    
    
}  // namespace lasagna_master
