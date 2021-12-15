#include <stdio.h>
#include <string.h>

int Pooh(int);
int Piglet(int);

int T;
int n, a, b, Ma, Mb;
char name[7];
int status[100005][2];

int main(){

    scanf("%d", &T);

    while(T--){
        memset(status, -1, 100005*2*sizeof(status[0][0]));
        scanf("%d %d %d %d %d %s", &n, &a, &b, &Ma, &Mb, name);
        for(int i=0; i<Ma; i++){
            int temp;
            scanf("%d", &temp);
            status[temp][0] = 1;
        }
        for(int i=0; i<Mb; i++){
            int temp;
            scanf("%d", &temp);
            status[temp][1] = 1;
        }

        if(name[1] == 'o'){
            if(Pooh(n)){
                printf("Pooh\n");
            }
            else{
                printf("Piglet\n");
            }
        }
        else{
            if(Piglet(n)){
                printf("Piglet\n");
            }
            else{
                printf("Pooh\n");
            }
        }

    }

    return 0;
}

int Pooh(int n){
    if(status[n][0] != -1){
        return status[n][0];
    }
    if(n <= a){
        return status[n][0] = 1;
    }

    for(int i=1; i<=a; i++){
        if(!(Piglet(n-i))){
            return status[n][0] = 1;
        }
    }

    for(int i=1; i<=b; i++){
        status[n+i][1] = 1;
    }
    return status[n][0] = 0;

}

int Piglet(int n){
    if(status[n][1] != -1){
        return status[n][1];
    }
    if(n <= b){
        return status[n][1] = 1;
    }

    for(int i=1; i<=b; i++){
        if(!(Pooh(n-i))){
            return status[n][1] = 1;
        }
    }

    for(int i=1; i<=a; i++){
        status[n+i][0] = 1;
    }
    return status[n][1] = 0;
}