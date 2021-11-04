#include <stdio.h>

int main(){

    int n, i, x=0, y=0;
    scanf("%d", &n);
    int len = 2*n;
    int grid[len][len];

    for(i=1;i<=len;i++){
        grid[0][i-1] = i;
    }
    y=len-1;
    len--;

    while(len>0){

        for(int move=0; move<len;move++,i++){
            x++;
            grid[x][y] = i;
        }
        
        for(int move=0; move<len;move++,i++){
            y--;
            grid[x][y] = i;
        }
        
        len--;
        if(len == 0){
            break;
        }
        
        for(int move=0; move<len;move++,i++){
            x--;
            grid[x][y] = i;
        }
        
        for(int move=0; move<len;move++,i++){
            y++;
            grid[x][y] = i;
        }
        len--;
        if(len == 0){
            break;
        }
    }

    for(int i=0; i<2*n; i++){
        for(int j=0; j<2*n; j++){
            if(j!=(2*n-1)){
                printf("%d ", grid[i][j]);
            }
            else{
                printf("%d\n", grid[i][j]);
            }
        }
    }

    return 0;
}