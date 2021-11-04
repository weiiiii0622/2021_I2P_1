#include<stdio.h>

int main(){

    int n;

    scanf("%d", &n);

    int i1=0,i2=n*2-1; //x邊界(i1~i2)

    int j1=0,j2=n*2-1; //y邊界(j1~j2)

    int grid[n*2][n*2];

    int x=0,y=0;//第(x,y)項

    int num=1;

    int max=n*n*4;//網格最大值

    while(num<=max){

        for(x=i1,y=j1;x<=i2;x++,num++){
            grid[x][y]=num;

        }
        j1++;

        for(x=i2,y=j1;y<=j2;y++,num++){
            grid[x][y]=num;  

        }
        i2--;
        
        if(num>max){
            break;
        }

        for(x=i2,y=j2;i1<=x;x--,num++){
            grid[x][y]=num;

        }
        j2--;

        for(x=i1,y=j2;j1<=y;y--,num++){
            grid[x][y]=num;

        }
        i1++;
    }

    x=0,y=0;

    while(y<=n*2-1){

        for(x=0;x<=n*2-1;x++){

            printf("%d ", grid[x][y]);
        }
        

        y=y+1;

        printf("\b\n");
    }



    return 0;

}