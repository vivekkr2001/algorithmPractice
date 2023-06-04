#include<iostream>
using namespace std;

struct DLLNode{
    int data;
    struct DLLNode *next;
    struct DLLNode *prev;
};

void DLLinsert(struct DLLNode *head, int data, int position){
    struct DLLNode *temp, *newNode;
    newNode = (struct DLLNode *) malloc(sizeof(struct DLLNode));

    if(!newNode){
        printf("Memory Error!");
        return;
    }

    newNode->data = data;
    if(position == 1){
        newNode->next = head;
        newNode->prev = NULL;
        
        if(head){
            head->prev = newNode;
        }

        head = newNode;
        return;
    }

    temp = head;
    int k = 1;

    while((k < position) && temp->next != NULL){
        temp = temp->next;
        k++;
    }

    if(k != position){
        printf("Desired position doesn't exist!");
        return;
    }

    newNode->next = temp->next;
    newNode->prev = temp;

    if(temp->next){
        temp->next->prev = newNode;
    }

    temp->next = newNode;

    return;
}

void DLLDelete(struct DLLNode *head, int position){
    struct DLLNode *temp, *temp2;
    temp = head;
    int k = 1;

    if(head == NULL){
        printf("EmptyList");
        return;
    }

    if(position == 1){
        head = head->next;
        
        if(head != NULL){
            head->prev = NULL;
        }

        free(temp);
        return;
    }

    while((k <  position ) && temp->next != NULL){
        temp = temp->next;
        k++;
    }

    if(k != position){
        printf("Desired position doesn't exist.");
        return;
    }

    temp2 = temp->prev;
    if(temp->next){
        temp2->next = temp->next;
    }

    temp->next->prev = temp2;
    free(temp);

    return;
}