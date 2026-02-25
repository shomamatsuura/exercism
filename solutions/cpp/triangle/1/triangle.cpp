#include "triangle.h"
#include <stdexcept>
namespace triangle {
    
    flavor kind(double a, double b, double c){
        if(a <= 0 || b <= 0 || c <= 0){
            throw std::domain_error("All sides should be greater than 0");
        }
        if(a + b < c || b + c < a || a + c < b){
            throw std::domain_error("All sides should be greater than 0");
        }
        
        if(a == b && b == c){
            return flavor::equilateral;
        } else if(a == b || a == c || b == c) {
            return flavor::isosceles;
        } else{
            return flavor::scalene;
        }
    }

}  // namespace triangle
