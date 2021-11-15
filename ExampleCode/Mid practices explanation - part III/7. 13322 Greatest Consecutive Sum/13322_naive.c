#include <stdio.h>
#include <limits.h>

int main(){
    int sum, N;
    int ans = INT_MIN;
    scanf("%d", &N);

    int array[N];

    for(int i = 0; i < N; i++){
        scanf("%d", &array[i]);
    }

    for(int start = 0; start < N; start++){
        for(int end = start; end < N; end++){
            sum = 0;
            for(int k = start; k <= end; k++){
                sum += array[k];
            }
        }
        if (sum > ans){
            ans = sum;
        }
    }

    printf("%d\n", ans);

}