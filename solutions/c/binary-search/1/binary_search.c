#include "binary_search.h"
#include <stdio.h>
#include <stddef.h>

const int *binary_search(int value, const int *arr, size_t length){
    int startIdx = 0;
    int endIdx = length - 1;
    int middleIdx = (startIdx + endIdx + 1) / 2;

    while(startIdx <= endIdx){
        if(arr[middleIdx] == value) return &arr[middleIdx];
        else if(arr[middleIdx] > value) {
            endIdx = middleIdx - 1;
            
        } else{
            startIdx = middleIdx + 1;
        }
        middleIdx = (startIdx + endIdx + 1) / 2;
        
    }
    return NULL;
}