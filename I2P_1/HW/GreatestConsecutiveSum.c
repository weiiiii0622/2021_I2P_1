#include <stdio.h>

int main(){

    int N;
    scanf("%d", &N);

    int nums[N];
    for(int i=0; i<N; i++){
        scanf("%d", &nums[i]);
    }

    int now = nums[0];
    int max = nums[0];

    for(int i=1; i<N; i++){
        if(now < 0){
            now = nums[i];
        }
        else{
            now += nums[i];
        }
        if(now > max){
            max = now;
        }
    }
    printf("%d\n", max);

    return 0;
}