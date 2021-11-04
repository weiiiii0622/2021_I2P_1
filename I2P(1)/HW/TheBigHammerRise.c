#include <stdio.h>

int main(){
    int a, b, c, d, answer;
    scanf("%d.%d %d.%d", &a, &b, &c, &d);

    answer = (a*100+b)*(c*100+d);

    printf("%d.%04d\n", answer/10000, answer%10000);

    return 0;
}