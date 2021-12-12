#include <stdio.h>
#include <string.h>

int Pooh_turn(int);
int Piglet_turn(int);
int status[10001][2] = {-1};

int a, b;

int main(){

    int T;
    scanf("%d", &T);

    while(T--){
        int n;
        char name[7];
        memset(status, -1, 10001*2*sizeof(status[0][0]));
        scanf("%d %d %d %s", &n, &a, &b, name);
        if(name[1]=='o'){
            int result = Pooh_turn(n);
            if(result == 1){
                printf("Pooh\n");
            }
            else{
                printf("Piglet\n");
            }
        }
        else{
            int result = Piglet_turn(n);
            if(result == 1){
                printf("Piglet\n");
            }
            else{
                printf("Pooh\n");
            }
        }
    }

    return 0;
}

int Pooh_turn(int n){
    if(n <= a){
        return status[n][0] = 1;
    }
    if(status[n][0] != -1){
        return status[n][0];
    }
    else{
        for(int i=1 ;i<=a; i++){        
            if(!(Piglet_turn(n-i))){
                return status[n][0] = 1;
            }
        }
    }
    return status[n][0] = 0;
}
 
int Piglet_turn(int n){
    if(n <= b){
        return status[n][1] = 1;
    }
    if(status[n][1] != -1){
        return status[n][1];
    }
    for(int i=1 ;i<=b; i++){
        if(!(Pooh_turn(n-i))){
            return status[n][1] = 1;
        }
    }
    return status[n][1] = 0;
}