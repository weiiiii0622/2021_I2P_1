#include <stdio.h>
#include <limits.h>

int main(){
    int sum = 0, in, N;
    int ans = INT_MIN;
    scanf("%d", &N);

    while(N--){
        scanf("%d", &in);
        sum += in;
        if (sum > ans)
            ans = sum;
        if (sum < 0)
            sum = 0;        
    }

    printf("%d\n", ans);

}