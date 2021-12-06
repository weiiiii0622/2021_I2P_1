#include <stdio.h>
#include <string.h>

void bubble_sort(char*, int);
void add(int, int);

char word[20];
char password[20];
int len;

int main(){

    scanf("%s", word);
    len = strlen(word);
    bubble_sort(word, len);

    for(int i=0; i<len-4; i++){
        add(1, i);
    }
    for(int i=len-4; i<len; i++){
        printf("%c", word[i]);
    }
    printf("\n");

    return 0;
}

void add(int digit, int pos){
    password[digit] = word[pos];

    if(digit < 4){
        for(int i=1; i<len-pos; i++){
            add(digit+1, pos+i);
        }
    }
    else if(digit == len){
        for(int i=1; i<=digit; i++){
            printf("%c", password[i]);
        }
        printf(", ");
    }
    else{
        for(int i=1; i<=digit; i++){
            printf("%c", password[i]);
        }
        printf(", ");
        for(int i=1; i<len-pos; i++){
            add(digit+1, pos+i);
        }
    }

}

void bubble_sort(char* arr, int n){
    for(int i=0; i<n; i++){
        for (int j=0; j<i; j++){
            if (arr[j] > arr[i]){
                int temp = arr[j];
                arr[j] = arr[i];
                arr[i] = temp;
            }
        }
    }
}