#include <stdio.h>
#include <string.h>

int main()
{
    int n, m, T;
    int grid[502][502], status[502][502];

    scanf("%d %d %d", &n, &m, &T);
    for(int i=1; i<=n; i++){
        for(int j=1; j<=m; j++){
            scanf("%d", &grid[i][j]);
        }
    }

    for(int a=0; a<T; a++){
        memset(status, 0, sizeof(status[0][0])*502*502);

        for(int i=1; i<=n; i++){
            for(int j=1; j<=m; j++){
                if(grid[i][j] == 1){
                    status[i-1][j-1]++;
                    status[i-1][j]++;
                    status[i-1][j+1]++;
                    status[i][j-1]++;
                    status[i][j+1]++;
                    status[i+1][j-1]++;
                    status[i+1][j]++;
                    status[i+1][j+1]++;
                }
            }
        }

        for(int i=1; i<=n; i++){
            for(int j=1; j<=m; j++){
                if(grid[i][j] == 1){
                    if(status[i][j] == 2 || status[i][j] == 3){
                        grid[i][j] = 1;
                    }
                    else{
                        grid[i][j] = 0;
                    }
                }
                else{
                    if(status[i][j] == 3){
                        grid[i][j] = 1;
                    }
                    else{
                        grid[i][j] = 0;
                    }
                }
            }
        }
    }

    for(int i=1; i<=n; i++){
        for(int j=1; j<=m; j++){
            if(j == m){
                printf("%d\n", grid[i][j]);
            }
            else{
                printf("%d ", grid[i][j]);
            }
        }
    }

    return 0;
}