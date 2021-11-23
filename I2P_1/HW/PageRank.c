#include <stdio.h>
#include <math.h>

int N;
double PR_diff;
double matrix[101][101];
double cur_PR[101], new_PR[101];


int main(){
    scanf("%d", &N);

    // 初始化各頁面 PR值
    for(int i=0; i<N; i++){
        cur_PR[i] = 1/((double)N);
    }


    // 建立轉移矩陣
    for(int i=0; i<N; i++){
        int count = 0;
        int temp_num[101];
        while(1){
            int page;
            scanf("%d", &page);
            if(page != -1){
                temp_num[count++] = page;
            }
            else{
                for(int j=0; j<count; j++){
                    matrix[i][temp_num[j]] = 1/((double)count);
                }
                break;
            }
        }
    }

    // 開始迭代
    while(1){
        for(int i=0; i<N; i++){
            for(int j=0; j<N; j++){
                //printf("cur_PR=%lf matrix[i][j]=%lf")
                new_PR[i] += cur_PR[j]*matrix[j][i];
            }

            PR_diff += fabs(new_PR[i] - cur_PR[i]);
        }

        if(PR_diff < 0.000001){
            break;
        }
        else{
            PR_diff = 0.0;
            for(int i=0; i<N; i++){
                cur_PR[i] = new_PR[i];
                new_PR[i] = 0.0; 
            }
        }
    }

    for(int i=0; i<N; i++){
        if(i != N-1){
            printf("%.2lf%% ", new_PR[i]*100);
        }
        else{
            printf("%.2lf%%\n", new_PR[i]*100);
        }
    }

    return 0;
}