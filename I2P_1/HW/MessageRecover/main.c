#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "function.h"

#define maxn 1000
#define maxl 1000

int P;
char M[1000010];

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

int main() {
    int n = 0;
    char Table[maxn][maxl+1]; // +1 for null char
    char *ptr[maxn];

    for (int i = 0; i < maxn; i++) {
        for(int j=0; j < maxl + 1; j++)
            Table[i][j] = '\0';
        ptr[i] = &Table[i][0];
    }

    scanf("%d", &P);
    scanf("%s", M);

    solver(ptr, &n, P, M);
    
    int cnt = 0;
    printf("%d\n", n); // the # of words
    for(int i=0; i<P; i++){
        if( strlen( Table[i] ) != 0 ){
            // if the position is non-empty.
            if( cnt < n-1 )
                printf("%s ", Table[i]);
            else
                printf("%s\n", Table[i]);
            cnt++;
        }
    }
    return 0;
}
