#include <stdio.h>

int main(){


    float a, b, c;
    int d, e;
    scanf("%f %f %f", &a, &b, &c);
    scanf("%d %d", &d, &e);

    if(d == 0){
        printf("%.3f\n", a/b*(float)e+c);
    }
    else{
        printf("%.3f\n", ((float)e-c)*b/a);
    }

    return 0;
}