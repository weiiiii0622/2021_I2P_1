#include <stdio.h>
#include <string.h>

int n, m;
int direction = 1; //down=1, left=2, up=3, right=4
int grid[2500][2500];
int pos[2];

void go_down();
void go_left();
void go_up();
void go_right();

int main(){

    scanf("%d %d", &n, &m);

    pos[0] = 0;
    pos[1] = m-1;
    printf("%d %d\n", pos[0], pos[1]);

    memset(grid, 0, 2500*2500*sizeof(grid[0][0]));
    grid[0][m-1] = 1;


    for(int i=1; i<(n*m+1)/2; i++){
        if(direction == 1){
            go_down();
            if(direction == 1){
                go_down();
                printf("%d %d\n", pos[0], pos[1]);
            }
            else if(direction == 2){
                go_left();
                printf("%d %d\n", pos[0], pos[1]);
            }
            else{
                printf("%d %d\n", pos[0], pos[1]);
            }
        }

        else if(direction == 2){
            go_left();
            if(direction == 2){
                go_left();
                printf("%d %d\n", pos[0], pos[1]);
            }
            else if(direction == 3){
                go_up();
                printf("%d %d\n", pos[0], pos[1]);
            }
            else{
                printf("%d %d\n", pos[0], pos[1]);
            }
        }

        else if(direction == 3){
            go_up();
            if(direction == 3){
                go_up();
                printf("%d %d\n", pos[0], pos[1]);
            }
            else if(direction == 4){
                go_right();
                printf("%d %d\n", pos[0], pos[1]);
            }
            else{
                printf("%d %d\n", pos[0], pos[1]);
            }
        }

        else{
            go_right();
            if(direction == 4){
                go_right();
                printf("%d %d\n", pos[0], pos[1]);
            }
            else if(direction == 1){
                go_down();
                printf("%d %d\n", pos[0], pos[1]);
            }
            else{
                printf("%d %d\n", pos[0], pos[1]);
            }
        }
        for(int p=0; p<n; p++){
            for(int j=0; j<m; j++){
                printf("%d ", grid[p][j]);
            }
            printf("\n");
        }

    }

    return 0;
}

void go_down(){
    if(pos[0]+1 >= n || grid[pos[0]+1][pos[1]] == 1){
        if(grid[pos[0]][pos[1]-1] == 1){
            direction = 0;
            return;
        }
        else{
            direction = 2;
            pos[1] -= 1;
            grid[pos[0]][pos[1]] = 1;
        }
    }
    else{
        pos[0] += 1;
        grid[pos[0]][pos[1]] = 1;
    }
}


void go_left(){
    if(pos[1]-1 < 0 || grid[pos[0]][pos[1]-1] == 1){
        if(grid[pos[0]-1][pos[1]] == 1){
            direction = 0;
            return;
        }
        else{
            direction = 3;
            pos[0] -= 1;
            grid[pos[0]][pos[1]] = 1;
        }
    }
    else{
        pos[1] -= 1;
        grid[pos[0]][pos[1]] = 1;
    }
}


void go_up(){
    if(pos[0]-1 < 0 || grid[pos[0]-1][pos[1]] == 1){
        if(grid[pos[0]][pos[1]+1] == 1){
            direction = 0;
            return;
        }
        else{
            direction = 4;
            pos[1] += 1;
            grid[pos[0]][pos[1]] = 1;
        }
    }
    else{
        pos[0] -= 1;
        grid[pos[0]][pos[1]] = 1;
    }
}


void go_right(){
    if(pos[1]+1 >= m || grid[pos[0]][pos[1]+1] == 1){
        if(grid[pos[0]+1][pos[1]] == 1){
            direction = 0;
            return;
        }
        else{
            direction = 1;
            pos[0] += 1;
            grid[pos[0]][pos[1]] = 1;
        }
    }
    else{
        pos[1] += 1;
        grid[pos[0]][pos[1]] = 1;
    }
}
