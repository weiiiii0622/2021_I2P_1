#include <stdio.h>
#include "function.h"

void shift(char* start, char* end){
    char temp = *start;
    int i=0;
    while(start+i < end){
        *(start+i) = *(start+i+1);
		i++;
    }
    *end = temp;
}