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

void inOrder(struct BinaryTreeNode *root){
    if(root){
        inOrder(root->left);
        printf("%d", root->data);
        inOrder(root->right);
    }
}

void postOrder(struct BinaryTreeNode *root){
    if(root){
        postOrder(root->left);
        postOrder(root->right);
        printf("%d", root->data);
    }
}