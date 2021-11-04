#include <stdio.h>

int main(){
    double temp;
    char x, y;

    scanf("%lf %c %c", &temp, &x, &y);

    if(x == 'C'){
        printf("%.2f\n", ((9.0/5.0)*temp)+32);
    }
    else{
        printf("%.2f\n", (5.0/9.0)*(temp-32));
    }

    return 0;
}