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

        for(int i=0; i<n; i++){
            for(int j=i+1; j<n; j++){

                if(arr[j].occupation < arr[i].occupation){
                    swap(i, j);
                }
                else if(arr[j].occupation == arr[i].occupation){
                    if(arr[j].occupation == 5){
                        if(arr[j].age < arr[i].age){
                            swap(i, j);
                        }
                        else if(arr[j].age == arr[i].age){
                            if(strcmp(arr[j].name, arr[i].name) < 0){
                                swap(i, j);
                            }
                        }
                    }
                    else{
                        if(arr[j].age > arr[i].age){
                            swap(i, j);
                        }
                        else if(arr[j].age == arr[i].age){
                            if(strcmp(arr[j].name, arr[i].name) < 0){
                                swap(i, j);
                            }
                        }
                    }
                }
            }
        }
        for(int i=0; i<m&&i<n; i++){
            printf("%s\n", arr[i].name);
        }
    }

    return 0;
}

void swap(int i, int j){
    char *temp_name = arr[i].name;
    int temp_occu = arr[i].occupation, temp_age = arr[i].age;

    arr[i].name = arr[j].name;
    arr[i].occupation = arr[j].occupation;
    arr[i].age = arr[j].age;

    arr[j].name = temp_name;
    arr[j].occupation = temp_occu;
    arr[j].age = temp_age;
}