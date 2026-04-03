#include "space_age.h"

namespace space_age {

    static constexpr double EARTH_YEAR_SECONDS = 31557600.0;
    double space_age::convert(double ratio) const{
        return age_sec / (EARTH_YEAR_SECONDS * ratio);
    }

    double space_age::on_earth() const{
        return convert(1.0);
    }
    double space_age::on_mercury() const{
        return convert(0.2408467);
    }
    double space_age::on_venus() const{
        return convert(0.61519726);
    }
    double space_age::on_mars() const{
        return convert(1.8808158);
    }
    double space_age::on_jupiter() const{
        return convert(11.862615);
    }
    double space_age::on_saturn() const{
        return convert(29.447498);
    }
    double space_age::on_uranus() const{
        return convert(84.016846);
    }
    double space_age::on_neptune() const{
        return convert(164.79132);
    }


}  // namespace space_age
