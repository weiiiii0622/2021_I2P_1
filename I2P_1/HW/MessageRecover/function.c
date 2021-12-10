#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "function.h"

void solver(char **ptr, int *n, int P, char *M){
    int i = 0, int_count = 0;
    char temp_int[1001], temp_str[1001];
    int num;

    while(M[i] != '\0'){

        int j;
        for(j=i; M[i] != '\0' && M[i]>='0' && M[i]<='9'; i++){
            temp_int[i-j] = M[i];
        }
        temp_int[i-j] = '\0';
        num = atoi(temp_int);

        for(j=i; M[i] != '\0' && ((M[i]>='a' && M[i]<='z')||(M[i]>='A' && M[i]<='Z')); i++){
            temp_str[i-j] = M[i];
        }
        temp_str[i-j] = '\0';

        if(strlen(ptr[num%P]) == 0){
            (*n)++;
            strcat(ptr[num%P], temp_str);
        }
        else{
            strcat(ptr[num%P], temp_str);
        }  
    }
}