#include <stdio.h>

int Fib(int);


int main(){
    int n;
    scanf("%d", &n);

    for(int i=1; i<=n; i++){
        printf("%d ", Fib(i));
    }
    printf("\n");

    return 0;
}

int Fib(int n){
    if(n == 1){
        return 0;
    }
    else if(n == 2){
        return 1;
    }
    else{
        return Fib(n-2) + Fib(n-1);
    }
}