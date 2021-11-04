#include <stdio.h>

void swap(int, int, int*);
int find(int, int*);

int N, M, a, b;

int main(){
    
    scanf("%d %d", &N, &M);
    int seat[N];
    for(int i=1; i<=N; i++){
        seat[i-1] = i;
    }

    for(int i=0; i<M; i++){
        scanf("%d %d", &a, &b);
        swap(find(a, seat), find(b, seat), seat);
    }

    for(int i=0; i<N; i++){
        if(i!=N-1){
            printf("%d ", seat[i]);
        }
        else{
            printf("%d\n", seat[i]);
        }
    }

    return 0;
}

void swap(int a, int b, int* seat){
    int temp;
    temp = seat[a];
    seat[a] = seat[b]; 
    seat[b] = temp;
}

int find(int x, int* seat){
    for(int i=0; i<N; i++){
        if(seat[i] == x){
            return i;
        }
    }
}