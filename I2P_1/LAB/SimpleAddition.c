#include <stdio.h>

int main(){
    while(1){
        char save[999999], ch;
        int num = 0, sum=0;
        int i=0, flag = 0;

        while(scanf("%c", &ch)){
            if(i == 0 && ch == '0'){
                flag = 1;
            }

            if(ch == '\n'){
                if(i > 1){
                    flag = 0;
                }
                for(int a=0; a<i; a++){
                    num = (save[a]-'0') + num*10;       
                }
                sum += num;
                num=0;
                i=0;
                break;
            }

            if(ch>='0' && ch<='9'){
                save[i] = ch;
                i++;
            }
            else{
                for(int a=0; a<i; a++){
                    num = (save[a]-'0') + num*10; 
                }
                sum += num;
                num=0;
                i=0;
            }
        }
        if(flag == 1){
            break;
        }
        printf("%d\n", sum);
        
    }
    return 0;
}