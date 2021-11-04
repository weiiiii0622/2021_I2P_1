#include <stdio.h>

void swap(int a, int b, int* seat, int* answer){
    int temp_r = seat[a];
    int temp_g = answer[seat[a]];

    answer[seat[a]] = answer[seat[b]];
    seat[a] = seat[b];

    answer[seat[b]] = temp_g;
    seat[b] = temp_r;
}


int main(){
    
    int N, M, Q, a, b, K;
    scanf("%d %d %d", &N, &M, &Q);

    int seat[N+1], answer[N+1]; 
    for(int i=1; i<=N; i++){
        seat[i] = i;
        answer[i] = i;
    }

    for(int i=0; i<M; i++){
        scanf("%d %d", &a, &b);
        swap(a, b, seat, answer);
    }

    for(int i=0; i<Q; i++){
        scanf("%d", &K);
        if(i != Q-1){
            printf("%d ", answer[K]);
        }
        else{
            printf("%d\n", answer[K]);
        }
    }

    return 0;
}