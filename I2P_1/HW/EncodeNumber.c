#include <stdio.h>

int main(){

    int n;
    scanf("%d", &n);

    printf("%c%c%c", n/100 +64, ((n%100)-(n%10))/10 +64, n%10 +64);

    return 0;
}