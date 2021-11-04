#include <stdio.h>

int main(){
    int length, width, area, answer;
    scanf("%d %d", &length, &width);

    area = length*width;

    if(area%2 == 0){
        printf("%d", area/2);
    }
    else{
        printf("%d", (area+1)/2);
    }
    
    return 0;
}