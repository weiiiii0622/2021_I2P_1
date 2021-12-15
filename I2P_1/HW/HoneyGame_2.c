#include <stdio.h>
#include <string.h>

int sum();

int T;
int n, a, b, Ma, Mb;
char name[7];
int status_Pooh[100005];
int special[100005][2];

int main(){

    scanf("%d", &T);

    while(T--){
        memset(status, -1, 100005*sizeof(status[0]));
        scanf("%d %d %d %d %d %s", &n, &a, &b, &Ma, &Mb, name);
        for(int i=0; i<Ma; i++){
            int temp;
            scanf("%d", temp);
            special[temp][0] = 1;
        }
        for(int i=0; i<Mb; i++){
            int temp;
            scanf("%d", temp);
            special[temp][1] = 1;
        }

        if(name[1] == 'o'){
            if(1){
                printf("Pooh\n");
            }
            else{
                printf("Piglet\n");
            }
        }
        else{
            if(1){
                printf("Piglet\n");
            }
            else{
                printf("Pooh\n");
            }
        }

    }

    return 0;
}

int sum(){
    int i=1;
    while(i <= n){

    }
}