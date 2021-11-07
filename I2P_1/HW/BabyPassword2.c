#include <stdio.h>

int main(){
    char c, operator, answer;
    int d, flag=0;
    scanf("%c %c%d", &c, &operator, &d);
    
    if(c>=65 && c<=90){
        flag=1;
    }

    if(operator == '-'){
        if(c+d>90 && flag == 1){
            answer = c+d-26;
        }
        else if(c+d>122 && flag == 0){
            answer = c+d-26;
        }
        else{
            answer = c+d;
        }
    }
    else{
        if(c-d<65 && flag == 1){
            answer = c-d+26;
        }
        else if(c-d<97 && flag == 0){
            answer = c-d+26;
        }
        else{
            answer = c-d;
        }
    }

    if(flag == 1){
        printf("%c\n", answer+32);
    }
    else{
        printf("%c\n", answer-32);
    }

    return 0;
}