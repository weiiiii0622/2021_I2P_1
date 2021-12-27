#include <stdio.h>
#include <string.h>

int arr[5] = {1,2,3,4,5};

int main(){
    int*pt = arr+2;
    printf("%td\n", (int*)pt-(int*)arr);

    return 0;
}
