#include <stdio.h>
#include <string.h>
char hex[16]={'0','1','2','3','4','5','6','7','8','9','A','B','C','D','E','F'};
char b[100000];
char *demi_to_hex(int x){
    char a[99999];
    int i=0;
    while(x>0){
        a[i++] = hex[x%16];
        x = x/16;
    }
    a[i] = '\0';
    for(int j=strlen(a)-1, k=0; j>=-1; j--, k++){
        if(j!=-1){
            b[k] = a[j];
        }
        else{
            b[k] = '\0';
        }
    }
    return b;
}


int main(){
    printf("%s %d\n", demi_to_hex(30), strlen(demi_to_hex(30)));
    printf("%s %d\n", demi_to_hex(300), strlen(demi_to_hex(300)));

    return 0;
}