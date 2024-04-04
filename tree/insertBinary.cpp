#include<iostream>
using namespace std;
/*
Code to insert tree node in binary tree structure.
*/
struct BinaryTreeNode{
    int data;
    struct BinaryTreeNode *left;
    struct BinaryTreeNode *right;
};

struct BinaryTreeNode *insert(struct BinaryTreeNode *root, int data){
    if(root == NULL){
        root = (struct BinaryTreeNode *) malloc(sizeof(struct BinaryTreeNode));
        if(root == NULL){
            printf("Memory Error");
            return;
        }else{
            root->data = data;
            root->left = root->right = NULL;
        }
    }else{
        if(data < root->data){
            root->left = insert(root->left, data);
        }else{
            root->right = insert(root->right, data);
        }
    }
    return root;
}

// struct BinaryTreeNode *delet(struct BinaryTreeNode *root, int data){
//     struct BinaryTreeNode *temp;

//     if(root == NULL){
//         printf("Elements are not in tree.");
//     }else if(data < root->data){
//         root->left = delet(root->left, data);
//     }else if(data > root->data){
//         root->right = delet(root->right, data);
//     }else{
//         if(root->left && root->right){
//             temp = FindMax(root->left);
//             root->data = temp->data;
//             root->left = delet(root->left, root->data);
//         }else{
//             temp = root;
//             if(root->left == NULL){
//                 root = root->right;
//             }
//             if(root->right == NULL){
//                 root = root->left;
//             }
//             free(temp);
//         }
//     }
// }