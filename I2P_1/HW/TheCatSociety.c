#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct _cat{
    char* name;
    int occupation;
    int age;
} Cat;

int n, m;
Cat arr[10001];

void swap(int, int);
int cmp();

int main(){
    while(scanf("%d %d", &n, &m) != EOF){
        for(int i=0; i<n; i++){
            arr[i].name = (char*) malloc(31*sizeof(char));
            char temp[15];
            scanf("%s %s %d", arr[i].name, temp, &arr[i].age);
                switch(temp[0]){
                    case 'e':
                        arr[i].occupation = 1;
                        break;
                    case 'n':
                        arr[i].occupation = 2;
                        break;
                    case 'k':
                        arr[i].occupation = 3;
                        break;
                    case 'w':
                        arr[i].occupation = 4;
                        break;
                    case 'a':
                        arr[i].occupation = 5;
                        break;
                    case 'm':
                        arr[i].occupation = 6;
                        break;
                    case 'd':
                        arr[i].occupation = 7;
                        break;
                    case 'l':
                        arr[i].occupation = 8;
                        break;
                }
        }

        qsort(arr, n, sizeof(Cat), cmp);

        for(int i=0; i<m&&i<n; i++){
            printf("%s\n", arr[i].name);
        }
    }

    return 0;
}

int cmp(const void *lhs, const void *rhs){
    Cat a = *(Cat*)lhs;
    Cat b = *(Cat*)rhs;

    if(b.occupation < a.occupation){
        return 1;
    }
    else if(b.occupation == a.occupation){
        if(b.occupation == 5){
            if(b.age < a.age){
                return 1;
            }
            else if(b.age == a.age){
                return strcmp(a.name, b.name);
            }
        }
        else{
            if(b.age > a.age){
                return 1;
            }
            else if(b.age == a.age){
                return strcmp(a.name, b.name);
            }
        }
    }
    return -1;
}