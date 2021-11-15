#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int main(){

    int r, c;
    int min = INT_MAX, max = INT_MIN;
    int count_min=0, count_max=0;

    scanf("%d %d", &r, &c);

    int grid[r][c];
    int min_pos[r*c][2];
    int max_pos[r*c][2];

    for(int i=0; i<r; i++){
        for(int j=0; j<c; j++){
            scanf("%d", &grid[i][j]);

            if(grid[i][j] > max){
                max = grid[i][j];
                count_max = 1;
                max_pos[0][0] = i;
                max_pos[0][1] = j;
            }
            else if(grid[i][j] == max){
                count_max++;
                max_pos[count_max-1][0] = i;
                max_pos[count_max-1][1] = j;
            }
            if(grid[i][j] < min){
                min = grid[i][j];
                count_min = 1;
                min_pos[0][0] = i;
                min_pos[0][1] = j;
            }
            else if(grid[i][j] == min){
                count_min++;
                min_pos[count_min-1][0] = i;
                min_pos[count_min-1][1] = j;
            }
        }
    }

    int max_length = 0;
    for(int i=0; i<count_min; i++){
        for(int j=0; j<count_max; j++){
            int temp_length = abs(max_pos[j][0]-min_pos[i][0]) + abs(max_pos[j][1]-min_pos[j][1]);
            if(temp_length > max_length){
                max_length = temp_length;
            }
        }
    }

    printf("%d %d", max_length, (max-min));

    return 0;
}