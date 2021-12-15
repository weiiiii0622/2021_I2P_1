#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define min(a,b) (a>=b?b:a)


char str[1001];
int count[1001][1001];

int check(int, int);

int main(){

    int len, delete;
    scanf("%d %d", &len, &delete);
    scanf("%s", str);
    memset(count, -1, 1001*1001*sizeof(count[0][0]));

    check(0, len-1);
    
    if(count[0][len-1] <= delete){
        printf("Yes\n");
    }
    else{
        printf("No\n");
    }
    return 0;
}

int check(int left, int right){
    if(count[left][right] != -1){
        return count[left][right];
    }
    else{
        if(left >= right){
            return count[left][right] = 0;
        }
        else if(str[left] == str[right]){
            return count[left][right] = check(left+1, right-1);
        }
        else if(str[left] != str[right]){
            return count[left][right] = 1 + min(check(left+1, right), check(left, right-1));
        }
    }
}