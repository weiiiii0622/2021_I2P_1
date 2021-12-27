#include <stdio.h>
#include <string.h>

void sort(char (*str)[7], int x){
    for(int i=0; i<6; i++){
        for(int j=i; j<6; j++){
            if(str[x][j] < str[x][i]){
                char temp = str[x][i];
                str[x][i] = str[x][j];
                str[x][j] = temp;
            }
        }
    }
}

int main(){
    int n;
    scanf("%d", &n);
    char str[n][7];
    
    for(int i=0; i<n; i++){
        scanf("%s", &str[i]);
        sort(str, i);
    }

    for(int i=0; i<n; i++){
        for(int j=i; j<n; j++){
            if(strcmp(str[j], str[i]) < 0){
                char temp[7];
                strcpy(temp, str[i]);
                strcpy(str[i], str[j]);
                strcpy(str[j], temp);
            }
        }
    }

    for(int i=0; i<n; i++){
        if(i != (n-1)){
            printf("%s ", str[i]);
        }
        else{
            printf("%s\n", str[i]);
        }
        
    }
    
    return 0;
}