#include <stdio.h>

int main(){
    int n;
    scanf("%d", &n);

    if(n%2 == 0){
        printf("Stop drawing fake diamonds!\n");
    }
    else{
        int space = (n-1)/2;
        
        for(int i=1; i<=(n+1)/2; i++){
            for(int j=0; j<space; j++){
                printf(" ");
            }
            for(int j=1; j<=2*i-1; j++){
                printf("*");
            }
            printf("\n");

            space--;
        }

        space = 1;

        for(int i=(n-1)/2; i>=1; i--){
            for(int j=0; j<space; j++){
                printf(" ");
            }
            for(int j=1; j<=2*i-1; j++){
                printf("*");
            }
            printf("\n");

            space++;
        }
    }

    return 0;
}