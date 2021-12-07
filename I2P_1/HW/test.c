#include <stdio.h>

int main(){

    int arr[5] = {1,2,4,8,16};

    int* const pt = &arr[1];
    
    *pt = 10;
    pt = &arr[2];
    printf("%d\n", *pt);


    return 0;
}