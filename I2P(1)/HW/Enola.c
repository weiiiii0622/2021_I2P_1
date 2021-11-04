#include <stdio.h>

int main(){
    int n, m;

    while(scanf("%d %d", &n, &m) != EOF){

        int a_count[26] = {0}, b_count[26] = {0};
        char a[n], b[m];
        int flag = 0;

        for(int i=0; i<n; i++){
            scanf(" %c", &a[i]);
            a_count[a[i]-'a']++;
        }

        for(int i=0; i<m; i++){
            scanf(" %c", &b[i]);
            b_count[b[i]-'a']++;
        }

        if(n != m){
            printf("NO\n");
        }

        else{
            for(int i=0; i<26; i++){
                if(a_count[i] != 0){
                    if(a_count[i] != b_count[i]){
                        printf("NO\n");
                        flag = 1;
                        break;
                    }
                }
            }

            if(flag == 0){
                printf("YES\n");
            }
        }
    }

    return 0;
}