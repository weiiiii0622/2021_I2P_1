#include <stdio.h>
#include <string.h>

int main(){
    char A[4];
    scanf("%s", A);
    int A_len = strlen(A);

    int n;
    scanf("%d", &n);

    int max = 0, temp = 0;
    for(int a=0; a<n; a++){
        char B[9];
        scanf("%s", B);
        int B_len = strlen(B);

        for(int i=0; i<(B_len-A_len+1); i++){
            int flag = 0;
            

            if(B[i] == A[0]){
                for(int j=1; j<A_len; j++){
                    if(B[i+j] != A[j]){
                        flag = 1;
                        break;
                    }
                }

                if(flag == 0){
                    temp++;
                }

            }
        }
        if(temp > max){
            max = temp;
        }
        temp = 0;
    }

    printf("%d", max);
    return 0;
}