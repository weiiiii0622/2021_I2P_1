#include <stdio.h>
#include <string.h>

char code[10001];
int convert[123];
char hex[16]={'0','1','2','3','4','5','6','7','8','9','a','b','c','d','e','f'};

void decode(char*);
void demi_to_hex(int, char*);

int main(){

    convert['0']= 0;convert['1']= 1;convert['2']= 2;convert['3']= 3;convert['4']= 4;convert['5']= 5;
    convert['6']= 6;convert['7']= 7;convert['8']= 8;convert['9']= 9;
    convert['a']=10; convert['b']=11; convert['c']=12; convert['d']=13; convert['e']=14; convert['f']=15;
    convert['A']=10; convert['B']=11; convert['C']=12; convert['D']=13; convert['E']=14; convert['F']=15;
    scanf("%s", code);

    decode(code);
    printf("\n");

    return 0;
}

void decode(char* str){
    int len = strlen(str);
    char temp_str[len];
    for(int i=0; i<len; i++){
        temp_str[i] = str[i];
    }

    if(len == 1){
        printf("%c", temp_str[0]);
        return;
    }
    else{
        int sum=0;
        for(int p=0; p<len; p+=2){
            sum += convert[temp_str[p]];
        }

        char b[10001];
        demi_to_hex(sum, b);
        decode(b);

        sum=0;
        for(int p=1; p<len; p+=2){
            sum += convert[temp_str[p]];
        }

        char d[10001];
        demi_to_hex(sum, d);
        decode(d);
    }
}


void demi_to_hex(int x, char* arr){
    char a[99999];
    int i=0;
    while(x>0){
        a[i++] = hex[x%16];
        x = x/16;
    }
    a[i] = '\0';
    for(int j=strlen(a)-1, k=0; j>=-1; j--, k++){
        if(j!=-1){
            arr[k] = a[j];
        }
        else{
            arr[k] = '\0';
        }
    }
}