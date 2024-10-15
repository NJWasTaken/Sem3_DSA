#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "narrt.h"

NODE *CreateNode(){
    NODE *p_node = (NODE *)malloc(sizeof(NODE));
    if (p_node==NULL){
        printf("Memory allocation failed.\n");
        exit(0);
    }
    int val;
    printf("Enter value in the node: ");
    scanf("%d",&val);
    p_node->val=val;
    p_node->kids=NULL;
    p_node->siblings=NULL;
    return p_node;
}

void CreateTree(NODE *root){
    NODE *root=NULL;
    NODE *p_node;
    while(1){
        char option;
        option=toupper(option);
        printf("Enter option: Add Sibling - S | Add Child - C | Move to next sibling - M | Move to child - N | Move to root - R | Quit - Q: ");
        scanf(" %c",&option);
        if (option=='Q')break;
        switch (option)
        {
        case 'S':
            NODE *sib = CreateNode();
            if (root==NULL){
                root=sib;
                p_node=root;
                printf("Created root of value %d\n", p_node->val);
            }
            p_node->siblings=sib;
            printf("Created sibling of %d with value: %d\n", p_node->val,sib->val);
            break;
        
        case 'C':
            NODE *child = CreateNode();
            if (root==NULL){
                printf("Create a root first!\n");
            }
            else{
                p_node->kids=child;
                printf("Created sibling of %d with value: %d\n", p_node->val,sib->val);
            }
            break;
        
        case 'M':
            if (p_node->siblings!=NULL)p_node = p_node->siblings;
            else{
                printf("No sibling.\n");
            }
            break;
        
        case 'N':
            if (p_node->kids!=NULL)p_node = p_node->kids;
            else{
                printf("No child.\n");
            }
            break;
        
        case 'R':
            p_node=root;
            if (p_node!=NULL)printf("Moved back to root of value %d\n",p_node->val);
            break;

        default:
            break;
        }
    }
}

void preorder(NODE* root){
    if(root!=NULL){
        printf("Data is:%d\n",root->val);
        preorder(root->kids);
        preorder(root->siblings);
    }
}

void inorder(NODE* root){
    if(root!=NULL){
        inorder(root->kids);
        printf("Data is: %d\n",root->val);
        inorder(root->siblings);
    }
}

void postorder(NODE* root){
    if(root!=NULL){
        posorder(root->kids);
        postorder(root->siblings);
        printf("Data is: %d\n",root->val);
    }
}

