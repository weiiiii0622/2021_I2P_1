#include <stdio.h>
#include <string.h>


int dp[101][101];
int combination(int, int);

int main(){

    int N, answer = 1;
    memset(dp, -1, sizeof(dp[0][0])*101*101);
    scanf("%d", &N);

    int n[N], k[N];   
    for(int i=0; i<N; i++){
        scanf("%d", &n[i]);
    }
    for(int i=0; i<N; i++){
        scanf("%d", &k[i]);

        answer = (answer*combination(n[i], k[i]))%10007;
    }

    printf("%d\n", answer);
    return 0;
}

int combination(int n, int k){

    if(dp[n][k] != -1){
        return dp[n][k];
    }
    else{
        if(n == k || k == 0){
            dp[n][k] = 1;
            return 1;
        }
        else if(k == 1 || n-k == 1){
            dp[n][k] = n;
            return n;
        }
        else{
            dp[n][k] = (combination(n-1, k)+combination(n-1, k-1))%10007;
            return dp[n][k];
        }
    }
}