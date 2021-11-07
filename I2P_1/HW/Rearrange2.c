#include <stdio.h>

void swap(int, int, int*, int*);

int main(){

    int N, M, Q;
    scanf("%d %d %d", &N, &M, &Q);

    int seat[N], order[N];
    for(int i=0; i<N; i++){
        seat[i] = i+1;
        order[i] = i+1;
    }

    for(int i=0; i<M; i++){
        int a, b;
        scanf("%d %d", &a, &b);

        swap(a, b, seat, order);

    }

    for(int i=0; i<Q; i++){
        int x;
        scanf("%d", &x);

        if(i != Q-1){
            printf("%d ", order[x-1]);
        }
        else{
            printf("%d\n", order[x-1]);
        }
    }
    
    return 0;
}

void swap(int a, int b, int* seat, int* order){
    int temp_order = order[seat[a-1]-1];
    int temp_seat = seat[a-1];

    order[seat[a-1]-1] = order[seat[b-1]-1];
    seat[a-1] = seat[b-1];

    order[seat[b-1]-1] = temp_order;
    seat[b-1] = temp_seat;
}