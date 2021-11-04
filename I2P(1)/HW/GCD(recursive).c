#include <stdio.h>

int gcd(int, int);

int main(){
    int t;
    scanf("%d", &t);

    for(int i=0; i<t; i++){
        int a, b;
        scanf("%d %d", &a, &b);
        if(a >= b){
            printf("%d\n", gcd(a, b));
        }
        else{
            printf("%d\n", gcd(b, a));
        }
    }

    return 0;
}

int gcd(int a, int b){

    int temp = b;
    b = a % b;
    a = temp;

    if(b == 0){
        return a;
    }
    else{
        return gcd(a, b);
    }
}