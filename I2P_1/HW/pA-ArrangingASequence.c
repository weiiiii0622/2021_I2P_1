#include <stdio.h>
#include <string.h>

int main(){

    int n, m;
    scanf("%d %d", &n, &m);

    int num[n+1], request[m];
    memset(num, 0, (n+1)*sizeof(num[0]));

    for(int i=m-1; i>=0; i--){
        scanf("%d", &request[i]);
        if(num[request[i]] == 0){
            num[request[i]] = 1;
        }
    }

    for(int i=0; i<m; i++){
        if(num[request[i]] == 1){
            printf("%d\n", request[i]);
            num[request[i]] = -1;
        }
    }
    for(int i=1; i<=n; i++){
        if(num[i] == 0){
            printf("%d\n", i);
        }
    }

    return 0;
}