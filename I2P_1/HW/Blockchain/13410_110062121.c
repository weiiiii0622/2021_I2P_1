#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "function.h"

int hash(block* b){
    int money = b->t[0].val+b->t[1].val;
    int link = (b->link);
    return (((money*money)^link)+link*link)%1000+1;
}

block* create_block(int currentTail, transaction t[2]){
    block* new_block = (block*) malloc(sizeof(block));
    new_block->t[0] = t[0];
    new_block->t[1] = t[1];
    new_block->link = currentTail;
    return new_block;
}

int query(block_chain *bc, char name[10], int initial_saving){
    int hash_value = bc->tail;
    while (hash_value != 0){
        for(int i=0; i<2; i++){
            transaction cur = bc->block_data[hash_value]->t[i];
            if(strcmp(cur.from, name) == 0){
                initial_saving -= cur.val;
            }
            else if(strcmp(cur.to, name) == 0){
                initial_saving += cur.val;
            }
        }
        hash_value = bc->block_data[hash_value]->link;
    }
    return initial_saving;
}