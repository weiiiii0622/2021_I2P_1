#include <stdio.h>
#include <string.h>

int main(){
    char word[1001];
    scanf("%s", word);

    int len = strlen(word);

    for(int i=1; i<=len; i++){
        int j = i;
        for(int k=0; k<len; k++){
            printf("%c", word[j%len]);
            j++;
        }
        printf("\n");
    }

    return 0;
}