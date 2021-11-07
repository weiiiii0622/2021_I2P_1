#include <stdio.h>

void gcd(int, int);

int main(){

    int a, b;
    scanf("%d %d", &a, &b);

    if(a >= b){
        gcd(a, b);
    }
    else{
        gcd(b, a);
    }

    return 0;
}

void gcd(int a, int b){
    int c=0;
    while(b != 0){
        c = b;
        b = a%b;
        a = c;
    }

    printf("%d\n", a);
}