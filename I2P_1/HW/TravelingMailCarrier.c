#include <stdio.h>
#include <stdbool.h>
#include <limits.h>

int n, distance, min_distance = INT_MAX;
int matrix[10][10], route[11];
bool visit[10];

void dfs(int);
int cost();

int main(){

    scanf("%d", &n);
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            scanf("%d", &matrix[i][j]);
        }
    }

    route[0] = 0;
    visit[0] = true;
    dfs(1);

    printf("%d\n", min_distance);    
    return 0;
}

int cost(){
    int dist=0;
    for(int i=0; i<n; i++){
        dist += matrix[route[i]][route[i+1]];
    }
    return dist;
}

void dfs(int step){
    if(step == n){
        route[n] = 0;
        distance = cost();
        min_distance = distance<min_distance ? distance : min_distance;
    }
    else{
        for(int i=0; i<n; i++){
            if(!visit[i]){
                route[step] = i;
                visit[i] = true;
                dfs(step+1);
                visit[i] = false;
            }
        }
    }
}