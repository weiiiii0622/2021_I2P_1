#include <stdio.h>

int main(){

    int N, M;
    scanf("%d %d", &N, &M);

    int input[M];
    for(int i=0; i<M; i++){
        scanf("%d", &input[i]);
    }

    if(N > M){
        for(int i=0; i<M; i++){
            printf("0\n");
        }
    }
    else{
        for(int i=0; i<N-1; i++){
            printf("0\n");
        }
        for(int i=0; i<M-N+1; i++){
            printf("%d\n", input[i]);
        }
    }

    return 0;
}