#include <stdio.h>

//Floor table; global variables initialized automatically
char Floor[2505][2505];//all set to '\0'
int N, M;//floor size
int x, y;//current position

//Clockwise:
//Dir[0]: Down
//Dir[1]: Left
//Dir[2]: Up
//Dir[3]: Right
int Dir[4][2] = {{1,0},{0,-1},{-1,0},{0,1}};
int d;//current direction

void moveOneSquare() {
    int new_x = x + Dir[d][0], new_y = y + Dir[d][1];
    if(new_x < 0 || new_x >= N || new_y < 0 || new_y >= M || Floor[new_x][new_y] != '\0') {
        d = (d+1) % 4;
        new_x = x + Dir[d][0];
        new_y = y + Dir[d][1];
    }
    x = new_x;
    y = new_y;
    Floor[x][y] = 'm';
}
int main(){
    int steps;
    scanf("%d%d",&N, &M);
    steps = (N*M+1) / 2;

    //for initial position and direction
    d = 0;
    x = -1;
    y = M-1;

    while(steps-- > 0) {
        //To 1st floor square
		moveOneSquare();
        printf("%d %d\n", x, y);
        //To 2nd floor square
		if(!(steps == 0 && N*M % 2 == 1)) {
            moveOneSquare();
        }
    }
}
