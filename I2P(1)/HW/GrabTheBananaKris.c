#include <stdio.h>

int main(){

    int pointer = 0, wrong = 0;
    char input, target[7] = {"BANANA"};

    while(scanf(" %c", &input) != EOF){
        if(input == '0'){
            printf("No potassium.\n");
            break;
        }
        if(pointer <= 5){
            if(input == target[pointer]){
                printf("%d\n", pointer+1);
                pointer++;
            }
            else if(input == '/'){
                wrong--;
                if(wrong == 0){
                    printf("%d\n", pointer+1);
                    pointer++;
                }
                else{
                    printf("%d\n", pointer+1);
                }
            }
            else{
                printf("-1\n");
                if(wrong == 0){
                    pointer--;
                }
                wrong++;

            }
            if(pointer == 6){
                printf("Potassium!\n");
            }
        }

    }

    return 0;
}