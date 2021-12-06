#include <stdio.h>
#include <string.h>

int n, m;
int flag, portal_count, can_teleport;
char grid[1005][1005];
int status[1005][1005];
char portal[1000001][2];

int pos_x[4] = {-1, 0, 1, 0};
int pos_y[4] = {0, 1, 0, -1};


void go(int, int);
int valid(int, int);

int main(){

    int T;
    scanf("%d", &T);

    for(int a=0; a<T; a++){
        flag = 0;
        portal_count = 0;
        can_teleport = 0;
        memset(status, 0, 1005*1005*sizeof(status[0][0]));
        scanf("%d %d", &n, &m);
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                scanf(" %c", &grid[i][j]);
                if(grid[i][j] == 'T'){
                    portal[portal_count][0] = i;
                    portal[portal_count][1] = j;
                    portal_count++;
                }
            }
        }

        
        go(0, 0);

        if(flag == 0){
            if(can_teleport == 1){
                for(int i=0; i<portal_count; i++){
                    if(valid(portal[portal_count][0], portal[portal_count][1])){
                        go(portal[portal_count][0], portal[portal_count][1]);
                    }
                }
            }
        }


        if(flag == 1){
            printf("Yes\n");
        }
        else{
            printf("No\n");
        }
    }
    return 0;
}

void go(int x, int y){
    //printf("x=%d y=%d step=%d\n", x, y, step);
    status[x][y]++;

    if(flag == 1){
        return;
    }
    if(x == (n-1) && y == (m-1)){
        flag = 1;
        return;
    }
    else{
        if(grid[x][y] == 'T'){
            can_teleport = 1;
            //return;
        }

        for(int i=0; i<4; i++){
            if(valid(x+pos_x[i], y+pos_y[i])){
                go(x+pos_x[i], y+pos_y[i]);

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