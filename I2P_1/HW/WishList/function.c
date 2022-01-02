#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "function.h"

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