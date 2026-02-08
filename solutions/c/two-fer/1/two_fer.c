#include "two_fer.h"
#include <stdio.h>
#include <string.h>


void two_fer(char *buffer, const char *name){
    
    if(name == NULL) {
        char msg[] = "One for you, one for me.";
        buffer = strcpy(buffer, msg);
    } else{
        char firstHalsMsg[] = "One for ";
        char secondHalsMsg[] = ", one for me.";
        buffer = strcpy(buffer, firstHalsMsg);
        buffer = strcat(buffer, name);
        buffer = strcat(buffer, secondHalsMsg);
        
    }

}
