#include <stdio.h>
#include <string.h>

char k[21], str[99999], *r;
char d[15] = {' ', '\n', '-', '/', ':', '(', ')', '[', ']', ',', '.'};

int main(){
    int i, ans=0;
    scanf("%s", k);
    while(fgets(str, 99999, stdin) != NULL){
        r = strtok(str, d);
        while(r != NULL){
            if(strlen(r) != strlen(k)){
                r = strtok(NULL, d);
                continue;
            }
            else{
                for(i=0; i<strlen(k); i++){
                    if(r[i]-32 != k[i] && r[i] != k[i] && r[i]+32 != k[i]){
                        break;
                    }
                }
                if(i == strlen(k)){
                    ans++;
                }
                r = strtok(NULL, d);
            }
        }
    } 

    printf("%d\n", ans);
    return 0;
}