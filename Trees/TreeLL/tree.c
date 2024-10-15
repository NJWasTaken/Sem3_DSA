#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "tree.h"

NODE *CreateNode(){
    NODE *p_node = (NODE *)malloc(sizeof(NODE));
    if (p_node==NULL){
        printf("Memory allocation failed.\n");
        exit(0);
    }
    int val;
    printf("Enter value in the node: ");
    scanf("%d",&val);
    p_node->data=val;
    p_node->right=NULL;
    p_node->left=NULL;
    return p_node;
}

NODE *insertL(NODE *root){
    root->left=CreateNode();
    return root->left;
}

NODE *insertR(NODE *root){
    root->right=CreateNode();
    return root->right;
}

void CreateTree(NODE **root){
    NODE *p_root = *root;
    p_root = CreateNode();
    insertL(p_root);
}