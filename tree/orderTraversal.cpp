#include<iostream>
using namespace std;

struct BinaryTreeNode{
    int data;
    struct BinaryTreeNode *left;
    struct BinaryTreeNode *right;
};

void preOrder(struct BinaryTreeNode *root){
    if(root){
        printf("%d", root->data);
        preOrder(root->left);
        preOrder(root->right);
    }
}

struct Stack *createStack();
void Push(struct Stack*, struct BinaryTreeNode*);
int IsEmptyStack(struct Stack*);
struct BinaryTreeNode* Pop(struct Stack*);
void DeleteStack(struct Stack*);
struct BinaryTreeNode* Top(struct Stack*);

void preOrderNonRecursive(struct BinaryTreeNode *root){
    struct Stack *S = createStack();
    while(1){
        while(root){
            printf("%d", root->data);
            Push(S, root);
            root = root->left;
        }

        if(IsEmptyStack(S)){
            break;
        }
        root = Pop(S);
        root = root->right;
    }
    DeleteStack(S);
}

void inOrder(struct BinaryTreeNode *root){
    if(root){
        inOrder(root->left);
        printf("%d", root->data);
        inOrder(root->right);
    }
}

void inOrderNonRecursive(struct BinaryTreeNode *root){
    struct Stack *S = createStack();

    while(1){
        while(root){
            Push(S,root);
            root = root->left;
        }
        if(IsEmptyStack(S)){
            break;
        }
        root = Pop(S);
        printf("%d", root->data);
        root = root->right;
    }
    DeleteStack(S);
}

void postOrder(struct BinaryTreeNode *root){
    if(root){
        postOrder(root->left);
        postOrder(root->right);
        printf("%d", root->data);
    }
}

void postOrderNonRecursive(struct BinaryTreeNode *root){
    struct Stack *S = createStack();

    while(1){
        if(root != NULL){
            Push(S, root);
            root = root->left;
        }
        else{
            if(IsEmptyStack(S)){
                return;
            }
            else{
                if(Top(S)->right == NULL){
                    root = Pop(S);
                    printf("%d", root->data);
                    if(root == Top(S)->right){
                        printf("%d", Top(S)->data);
                        Pop(S);
                    }
                }
            }

            if(!IsEmptyStack(S)){
                root = Top(S)->right;
            }
            else{
                root = NULL;
            }
        }
        DeleteStack(S);

    }
}
