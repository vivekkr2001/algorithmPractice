#include<iostream>

using namespace std;

struct listNode{
    int data;
    struct listNode *next;
};

struct queue{
    struct listNode *front;
    struct listNode *rear;
};

struct queue *createQueque(){
    struct queue *Q;
    Q = (struct queue*) malloc(sizeof(struct queue));
    struct listNode *temp;
    if(!Q){
        return NULL;
    }

    temp = (struct listNode*) malloc(sizeof(struct listNode));
    Q->front = Q->rear = NULL;

    if(!temp){
        free(Q);
        return NULL;
    }
    Q->rear = temp;
    return Q;
}

int isEmptyQueque(struct queue *Q){
    return (Q->front == NULL);
}

void EnQueue(struct queue *Q, int data){
    struct listNode *newNode;
    newNode = (struct listNode*) malloc(sizeof(struct listNode));

    if(!newNode){
        return;
    }

    newNode->data = data;
    newNode->next = NULL;

    Q->rear->next = newNode;

    Q->rear = newNode;

    if(Q->front == NULL){
        Q->front = Q->rear;
    }

}

int DeQueue(struct queue *Q){
    int data=0;
    struct listNode *temp;
    if(isEmptyQueque(Q)){
        return 0;
    }
    else{
        temp = Q->front;
        data = temp->data;
        Q->front = Q->front->next;
        free(temp);
    }
    return data;
}

void deleteQueue(struct queue *Q) {
    if (Q == NULL) {
        return;
    }

    struct listNode *current = Q->front;
    struct listNode *nextNode;

    while (current != NULL) {
        nextNode = current->next;
        free(current);
        current = nextNode;
    }

    free(Q);
}

void printQueue(struct queue *Q){
    struct listNode *temp = Q->front;
    while(temp != Q->rear){
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("%d ", Q->rear->data);

}

int main(){

    struct queue *Q = createQueque();
    EnQueue(Q, 1);
    EnQueue(Q, 5);
    EnQueue(Q, 2);
    EnQueue(Q, 6);
    EnQueue(Q, 8);

    printQueue(Q);
    cout << "data: " << DeQueue(Q) << endl;
    return 0;

}