#include <stdio.h>

int m, n, k;
int matrix[1000][1000];

void switch_matrix(int i, int j){
    for(int k=0; k<n; k++){
        int temp = matrix[i][k];
        matrix[i][k] = matrix[j][k];
        matrix[j][k] = temp;
    }
};

void add_matrix(int i, int j){
    for(int k=0; k<n; k++){
        matrix[i][k] += matrix[j][k];
    }
};

int main(){
    
    int operator, i, j;
    scanf("%d %d %d", &m, &n, &k);



    for(int i=0; i<m; i++){
        for(int j=0; j<n; j++){
            scanf("%d", &matrix[i][j]);
        }
    }

    for(int p=0; p<k; p++){
        scanf("%d %d %d", &operator, &i, &j);

        if(operator == 0){
            switch_matrix(i, j);
        }
        else{
            add_matrix(i, j);
        }
    }

    int max=0, ans_row=0, current=0;
    for(int i=0; i<m; i++){
        for(int j=0; j<n; j++){
            current += matrix[i][j]*matrix[i][j];
        }

        if(current > max){
            ans_row = i;
            max = current;
        }
        current = 0;
    }

    for(int j=0; j<n; j++){
        if(j != (n-1)){
            printf("%d ", matrix[ans_row][j]);
        }
        else{
            printf("%d\n", matrix[ans_row][j]);
        }
    }

    return 0;
}