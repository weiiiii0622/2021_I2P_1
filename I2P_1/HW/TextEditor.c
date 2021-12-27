#include <stdio.h>
#include <string.h>

#define MAX_SIZE 500

char content[MAX_SIZE];
char input[MAX_SIZE];

char *cursor_con, *cursor_inp, *len;
int flag = 0;

void solve();

int main(){

    fgets(input, MAX_SIZE, stdin);
    solve();
    printf("%s", content);
    return 0;
}

void solve(){

    cursor_con = content;
    cursor_inp = input;
    len = content;

    while(*(cursor_inp) != '\0'){

        if(*(cursor_inp) == '/'){
            cursor_inp += 1;
            if(*(cursor_inp) == 'b'){
                cursor_inp += 9;

                if(len-content == 0){
                    flag = 0;
                }
                
                if(flag != 0){
                    int i=0;
                    while(cursor_con+i < len){
                        *(cursor_con+i) = *(cursor_con+i+1);
                        i++;
                    }

                    cursor_con -= 1;
                    len -= 1;
                }
            }
            else if(*(cursor_inp) == 'n'){
                cursor_inp += 7;
                if(flag == 0){
                    *(cursor_con) = '\n';
                    flag=1;
                }
                else{
                    *(++cursor_con) = '\n';
                    len++;
                }
                
            }
            else if(*(cursor_inp) == 'l'){
                cursor_inp += 4;
                if((cursor_con-content) != -1){
                    cursor_con -= 1;
                }
            }
            else if(*(cursor_inp) == 'r'){
                cursor_inp += 5;
                if(cursor_con != len){
                    cursor_con += 1;
                }
            }
        }
        else{
            int i=0;
            if(len != cursor_con){
                while(len-i > cursor_con){
                    *(len+1-i) = *(len-i);
                    i++;
                }
            }

            if(flag == 0){
                flag = 1;
                *(cursor_con) = *(cursor_inp);
            }
            else{
                *(++cursor_con) = *(cursor_inp);
                len += 1;
            }
            cursor_inp += 1;
        }
    }
}