#include "gigasecond.h"
#include <stdio.h>

void gigasecond(time_t input, char *output, size_t size){
    if(size == 0) return;
    time_t result = input + 1000000000;
    struct tm* tm;
    tm = gmtime(&result);
    sprintf(output, "%04d-%02d-%02d %02d:%02d:%02d", tm->tm_year + 1900 , tm->tm_mon + 1,
           tm->tm_mday, tm->tm_hour, tm->tm_min, tm->tm_sec);
}
