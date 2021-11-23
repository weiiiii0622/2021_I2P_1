#include <stdio.h>
#include <string.h>

#define max(a ,b) (a>=b ? a : b)

int main(){
    int T;
    scanf("%d", &T);

    while(T--){
        char A[2001], B[2001];
        scanf("%s %s", A, B);

        int Q;
        scanf("%d", &Q);

        while(Q--){
            int L, R;
            scanf("%d %d", &L, &R);

            int len = max(R-L+1, strlen(B));

            int ans = 1;

            for(int a = 1; a <= len; a++){
                int flag = 0;
            // check each character
                for(int i = 0; i < a; i++){
                    if(A[(R+1-a+i)] != B[i]){
                        flag = 1;
                        break;
                    }
                }
                if(flag == 0){
                    ans++;
                }
            }
            printf("%d\n", ans);
        }
    }
    return 0;
}