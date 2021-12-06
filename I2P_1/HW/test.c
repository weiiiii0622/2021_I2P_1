#include <stdio.h>

int way;
int n;
int binary_tree[5005];


void res(int node){
    if (way==0){
        printf("%d ", binary_tree[node]);
        
        if (2*node <= n){
            res(2*node);
        }
        if (2*node+1 <= n){
            res(2*node+1);
        }
    }
    if (way==2){
        if (2*node <= n){
            res(2*node);
        }
        if (2*node+1 <= n){
            res(2*node+1);
        }
        printf("%d ", binary_tree[node]);
    }
    if (way==1){
        if (2*node <= n){
            res(2*node);
        }
        printf("%d ", binary_tree[node]);
        if (2*node+1 <= n){
            res(2*node+1);
        }
    }
}

int main(){
    
    scanf("%d",&way);
    scanf("%d",&n);
    
    for (int i=1;i<=n;i++){
        scanf("%d", &binary_tree[i]);
    }

    res(1);

    return 0;
}