#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME 100
typedef struct _Item {
    char* name;
    int price;
    int discount;
    int quality;
} Item;

typedef int (*func_ptr)(const void*, const void*);

Item* CreateList(int N);
void AddItem( Item* L, int idx, char* name, int price, int discount, int quality );
void DeleteList(Item* L, int N);

int price_cmp( const void* lhs, const void* rhs );
int discount_cmp( const void* lhs, const void* rhs );
int quality_cmp( const void* lhs, const void* rhs );

int N, X;
int O[3];
func_ptr cmp[3] = { price_cmp, discount_cmp, quality_cmp };



int qsort_cmp( const void* lhs, const void* rhs){
    for(int i=0; i<3; i++){
        int res = cmp[ O[i]-1 ](lhs, rhs);
        if( res != 0 ) // If not same
            return res;
    }
    // This case will not appear in Test cases;
    int str_res = strcmp( ((Item*)lhs)->name, ((Item*)rhs)->name);
    if( str_res < 0 ) return -1;
    if( str_res > 0 ) return 1;
    return 0;
}


int main(){
    int T;
    scanf("%d", &T);
    for(int cnt=1; cnt<=T; cnt++){
        scanf("%d %d %1d%1d%1d", &N, &X, &O[0], &O[1], &O[2]);

        Item* L = CreateList(N);
        char name[MAX_NAME+1];
        int P, D, Q;
        for(int i=0; i<N; i++){
            scanf("%s %d %d %d", name, &P, &D, &Q);

            AddItem(L, i, name, P, D, Q);
        }
        
        qsort( L, N, sizeof( Item ), qsort_cmp);

        printf("case %d:\n", cnt);
        for(int i=0; i<N; i++){
            int sp = L[i].price - L[i].discount;
            if( sp < X ){
                printf("%s\n", L[i].name);
                X -= sp;
            }
        }
        DeleteList(L, N);
    }
    return 0;
}

Item* CreateList(int N){
    Item* arr = (Item*) malloc(N*sizeof(Item));
    return arr;
}

void AddItem( Item* L, int idx, char* name, int price, int discount, int quality ){
    char* n = (char*) malloc((strlen(name)+1)*sizeof(char));
    strcpy(n, name);

    (L+idx)->name = n;
    (L+idx)->price = price;
    (L+idx)->discount = discount;
    (L+idx)->quality = quality;
}

void DeleteList(Item* L, int N){
    for(int i=0; i<N; i++){
        free((L+i)->name);
        
    }
    free(L);
}

int price_cmp( const void* lhs, const void* rhs ){
    Item a = *(Item *)lhs;
    Item b = *(Item *)rhs;
    int a_sell = a.price - a.discount;
    int b_sell = b.price - b.discount;
    if(a_sell == b_sell){
        return 0;
    }
    else{
        return a_sell>b_sell ? 1:-1;
    }
}
int discount_cmp( const void* lhs, const void* rhs ){
    Item a = *(Item *)lhs;
    Item b = *(Item *)rhs;
    if(a.discount == b.discount){
        return 0;
    }
    else{
        return a.discount<b.discount ? 1:-1;
    }
}
int quality_cmp( const void* lhs, const void* rhs ){
    Item a = *(Item *)lhs;
    Item b = *(Item *)rhs;
    if(a.quality == b.quality){
        return 0;
    }
    else{
        return a.quality<b.quality ? 1:-1;
    }
}