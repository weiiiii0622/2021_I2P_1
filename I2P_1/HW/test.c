<<<<<<< HEAD
#include<stdio.h>

int main()
{
    int arr[][4][4] = {
                        
                        {{0,2,3,4},{5,6,7,8},{9,10,11,12},{13,14,15,16}},
                        {{17,18,19,20},{21,22,23,24},{25,26,27,28},{29,30,31,32}}
                        
                    };

    int i, j, k;
    int (*p)[4][4];

    p = arr;

    for(i = 0; i < 2; i++)
    {
        //printf("Address of %d th array %u \n",i , p + i);
        for(j = 0; j < 4; j++)
        {
            //printf("Address of %d th array %u \n",i , p + i);
            for(k=0; k<4; k++){
                printf("arr[%d][%d][%d]=%d\n", i, j, k, *(*( *(p + i) + j)+k) );
            }
            printf("\n");
        }
        printf("\n\n");
    }

    // signal to operating system program ran fine
=======
#include <stdio.h>

int way;
int n;
int binary_tree[5005];


void res(int node){
    if (way==0){
        printf("%d ", binary_tree[node]);
        
        if (2*node <= n){
            res(2*node);
        }
        if (2*node+1 <= n){
            res(2*node+1);
        }
    }
    if (way==2){
        if (2*node <= n){
            res(2*node);
        }
        if (2*node+1 <= n){
            res(2*node+1);
        }
        printf("%d ", binary_tree[node]);
    }
    if (way==1){
        if (2*node <= n){
            res(2*node);
        }
        printf("%d ", binary_tree[node]);
        if (2*node+1 <= n){
            res(2*node+1);
        }

    }
<<<<<<< HEAD
}

int main(){
    
    scanf("%d",&way);
    scanf("%d",&n);
    
    for (int i=1;i<=n;i++){
        scanf("%d", &binary_tree[i]);
    }

    res(1);
=======
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
>>>>>>> 0df81d38c7df6a8a590225e168809131c947f9dc

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
>>>>>>> a80cd9f9e6e34b9f2f7ef95e850eada0d9512c8a
    return 0;
}