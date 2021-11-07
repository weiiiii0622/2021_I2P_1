#include <stdio.h>

int climb(int);

int main(){

    int N;
    scanf("%d", &N);

    for(int a=0; a<N; a++){
        int x;
        scanf("%d", &x);
        printf("%d\n", climb(x));
    }

    return 0;
}

int climb(int x){
    if(x == 1){
        return 1;
    }
    else if(x == 2){
        return 2;
    }
    else{
        return climb(x-1) + climb(x-2);
    }
}