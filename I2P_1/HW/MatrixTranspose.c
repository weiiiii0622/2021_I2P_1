#include <stdio.h>

int main(){

    int x, y;
    scanf("%d %d", &x, &y);

    int matrix[x][y];
    for(int i=0; i<x; i++){
        for(int j=0; j<y; j++){
            scanf("%d", &matrix[i][j]);
        }
    }

    for(int j=0; j<y; j++){
        for(int i=0; i<x; i++){
            if(i != (x-1)){
                printf("%d ", matrix[i][j]);
            }
            else{
                printf("%d\n", matrix[i][j]);
            }
        }
    }

    return 0;
}