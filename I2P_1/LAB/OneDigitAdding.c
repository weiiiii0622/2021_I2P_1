#include <stdio.h>

int main(){
    long long a, k;
    scanf("%d %d", &a, &k);

    long long answer = 0;
    long long b = a;
    for(int i=0; i<k; i++){
        answer += b;
        b = b*10 + a;
    }
    
    printf("%lld\n", answer);
    return 0;
}