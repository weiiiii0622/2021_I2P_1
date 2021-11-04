#include <stdio.h>

int main(){

    int T;
    scanf("%d", &T);
    int N;
    scanf("%d", &N);

    for(int a=0; a<T; a++){

        int matrix[N][N], row[N], col[N], answer = 0;
        for(int i=0; i<N; i++){
            row[i] = 1;
            col[i] = 1;
        }

        for(int i=0; i<N; i++){
            for(int j=0; j<N; j++){
                scanf("%d", &matrix[i][j]);

                if(row[i] == 1 || col[j] == 1){
                    if(matrix[i][j] != 255){
                        row[i] = 0;
                        col[j] = 0;
                    }
                }
            }
        }

        for(int i=0; i<N; i++){
            for(int j=0; j<N; j++){
                if(row[i] == 1 && col[j] == 1){
                    printf("center:%d,%d\n", i, j);
                    int center_x = i;
                    int center_y = j;
                    int flag = 1;
                    
                    //check left-top
                    while(flag == 1 && center_x >= 0 && center_y >= 0){

                        if(matrix[center_x][center_y] != 255){
                            printf("Die at %d,%d\n", center_x, center_y);
                            flag = 0;
                            break;
                        }
                        center_x--;
                        center_y--;
                    }
                    if(flag == 0){
                        continue;
                    }

                    //check right-top
                    center_x = i;
                    center_y = j;                    
                    while(flag == 1 && center_x < N && center_y >= 0){

                        if(matrix[center_x][center_y] != 255){
                            printf("Die at %d,%d\n", center_x, center_y);
                            flag = 0;
                            break;
                        }
                        center_x++;
                        center_y--;
                    }
                    if(flag == 0){
                        continue;
                    }

                    //check left-bottom
                    center_x = i;
                    center_y = j;                    
                    while(flag == 1 && center_x >=0 && center_y < N){

                        if(matrix[center_x][center_y] != 255){
                            printf("Die at %d,%d\n", center_x, center_y);
                            flag = 0;
                            break;
                        }
                        center_x--;
                        center_y++;
                    }
                    if(flag == 0){
                        continue;
                    }

                    //check right-bottom
                    center_x = i;
                    center_y = j;                    
                    while(flag == 1 && center_x < N && center_y < N){

                        if(matrix[center_x][center_y] != 255){
                            printf("Die at %d,%d\n", center_x, center_y);
                            flag = 0;
                            break;
                        }
                        center_x++;
                        center_y++;
                    }
                    if(flag == 1){
                        answer++;
                    }
                }
            }
        }
        printf("%d\n", answer);
    }

    return 0;
}