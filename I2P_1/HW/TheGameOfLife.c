#include <stdio.h>

int n, m, T;
int grid[500][500];
int temp[500][500];

void check_dead(int, int);
void check_alive(int, int);

int main(){

    scanf("%d %d %d", &n, &m, &T);

    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            scanf("%d", &grid[i][j]);
        }
    }

    for(int a=0; a<T; a++){
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){

                if(grid[i][j] == 0){
                    check_dead(i, j);
                }
                else{
                    check_alive(i, j);
                }

            }
        }

        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                grid[i][j] = temp[i][j];
            }
        }
    }

    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(j != (m-1)){
                printf("%d ", grid[i][j]);
            }
            else{
                printf("%d\n", grid[i][j]);
            }
        }
    }

    return 0;
}

void check_dead(int i, int j){

    int survive = 0;
    if((i-1) >= 0){
        if(grid[i-1][j] == 1){
            survive++;
        }

        if((j-1) >= 0){
            if(grid[i-1][j-1] == 1){
                survive++;
            }
        }
        if((j+1) < m){
            if(grid[i-1][j+1] == 1){
                survive++;
            }
        }
    }
    if((j-1) >= 0){
        if(grid[i][j-1] == 1){
            survive++;
        }
    }
    if((j+1) < m){
        if(grid[i][j+1] == 1){
            survive++;
        }
    }
    if((i+1) < n){
        if(grid[i+1][j] == 1){
            survive++;
        }

        if((j-1) >= 0){
            if(grid[i+1][j-1] == 1){
                survive++;
            }
        }
        if((j+1) < m){
            if(grid[i+1][j+1] == 1){
                survive++;
            }
        }
    }

    if(survive == 3){
        temp[i][j] = 1;
    }
    else{
        temp[i][j] = 0;
    }
}

void check_alive(int i, int j){
    int survive = 0;
    if((i-1) >= 0){
        if(grid[i-1][j] == 1){
            survive++;
        }

        if((j-1) >= 0){
            if(grid[i-1][j-1] == 1){
                survive++;
            }
        }
        if((j+1) < m){
            if(grid[i-1][j+1] == 1){
                survive++;
            }
        }
    }
    if((j-1) >= 0){
        if(grid[i][j-1] == 1){
            survive++;
        }
    }
    if((j+1) < m){
        if(grid[i][j+1] == 1){
            survive++;
        }
    }
    if((i+1) < n){
        if(grid[i+1][j] == 1){
            survive++;
        }

        if((j-1) >= 0){
            if(grid[i+1][j-1] == 1){
                survive++;
            }
        }
        if((j+1) < m){
            if(grid[i+1][j+1] == 1){
                survive++;
            }
        }
    }
    if(survive == 2 || survive == 3){
        temp[i][j] = 1;
    }
    else{
        temp[i][j] = 0;
    }
}