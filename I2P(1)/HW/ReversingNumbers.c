#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
    char a[11];
    scanf("%s", a);
    int len = strlen(a);

    char b[len];
    for(int i=0; i<len; i++){
        b[len-i-1] = a[i];
    }

    int val_A = atoi(a);
    int val_B = atoi(b);
    
    printf("%d\n", val_A+val_B);

    return 0;
}