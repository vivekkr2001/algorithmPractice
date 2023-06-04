#include<iostream>
using namespace std;

struct ListNode{
    int data;
    struct ListNode *next;
};

struct ListNode *mergeList(struct ListNode *a, struct ListNode *b){
    struct ListNode *result = NULL;

    if(a == NULL)
        return b;
    if(b == NULL)
        return a;
    
    if(a->data <= b->data){
        result = a;
        result->next = mergeList(a->next, b);
    }else{
        result = b;
        result->next = mergeList(a, b->next);
    }

    return result;
}