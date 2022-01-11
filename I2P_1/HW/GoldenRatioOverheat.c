#include <stdio.h>
#include <string.h>

#define ll long long int 

ll t, n, k;
char f0[2001], f1[2001];
ll len[60];

char solve(ll, ll);

int main(){

    scanf("%lld", &t);
    while(t--){
        scanf("%s %s", f0, f1);
        scanf("%lld %lld", &n, &k);
        len[0] = strlen(f0);
        len[1] = strlen(f1);

        for(int i=2; i<60; i++){
            len[i] = len[i-1] + len[i-2];
        }
         
        printf("%c\n", solve(n, k));
    }
    return 0;
}

char solve(ll n, ll k){
    if(n == 0){
        return f0[k];
    }
    if(n == 1){
        return f1[k];
    }
    if(k >= len[n-2]){
        return solve(n-1, k-len[n-2]);
    }
    else{
        return solve(n-2, k);
    }
}