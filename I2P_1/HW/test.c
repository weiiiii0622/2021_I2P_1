#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct substr{
    int occurrence;
    char* substr;
} SubStr;

char str[3005], p[3005];
int str_check[26], p_check[26];
int n, substr_count;
SubStr arr[3005];

void sort();

int main(){

    scanf("%s %d", str, &n);
    scanf("%s", p);
    for(int i=0; i<strlen(p); i++){
        p_check[p[i]-'a'] += 1;
    }
    

    for(int i=0; i<=strlen(str)-n; i++){
        int j=0, flag=1;
        char *temp_str = (char*) malloc((n+5)*sizeof(char));
        memset(str_check, 0, 26*sizeof(int));
        while(j<n){
            temp_str[j] = str[i+j];
            str_check[str[i+j]-'a'] += 1;
            j++;
        }
        temp_str[n] = '\0';

        for(int i=0; i<26; i++){
            if(str_check[i]!=p_check[i]){
                flag = 0;
                break;
            }
        }

        if(flag!=0){
            if(substr_count == 0){
                arr[substr_count].substr = temp_str;
                arr[0].occurrence = 1;
                substr_count += 1;
            }
            else{
                int flag = 0;
                for(int i=0; i<substr_count; i++){
                    if(strcmp(temp_str, arr[i].substr) == 0){
                        arr[i].occurrence += 1;
                        flag = 1;
                        break;
                    }
                }
                if(flag == 0){
                    arr[substr_count].substr = temp_str;
                    arr[substr_count].occurrence = 1;
                    substr_count += 1;
                }
            }  
        }
    }

    sort();

    printf("%d\n", substr_count);
    for(int i=0; i<substr_count; i++){
        printf("%s %d\n", arr[i].substr, arr[i].occurrence);
    }

    return 0;
}

void sort(){
    for(int i=0; i<substr_count; i++){
        for(int j=i; j<substr_count; j++){
            if(arr[j].occurrence > arr[i].occurrence){
                int temp = arr[i].occurrence;
                arr[i].occurrence = arr[j].occurrence;
                arr[j].occurrence = temp;

                char *pt = arr[i].substr;
                arr[i].substr = arr[j].substr;
                arr[j].substr = pt;
            }
            else if(arr[j].occurrence == arr[i].occurrence){
                if(strcmp(arr[j].substr, arr[i].substr) < 0){
                int temp = arr[i].occurrence;
                arr[i].occurrence = arr[j].occurrence;
                arr[j].occurrence = temp;

                char *pt = arr[i].substr;
                arr[i].substr = arr[j].substr;
                arr[j].substr = pt; 
                }
            }
        }
    }
}