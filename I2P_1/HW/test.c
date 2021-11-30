#include <stdio.h>
#include <string.h>

int n, m;
int flag, start_flag, end_flag;
char grid[1005][1005];
int status[1005][1005];

int pos_x[4] = {-1, 0, 1, 0};
int pos_y[4] = {0, 1, 0, -1};

void go(int, int);
void find_end_portal(int, int);
int valid(int, int);

int main(){

    int T;
    scanf("%d", &T);

    for(int a=0; a<T; a++){
        start_flag = 0;
        end_flag = 0;
        flag = 0;
        
        scanf("%d %d", &n, &m);
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                scanf(" %c", &grid[i][j]);
            }
        }
        memset(status, 0, 1005*1005*sizeof(status[0][0]));
        go(0, 0);
        

        if(flag == 0 && start_flag == 1 && valid(n-1, m-1)){
            memset(status, 0, 1005*1005*sizeof(status[0][0]));
            find_end_portal(n-1, m-1);
        }

        if(flag == 1){
            printf("Yes\n");
        }
        else if(start_flag == 1 && end_flag == 1){
            printf("Yes\n");
        }
        else{
            printf("No\n");
        }

    }
    return 0;
}

void go(int x, int y){

    status[x][y]++;

    if(flag == 1){
        return;
    }
    if(x == (m-1) && y == (m-1)){
        flag = 1;
        return;
    }
    else{
        if(grid[x][y] == 'T'){
            start_flag = 1;
        }

        for(int i=0; i<4; i++){
            if(valid(x+pos_x[i], y+pos_y[i])){
                go(x+pos_x[i], y+pos_y[i]);
            }
        }
    }
}

void find_end_portal(int x, int y){

    status[x][y]++;

    if(end_flag == 1){
        return;
    }
    // if(x == 0 && y == 0){
    //     flag = 1;
    //     return;
    // }
    else{
        if(grid[x][y] == 'T'){
            end_flag = 1;
            return;
        }
        else{
            for(int i=0; i<4; i++){
                if(valid(x+pos_x[i], y+pos_y[i])){
                    find_end_portal(x+pos_x[i], y+pos_y[i]);
                }
            }
        }
    }
}

int valid(int x, int y){
    if(x>=0 && y>=0 && x<n && y<m){
        if(grid[x][y] == '#'){
            return 0;
        }
        else if(status[x][y] != 0){
            return 0;
        }
        return 1;
    }
    return 0;
}