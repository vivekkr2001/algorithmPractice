#include<iostream>
using namespace std;

struct ArrayStack{
    int top;
    int capacity;
    int *array;
};

struct ArrayStack *createStack(){
    struct ArrayStack *S =(struct ArrayStack *) malloc(sizeof(struct ArrayStack));

    if(!S){
        return NULL;
    }

    S->capacity = 1;
    S->top = -1;
    S->array = (int *) malloc(S->capacity * sizeof(int));
    if(!S->array)
        return NULL;
    
    return S;

};

int isEmptyStack(struct ArrayStack *S){
    return (S->top == -1); //if condition is true then 1 else 0.
}

int isFullStack(struct ArrayStack *S){
    return (S->top == S->capacity -1);
}

void Push(struct ArrayStack *S, int data){
    if(isFullStack){
        printf("Stack is full");
        return;
    }else{
        S->array[++S->top] = data;
    }
}

int Pop(struct ArrayStack *S){
    if(isEmptyStack){
        printf("Empty Stack");
        return 0;
    }else{
        return (S->array[S->top--]);
    }
}

void deleteStack(struct ArrayStack *S){
    if(S){
        if(S->array){
            free(S->array);
        }
        free(S);
    }
}