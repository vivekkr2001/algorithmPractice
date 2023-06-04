#include <iostream>

using namespace std;

struct ListNode {
    int data;
    struct ListNode *next;
};

int listLength(struct ListNode* head){
    struct ListNode *temp = head;
    
    int count = 0;

    while(temp != NULL){
        count++;

        temp = temp->next;
    }

    return count;
}

void insertElement(struct ListNode **head, int data, int position){
    int k=1;

    struct ListNode *p, *q, *newNode;
    newNode = (ListNode *) malloc(sizeof(struct ListNode));

    if(!newNode){
        printf("Memory Error!");
        return;
    }

    newNode->data = data;

    p = *head;

    if(position == 1){
        newNode->next = p;
        *head = newNode;
    }
    else{
        while(p != NULL && (k < position)){
            k++;
            q = p;
            p = p->next;
        }

        q->next = newNode;
        newNode->next = p;
    }
}

void deleteElement(ListNode *head, int position){
    if(head == NULL){
        printf("Memory error");
    }

    struct ListNode *p, *q;
    p = head;

    if(position == 1){
        head = head -> next;
        free(p);
        return;
    }else{
        int k = 1;
        while(p != NULL && (k < position)){
            k++;
            q = p;
            p = p->next;
        }
        if(p == NULL){
            printf("Position doesn't exist.");
        }else{
            q->next = p->next;
            free(p);
        }
    }
}

void deleteLinkedList(struct ListNode *head){
    struct ListNode *iterator, *auxilaryNode;

    iterator = head;
    while(iterator != NULL){
        auxilaryNode = iterator->next;
        free(iterator);
        iterator = auxilaryNode;
    }

    head = NULL;
}


