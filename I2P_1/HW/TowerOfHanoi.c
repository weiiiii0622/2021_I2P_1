#include <stdio.h>

void hanoi(int);

int main(){

    int n;
    scanf("%d", &n);

    hanoi(n);

    return 0;
}

void hanoi(int n){

    if(n == 1){
        printf("1\n");
    }
    else{
        hanoi(n-1);
        printf("%d\n", n);
        hanoi(n-1);
    }
}