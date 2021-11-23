#include <stdio.h>
#include <stdlib.h>

int n, s, t, max_steps, cur_cost, max_cost;
int energy[100001], color[100001], jumped[100001];

int valid(int ,int, int);
void cost(int);
void jump(int, int);

int main(){

    scanf("%d %d %d", &n, &s, &t);
    for(int i=1; i<=n; i++){
        scanf("%d", &energy[i]);
    }
    for(int i=1; i<=n; i++){
        scanf("%d", &color[i]);
    }

    jump(s, 0);

    printf("%d %d\n", max_cost, max_steps);

    return 0;
}

int valid(int cur, int next, int step){
    if(next == cur+1 || next == cur-1 || color[next] == color[cur]){
        int flag = 1;
        for(int i=0; i<step+1; i++){
            
            if(next == jumped[i]){
                flag = 0;
            }
        }
        if(flag == 1){
            return 1;
        }
        else{
            return 0;
        }
    }
    return 0;
}

void cost(int step){

    cur_cost = 0;

    // for(int i=0; i<step; i++){
    //     printf("%d ", jumped[i]);
    // }
    // printf("\n");

    for(int i=0; i<step-1; i++){
        cur_cost += (abs(jumped[i+1]-jumped[i])) * (abs(energy[jumped[i+1]]-energy[jumped[i]]));
    }
    
    if(cur_cost > max_cost){
        max_cost = cur_cost;
        max_steps = step-1;
    }
    else if(cur_cost == max_cost){
        if(step-1 > max_steps){
            max_steps = step-1;
        }
    }
}

void jump(int rock, int step){
    jumped[step] = rock;

    if(rock == t){

        jumped[++step] = rock;
        cost(step);
    }
    else{
        for(int i=1; i<=n; i++){
            if(valid(rock, i, step) == 1){
                jump(i, step+1);
            }
        }
    }
}