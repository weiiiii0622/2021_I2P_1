#include <stdio.h>

int main(){
    int T;
    scanf("%d", &T);
    
    for(int a=0; a<T; a++){
        int deck[13] = {0};
        for(int i=0; i<5; i++){
            char card;
            scanf(" %c", &card);

            if(card == '1'){
                char waste;
                scanf("%c", &waste);
                deck[9]++;
            }
            else{
                if(card == 'A'){
                    deck[0]++;
                }
                else if(card == 'J'){
                    deck[card-64]++;
                }
                else if(card == 'Q'){
                    deck[card-70]++;
                }
                else if(card == 'K'){
                    deck[card-63]++;
                }
                else{
                    deck[card-'1']++;
                }
            }
        }

        int flag = 0;
        for(int i=0; i<13; i++){
            if(deck[i] == 1 || deck[i] > 3){
                printf("NO\n");
                flag = 1;
                break;
            }
        }

        if(flag == 0){
            printf("YES\n");
        }
    }

    return 0;
}