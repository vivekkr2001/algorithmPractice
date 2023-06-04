#include<iostream>
using namespace std;

struct ListNode{
    int data;
    struct ListNode *next;
};

struct ListNode* intersectingNode(struct ListNode *list1, struct ListNode *list2){
    struct ListNode *temp1=list1, *temp2=list2;

    while(temp1 != temp2){
        if(temp1 == NULL){
            temp1 = list2;
        }

        if(temp2 == NULL){
            temp2 = list1;
        }

        temp1 = temp1->next;
        temp2 = temp2->next;
    }
    return temp1;
}