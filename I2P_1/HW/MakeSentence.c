#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct _string{
    char *str;
    struct _string *next;
    struct _string *prev;
} String;

String *arr[101], *tail[101];
int n ,m;
int len[101];
char command[8];

void add();
void delete();
void swap();
void longest();
void all();
void free_str(int);

int main(){
    scanf("%d %d", &n, &m);
    for(int i=1; i<=100; i++){
        arr[i] = NULL;
        tail[i] = NULL;
    }

    while(m--){
        // for(int i=1; i<=n; i++){
        //     printf("arr[i]:%p len[i]=%d / ", arr[i], len[i]);
        // }
        // printf("\n");
        scanf("%s", command);

        if(command[1] == 'd'){
            add();
        }
        else if(command[1] == 'e'){
            delete();
        }
        else if(command[1] == 'w'){
            swap();
        }
        else if(command[1] == 'o'){
            longest();
        }
        else if(command[1] == 'l'){
            all();
        }
    }
    for(int i=1; i<=n; i++){
        free_str(i);
    }
    
    return 0;
}

void add(){
    int id;
    scanf("%d", &id);

    if(tail[id] == NULL){
        arr[id] = (String*) malloc(sizeof(String));
        arr[id]->str = (char*) malloc(101*sizeof(char));
        scanf("%s", arr[id]->str);
        arr[id]->prev = NULL;
        arr[id]->next = NULL;
        len[id] += strlen(arr[id]->str);

        tail[id] = arr[id];  
    }
    else{
        String *new_str = (String*) malloc(sizeof(String));
        new_str->str = (char*) malloc(101*sizeof(char));
        new_str->next = NULL;
        new_str->prev = tail[id];
        scanf("%s", new_str->str);
        len[id] += strlen(new_str->str);

        tail[id]->next = new_str;
        tail[id] = tail[id]->next;
    }
    return;
}

void delete(){
    int id, k;
    scanf("%d %d", &id, &k);

    if(tail[id] != NULL){
        while(tail[id] != NULL && k > 0){
            int str_len = strlen(tail[id]->str);
            if(k < str_len){
                tail[id]->str[str_len-k] = '\0';
				len[id] -= k;
                k=0;   
            }
            else{
                k -= str_len;
                String *temp = tail[id]->prev;
                if(temp != NULL){
                    temp->next = NULL;
                }
                free(tail[id]->str);
                free(tail[id]);
                tail[id] = temp;
                len[id] -= str_len;
            }
        }
    }
    if(tail[id] == NULL){
        arr[id] = NULL;
    }
    return;
}
void swap(){
    int a, b;
    scanf("%d %d", &a, &b);

    String *arr_temp = arr[a];
    arr[a] = arr[b];
    arr[b] = arr_temp;
    String *tail_temp = tail[a];
    tail[a] = tail[b];
    tail[b] = tail_temp;
    int len_temp = len[a];
    len[a] = len[b];
    len[b] = len_temp;

    return;
}

void longest(){
    int max_id = 1;
    for(int i=2; i<=n; i++){
        if(len[i] > len[max_id]){
            max_id = i;
        }
    }
    String *temp = arr[max_id];
    if(temp == NULL){
        printf("0 \n");
    }
    else{
        printf("%d ", len[max_id]);
        while(temp->next != NULL){
            printf("%s", temp->str);
            temp = temp->next;
        }
        printf("%s\n", temp->str);        
    }
    return;
}

void all(){
    for(int i=1; i<=n; i++){
        String* temp = arr[i];
        if(tail[i] == NULL){
            printf("\n");
        }
        else{
            while(temp->next != NULL){
                printf("%s", temp->str);
                temp = temp->next;
            }
            printf("%s\n", temp->str);
        }
    }
    return;
}

void free_str(int i){
    String *cur = arr[i], *next;
    while(cur != NULL){
        next = cur->next;
        free(cur->str);
        free(cur);
        cur = next;
    }
}