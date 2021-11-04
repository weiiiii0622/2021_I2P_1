#include <stdio.h>
#include <string.h>

int main(){

    int n, m;
    scanf("%d %d", &n, &m);

    char S1[n][1001], S2[m][1001];

    for(int i=0; i<n; i++){
        scanf("%s", S1[i]);
    }

    for(int i=0; i<m; i++){
        int flag = 0;
        scanf("%s", S2[i]);
        for(int j=0; j<n; j++){
            if(strlen(S2[i]) == strlen(S1[j])){
                if(strcmp(S2[i], S1[j]) == 0){
                    flag = 1;
                    printf("Yes\n");
                }
            }
        }
        if(flag == 0){
            printf("No\n");
        }
    }
    return 0;
}