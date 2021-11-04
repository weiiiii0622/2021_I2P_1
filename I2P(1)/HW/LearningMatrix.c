#include <stdio.h>

int main(){
    int N, M;
    scanf("%d %d", &N, &M);

    int A[N][M], B[M][N], Ans[N][N];

    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++){
            scanf("%d", &A[i][j]);
        }
    }

    for(int i=0; i<M; i++){
        for(int j=0; j<N; j++){
            scanf("%d", &B[i][j]);
        }
    }

    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){

            int sum = 0;
            for(int x=0, y=0; x<M&&y<M; x++, y++){
                sum += (A[i][x] * B[y][j]);
            }
            Ans[i][j] = sum;
        }
    }

    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            if(j!=N-1){
                printf("%d ", Ans[j][i]);
            }
            else{
                printf("%d\n", Ans[j][i]);
            } 
        }
    }

    return 0;
}