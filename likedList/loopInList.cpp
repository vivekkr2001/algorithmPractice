#include<iostream>

struct ListNode{
    int data;
    struct ListNode *next;
};

int isLoop(struct ListNode *head){
    struct ListNode *slowPtr = head, *fastPtr = head;

    while(slowPtr && fastPtr){
        fastPtr = fastPtr->next;
        if(fastPtr == slowPtr){
            return 1;
        }

        if(fastPtr == NULL)
            return 0;
        
        fastPtr = fastPtr->next;

        if(fastPtr == slowPtr){
            return 1;
        }

        slowPtr = slowPtr->next;
    }
}