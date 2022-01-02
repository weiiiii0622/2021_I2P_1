#include <stdio.h>
#include <string.h>
#include <limits.h>

int n, m;
int table[4][17];
int min_step;

int check();
void flip(int, int);
void dfs(int, int, int);

int main(){
    int t;
    scanf("%d", &t);

    while (t--){
        char c;
        min_step = 99;
        scanf("%d %d", &n, &m);
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                scanf(" %c", &c);
                table[i][j] = c=='w'?1:0;
            }
        }

        dfs(0,0,0);

        if(min_step != 99){
            printf("%d\n", min_step);
        }
        else{
            printf("%s\n", "oops");
        }
    }

    return 0;
}

void flip(int x, int y){
    table[x][y] = !table[x][y];
    if(x-1>=0){
        table[x-1][y] = !table[x-1][y];
    }
    if(x+1<n){
        table[x+1][y] = !table[x+1][y];
    }
    if(y-1>=0){
        table[x][y-1] = !table[x][y-1];
    }
    if(y+1<m){
        table[x][y+1] = !table[x][y+1];
    }    
}

void dfs(int x, int y, int step){
    if(x == n){
        if(check()){
            min_step = step<min_step?step:min_step;
        }
        return;
    }
    if(y == m-1){
        dfs(x+1, 0, step);
        flip(x, y);
        dfs(x+1, 0, step+1);
        flip(x, y);
    }
    else{
        dfs(x, y+1, step);
        flip(x, y);
        dfs(x, y+1, step+1);
        flip(x, y);
    }



}

int check(){
    int c = table[0][0];
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(table[i][j] != c){
                return 0;
            }
        }
    }
    return 1;
}