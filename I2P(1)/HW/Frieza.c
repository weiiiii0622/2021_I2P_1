#include <stdio.h>

int main(){
    float a, b;
    scanf("%f %f", &a, &b);

    float answer = a/b;

    if(b == 0){
        printf("Error");
    }
    else{
        printf("%.2f", answer);
    }

    return 0;
}