#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    char C;
    int D;

    scanf("%c %d", &C, &D);

    if (C>=65&&C<=90&&((C-65)-D)<0){
        printf("%c\n",(123-abs((C-65)-D)%26));
    }

    else if (C>=65&&C<=90&&((C-65)-D)>=0){
        printf("%c\n",(97+abs((C-65)-D)%26));
    }

    else if(C>=97&&C<=122&&((C-97)-D)<0){
        printf("%c\n",(90-abs((C-97)-D)%26));
    }

    else if(C>=97&&C<=122&&((C-97)-D)>=0){
        printf("%c\n",(65+abs((C-97)-D)%26));
    }
    
    return 0;
}