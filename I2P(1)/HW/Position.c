#include <stdio.h>
#include <string.h>

int main(){

    char word[1000001];
    int order[52];
    int i=0;
    while(1){
        scanf("%c", &word[i]);
        if(word[i] == '\n'){
            break;
        }
        if(word[i]>= 'A' && word[i] <= 'Z'){
            order[word[i]-'A'] = 1;
        }
        else{
            order[word[i]-'a'+26] = 1;
        }
        i++;
    }
    int len = i;

    for(int i=0; i<52; i++){
        if(order[i] == 1){
            char target;
            if(i<26){
                target = 'A'+i;
                printf("%c:", target);
            }
            else{
                target = 'a'+(i%26);
                printf("%c:", 'a'+(i%26));
            }

            for(int j=0; j<len; j++){
                if(word[j] == target){
                    printf(" %d", j);
                }
            }
            printf("\n");
        }
    }

    return 0;
}