#include <stdio.h>

int main(){
    int a, b, c, x, y, z;
    scanf("%d,%d,%d", &a, &b, &c);
    scanf("%d,%d,%d", &x, &y, &z);

    int m = 1000000*a + 1000*b + c;
    int n = 1000000*x + 1000*y + z;

    printf("%d\n", m+n);

    return 0;
}