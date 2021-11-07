#include <stdio.h>

int main(){

    int L, R, max_num, max_fac=0, temp_fac;
    scanf("%d %d", &L, &R);

    for(int i=L; i<=R; i++){
        temp_fac=0;
        for(int j=2; j<=i; j++){
            if(i%j==0){
                temp_fac++;
            }
        }

        if(temp_fac >= max_fac){
            max_fac = temp_fac;
            max_num = i;
        }
    }

    printf("%d", max_num);

    return 0;
}