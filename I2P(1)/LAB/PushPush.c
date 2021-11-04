#include <stdio.h>

int main(){
    int A;
    scanf("%d", &A);

    int x = A%10;
    int B = x*1000+A/10;

    printf("%d", A+B);

    return 0;
}