#include <stdio.h>

int Pooh_turn(int);
int Piglet_turn(int);

int a, b;

int main(){

    int T;
    scanf("%d", &T);

    while(T--){
        int n;
        char name[7];
        scanf("%d %d %d %s", &n, &a, &b, name);
        if(name[1]=='o'){
            int status = Pooh_turn(n);
            if(status == 1){
                printf("Pooh\n");
            }
            else{
                printf("Piglet\n");
            }
        }
        else{
            int status = Piglet_turn(n);
            if(status == 1){
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
        return 1;
    }
    for(int i=1 ;i<=a; i++){
        if(!(Piglet_turn(n-i))){
            return 1;
        }
    }
    return 0;
}
 
int Piglet_turn(int n){
    if(n <= b){
        return 1;
    }

    for(int i=1 ;i<=b; i++){
        if(!(Pooh_turn(n-i))){
            return 1;
        }
    }
    return 0;
}