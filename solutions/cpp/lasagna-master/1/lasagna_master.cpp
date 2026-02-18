#include "lasagna_master.h"

namespace lasagna_master {
    int preparationTime(const std::vector<std::string>& layers, int prep_time){
        return layers.size() * prep_time;
    }
    amount quantities(const std::vector<std::string>& layers){
        amount needed{0, 0.0};
        for(size_t i = 0; i < layers.size(); ++i){
            if(layers.at(i) == "noodles"){
                needed.noodles += 50;
            } else if(layers.at(i) == "sauce"){
                needed.sauce += 0.2;
            }
        }
        return needed;
    }
    void addSecretIngredient(std::vector<std::string>& myList, const std::vector<std::string>& frinedsList){
        std::string secret_ingredient = frinedsList.at(frinedsList.size() - 1);
        myList.at(myList.size() - 1) = secret_ingredient;
    }
    void addSecretIngredient(std::vector<std::string>& myList, const std::string secretIngredient){
        myList.at(myList.size() - 1) = secretIngredient;
    }
    std::vector<double> scaleRecipe(const std::vector<double>& qunatites, const int num_portions){
        std::vector<double> scaled_qunatites{};
        for(size_t i = 0; i < qunatites.size(); ++i){
            scaled_qunatites.emplace_back(qunatites.at(i) * num_portions / 2);
        }
        return scaled_qunatites;
    }
    
    
}  // namespace lasagna_master
