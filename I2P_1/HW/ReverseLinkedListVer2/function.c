#include<stdio.h>
#include<string.h>
#include"function.h"

void Push(Node** ptr_head, int x){
    Node* new_head = (Node*) malloc(sizeof(Node));
    new_head->data = x;
    new_head->next = (*ptr_head);
    *ptr_head = new_head;
}

void Pop(Node** ptr_head){
    if(*ptr_head == NULL){
        return;
    }
    Node* new_head = *ptr_head;
    *ptr_head = (*ptr_head)->next;
    free(new_head);
}

void Reverse_List(Node** ptr_head){
    if(*ptr_head == NULL){
        return;
    }
    Node *before = NULL, *next, *current = *ptr_head;
    while (current->next != NULL){
        next = current->next;
        current->next = before;
        before = current;
        current = next;
    }
    current->next = before;
    *ptr_head = current;
}