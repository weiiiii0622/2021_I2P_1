#include <stdio.h>

int search_char(char, char[]);

int main(){
    char mapping[10];
    scanf("%s", mapping);

    char word[5];
    scanf("%s", word);


    for(int i=0; i<4; i++){
        if(word[i]>=97 && word[i]<=122){
            printf("%d", search_char(word[i], mapping) + 1);        
        }
        else{
            printf("%c", mapping[(word[i]-'0')-1]);
        }
    }


    return 0;
}

int search_char(char x, char mapping[]){
    for(int i=0; i<9; i++){
        if(mapping[i] == x){  
            return i;
        }
    }
}