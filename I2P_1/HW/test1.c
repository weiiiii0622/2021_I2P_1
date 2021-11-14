#include<stdio.h>

int main(){

    char input[999999];

    char banana[6]={'B','A','N','A','N','A'};

    int i=0;int j=0;
    char check[999999];
    int flag=1;
    while(scanf("%s", input) != EOF){
        while(1){
            if(input[i]=='0'||input[i]=='\0'){

                printf("No potassium.\n");
                break;
            }

            else if(input[i]=='/'){

                j++;
                check[i-j*2+1]=' ';
            }

            else{
                check[i-2*j]=input[i];
            }

            printf("Xx %s xX\n", check);

            int k=0;
            flag=1;

            for(k=0;k<i-2*j+1;k++){
                if(check[k]==banana[k]){
                    flag=1;
                }

                else{
                    flag=0;
                    break;
                }
            }
            if(flag){
                if(k==0){}
                else if(k!=6){
                    printf("%d\n", k);
                }

                else{
                    printf("6\nPotassium!\n");
                    break;
                }
            }
            else{
                    printf("-1\n");
            }
            i++;
        }
        i=0;
        j=0;
    }
    return 0;
}