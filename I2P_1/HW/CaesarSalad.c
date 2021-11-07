#include <stdio.h>

int main(void) {
    char a[3];
    for (int i=0;i<3;i++){
        scanf("%c",&a[i]);
    }
    int num;
    scanf("%d",&num);
    
    for (int i=0;i<3;i++){
        a[i] += (num%26);

        if(a[i]>90){
            a[i]-=26;
        }
        else if(a[i]<65){
            a[i]+=26;
        }

        printf("%c",a[i]);
    }
    printf("\n");
    
}