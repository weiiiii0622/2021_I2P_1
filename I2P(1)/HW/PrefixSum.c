#include <stdio.h>

int main(){

    int N;
    scanf("%d", &N);

    long long list[N];
    scanf("%lld", &list[0]);

    for(int i=1; i<N; i++){
        scanf("%lld", &list[i]);    
        list[i] +=  list[i-1];
    }

    int M;
    scanf("%d", &M);

    for(int i=0; i<M; i++){
        int L, R;
        scanf("%d %d", &L, &R);
        if(L == 1){
            printf("%lld\n", list[R-1]);
        }
        else{
            printf("%lld\n", (list[R-1] - list[L-2]));
        }
    }

    return 0;
}