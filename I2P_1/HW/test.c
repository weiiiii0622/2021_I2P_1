#include<stdio.h>
#define num 11111

void postorder(int);
void inorder(int);
void preorder(int);

int tree[num] = {0};
int main () {
    int x,y,i;
    int n = 1;

    scanf("%d",&x);
    scanf("%d",&y);
    for(i = 1; i <= y; i++){
        scanf("%d",&tree[i]);
    }

    if(x == 0){
        preorder(1);
    }
    if(x == 1){
        inorder(1);
    }
    if(x == 2){
        postorder(1);
    }

}

void preorder(int n){
    if(tree[n] != 0){
        printf("%d ",tree[n]);
        preorder(2 * n);
        preorder(2 * n + 1);
    }
}
void inorder(int n){
    if(tree[n] != 0){
        inorder(2 * n);
        printf("%d ",tree[n]);
        inorder(2 * n + 1);
    }
}
void postorder(int n){
    if(tree[n] != 0){
        postorder(2 * n);
        postorder(2 * n + 1);
        printf("%d ",tree[n]);
    }
}