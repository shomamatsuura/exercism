#include "triangle.h"

static inline bool is_triangle(triangle_t sides){
    if(sides.a <= 0 || sides.b <= 0 || sides.c <= 0) return false;
    if((sides.a + sides.b >= sides.c) && (sides.b + sides.c >= sides.a) && (sides.a + sides.c >= sides.b)) return true;
    return false;    
}

bool is_equilateral(triangle_t sides){
    if(!is_triangle(sides)) return false;
    if(sides.a == sides.b && sides.b == sides.c) return true;
    return false;
}

bool is_isosceles(triangle_t sides){
    if(!is_triangle(sides)) return false;
    if(is_equilateral(sides)) return true;
    if((sides.a == sides.b) || (sides.a == sides.c) || (sides.b == sides.c)) return true;
    return false;
}

bool is_scalene(triangle_t sides){
    if(!is_triangle(sides)) return false;
    if((sides.a != sides.b) && (sides.a != sides.c) && (sides.b != sides.c)) return true;
    return false;
}