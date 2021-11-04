#include <stdio.h>
#include <string.h>

int main(){

    int T;
    scanf("%d", &T);
    int N;
    scanf("%d", &N);
    int answer[N][N];

    for(int a=0; a<T; a++){

        int matrix[N][N], stars = 0;
        int answer[N][N];
        memset(answer, 0, N*N*sizeof(answer[0][0]));

        for(int i=0; i<N; i++){
            for(int j=0; j<N; j++){
                scanf("%d", &matrix[i][j]);

                if(matrix[i][j] != 255){
                    for(int m = 0; m<N; m++){
                        answer[i][m] = 1;
                    }
                    for(int m = 0; m<N; m++){
                        answer[m][j] = 1;
                    }
                    //left-top
                    for(int x=i-1, y=j-1; x>=0&&y>=0; x--, y--){
                        answer[x][y] = 1;
                    }
                    //right-top
                    for(int x=i-1, y=j+1; x>=0&&y<N; x--, y++){
                        answer[x][y] = 1;
                    }
                    //left-bottom
                    for(int x=i+1, y=j-1; x<N&&y>=0; x++, y--){
                        answer[x][y] = 1;
                    }
                    //right-bottom
                    for(int x=i+1, y=j+1; x<N&&y<N; x++, y++){
                        answer[x][y] = 1;
                    }            
                }
            }
        }

        for(int i=0; i<N; i++){
            for(int j=0; j<N; j++){
                if(answer[i][j] == 0){
                    stars++;
                }
            }
        }
        printf("%d\n", stars);
    }
}