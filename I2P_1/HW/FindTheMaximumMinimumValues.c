#include <stdio.h>
#include <stdlib.h>

int main(){

    int R, C, max, max_i=0, max_j=0, min, min_i=0, min_j=0;
    int flag = 0;
    scanf("%d %d", &R, &C);

    int grid[R][C];
    for(int i=0; i<R; i++){
        for(int j=0; j<C; j++){
            scanf("%d", &grid[i][j]);
            if(flag == 0){
                max = grid[i][j];
                min = grid[i][j];
                flag = 1;
            }
            else{
                if(grid[i][j] > max){
                    max = grid[i][j];
                    max_i = i;
                    max_j = j;
                }
                else if(grid[i][j] < min){
                    min = grid[i][j];
                    min_i = i;
                    min_j = j;
                }
            }
        }
    }

    printf("%d %d", (abs(max_i - min_i) + abs(max_j - min_j)), abs(max - min));

    return 0;
}