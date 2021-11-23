#include <stdio.h>
#include <string.h>

int main(){

    int n, m;
    scanf("%d %d", &n, &m);

    int floor[m], top[m], final_status[n]; //floor 紀錄'x'的最高高度 top 紀錄'o'的最低高度 final_status 紀錄最後每行會不會被消掉
    char grid[n][m]; //紀錄盤面

    memset(top, 0, m*sizeof(top[0]));
    memset(final_status, 0, n*sizeof(final_status[0]));
    for(int i=0; i<m; i++){
        floor[i] = n;
    }

    int lowest = 1;
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            scanf(" %c", &grid[i][j]);

            if(grid[i][j] == 'o'){
                top[j] = i+1;
                if(top[j] > lowest){
                    lowest = top[j];
                }
            }
        }
    }

    for(int j=0; j<m; j++){
        for(int i=top[j]; i<n; i++){
            if(grid[i][j] == 'x'){
                floor[j] = i;
                break;
            }
        }
    }

    // printf("\n");
    // for(int i=0; i<m; i++){
    //     printf("%d: top=%d floor=%d\n", i, top[i], floor[i]);
    // }


    //計算最大下移距離
    int min_drop = n;
    for(int i=0; i<m; i++){
        if(top[i] != 0){
            int drop = floor[i] - top[i];

            if(drop < min_drop){
                min_drop = drop;
            }
        }

    }
    // printf("min_drop = %d\n", min_drop);

    //移動盤面
    for(int i=lowest-1; i>=0; i--){
        for(int j=0; j<m; j++){
            if(grid[i][j] == 'o'){
                grid[i][j] = '.';
                grid[i+min_drop][j] = 'x';
            }
        }
    }


    //檢查會不會被消掉 當整排為'.'時即可停止檢查
    int kill = 0;
    for(int i=n-1; i>=0; i--){
        int flag = 1, dot = 0;
        for(int j=0; j<m; j++){
            if(grid[i][j] == '.'){
                flag = 0;
                dot++;
            }
        }

        if(flag == 1){
            kill++;
            final_status[i] = 1;
        }
        else if(dot == m){
            break;
        }
    }
    // printf("kill = %d\n", kill);

    //印出最終盤面
    for(int i=0; i<kill; i++){
        for(int j=0; j<m; j++){
            printf(".");
        }
        printf("\n");
    }
    for(int i=0; i<n; i++){
        if(final_status[i] == 0){
            for(int j=0; j<m; j++){
                printf("%c", grid[i][j]);
            }
            printf("\n");
        }
    }

    return 0;
}