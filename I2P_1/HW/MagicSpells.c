#include <stdio.h>
#include <string.h>

int max(int, int);

int main(){

    int T;
    scanf("%d", &T);

    for(int q=0; q<T; q++){
        char a[1000], b[1000];
        scanf("%s %s", a, b);

        int a_len = strlen(a), b_len = strlen(b);
        int final = 0;
        for(int i=max((a_len-1),(b_len-1)); i>=0; i--){
            int j = a_len-i-1, k = 0;
            int flag = 0;
            while(k <= i){
                if(a[j] != b[k]){
                    flag = 1;
                    break;
                }
                j++, k++;
            }

            if(flag == 0){
                final = k;
                break;
            }
        }

        printf("%s", a);
        for(int i=final; i<b_len; i++){
            printf("%c", b[i]);
        }
        printf("\n");
    }

    return 0;
}

int max(int a, int b){
    if(a >= b){
        return a;
    }
    else{
        return b;
    }
}