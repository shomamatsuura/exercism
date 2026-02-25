#pragma once

namespace space_age {
    class space_age{
        private:
            long int age_sec;
            double convert(double ratio) const;
        public:
            space_age(long int age_sec) : age_sec{age_sec}{};
            long int seconds() const {return age_sec;};
            double on_mercury() const ;
            double on_venus() const ;
            double on_earth() const ;
            double on_mars() const ;
            double on_jupiter() const ;
            double on_saturn() const ;
            double on_uranus() const ;
            double on_neptune() const ;
    };

}  // namespace space_age
