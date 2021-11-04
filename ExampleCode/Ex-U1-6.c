//To do or not to do - using if-else
#include <stdio.h>

int main(void)
{
    int x=0;

    scanf("%d", &x);

    //check if x is Odd or Even
    if(x%2 > 0)
    {
        printf("Odd!\n");
    }
    else
    {
        printf("Even!\n");
    }

    return 0;
}
