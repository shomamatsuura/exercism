#pragma once
#include <unordered_map>
#include <string>


namespace space_age {
    static const std::unordered_map<std::string, double> planet_years{
        {"Mercury", 0.2408467},
        {"Venus", 0.61519726},
        {"Earth", 1.0},
        {"Mars", 1.8808158},
        {"Jupiter", 11.862615},
        {"Saturn", 29.447498},
        {"Uranus", 84.016846},
        {"Neptune", 164.79132}
    };
    
    class space_age{
        private:
            long int age_sec;
        public:
            space_age(long int age_sec) : age_sec{age_sec}{};
            long int seconds() const {return age_sec;};
            // double on_mercury() const ;
            // double on_venus() const ;
            // double on_earth() const ;
            // double on_mars() const ;
            // double on_jupiter() const ;
            // double on_saturn() const ;
            // double on_uranus() const ;
            // double on_neptune() const ;
            double on_mercury() const {return age_sec / (31557600 * planet_years.at("Mercury"));};
            double on_venus() const {return age_sec / (31557600 * planet_years.at("Venus"));};
            double on_earth() const {return age_sec / (31557600 * planet_years.at("Earth"));};
            double on_mars() const {return age_sec / (31557600 * planet_years.at("Mars"));};
            double on_jupiter() const {return age_sec / (31557600 * planet_years.at("Jupiter"));};
            double on_saturn() const {return age_sec / (31557600 * planet_years.at("Saturn"));};
            double on_uranus() const {return age_sec / (31557600 * planet_years.at("Uranus"));};
            double on_neptune() const {return age_sec / (31557600 * planet_years.at("Neptune"));};
    };

}  // namespace space_age
