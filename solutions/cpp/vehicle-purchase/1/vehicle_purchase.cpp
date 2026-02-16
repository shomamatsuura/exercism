#include "vehicle_purchase.h"

namespace vehicle_purchase {

// needs_license determines whether a license is needed to drive a type of
// vehicle. Only "car" and "truck" require a license.
bool needs_license(std::string kind) {
    // TODO: Return true if you need a license for that kind of vehicle.
    return kind == "car" || kind == "truck";
}

// choose_vehicle recommends a vehicle for selection. It always recommends the
// vehicle that comes first in lexicographical order.
std::string choose_vehicle(std::string option1, std::string option2) {
    // TODO: Return the final decision in a sentence.

    size_t len = option1.length() > option2.length() ? option2.length() : option1.length();
    std::string result = "";
    for(size_t i = 0; i < len; i++){
        if(tolower(option1[i]) > tolower(option2[i])){
            result = option2;
            break;
        } 
        else if(tolower(option1[i]) < tolower(option2[i])){
            result = option1;
            break;
        } 
    }
    result += " is clearly the better choice.";
    return result;
}

// calculate_resell_price calculates how much a vehicle can resell for at a
// certain age.
double calculate_resell_price(double original_price, double age) {
    // TODO: Return the age-corrected resell price.
    if(age < 3) return original_price * 0.8;
    else if(age >= 10) return original_price * 0.5;
    else return original_price * 0.7;
    
}

}  // namespace vehicle_purchase
