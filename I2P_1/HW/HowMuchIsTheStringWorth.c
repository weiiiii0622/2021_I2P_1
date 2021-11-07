#include <stdio.h>
#include <string.h>

int main(){
    char a, T[100];
    int i=0;

    while(scanf("%c", &a) != EOF){
        if(a != '\n'){
            T[i++] = a;
        }
        else{
            if(T[0] == '0' && i == 1){
                break;
            }
            else{
                int value = 0;
                for(int j=0; j<i; j++){
                    if(T[j] >= 'a' && T[j] <= 'z'){
                        value += (T[j] - ('a' - 1));
                    }
                }
                printf("%d\n", value);
            }

            i=0;
        }
    }
    return 0;
}