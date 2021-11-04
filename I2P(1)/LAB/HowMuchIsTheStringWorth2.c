#include <stdio.h>

int main(){
    
    char coins[123];
    for(int i=1; i<=26; i++){
        char C;
        scanf("%c", &C);
        coins[C] = i;
    }
    char waste;
    scanf("%c", &waste);

    char input, T[101];
    int i=0;
    while(scanf("%c", &input) != EOF){
        
        if(input != '\n'){
            T[i++] = input;
        }
        else{
            if(T[0] == '0' && i == 1){
                break;
            }
            else if(T[0] == 'e'&& T[1] == 'n' && T[2] == 'd' && i == 3){
                break;
            }
            else{
                int value = 0;
                for(int a=0; a<i; a++){
                    if(T[a] >= 97 && T[a] <= 122){
                        value += coins[T[a]];
                    }
                }

                printf("%d\n", value);
            }
            i=0;
        }
    }

    return 0;
}