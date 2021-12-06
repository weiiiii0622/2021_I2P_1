#include<stdio.h>

int main()
{
    int arr[][4][4] = {
                        
                        {{0,2,3,4},{5,6,7,8},{9,10,11,12},{13,14,15,16}},
                        {{17,18,19,20},{21,22,23,24},{25,26,27,28},{29,30,31,32}}
                        
                    };

    int i, j, k;
    int (*p)[4][4];

    p = arr;

    for(i = 0; i < 2; i++)
    {
        //printf("Address of %d th array %u \n",i , p + i);
        for(j = 0; j < 4; j++)
        {
            //printf("Address of %d th array %u \n",i , p + i);
            for(k=0; k<4; k++){
                printf("arr[%d][%d][%d]=%d\n", i, j, k, *(*( *(p + i) + j)+k) );
            }
            printf("\n");
        }
        printf("\n\n");
    }

    // signal to operating system program ran fine
    return 0;
}