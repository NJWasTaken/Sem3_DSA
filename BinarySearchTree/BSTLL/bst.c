#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <bst.h>


NODE *new_node(int value){
    NODE *p_node;
    p_node = (NODE*)malloc(sizeof(NODE));
    if (p_node==NULL){
        printf("Memory unavailable to allocate.\n");
        exit(0);
    }
    p_node->left=NULL;
    p_node->right=NULL;
    p_node->val=value;

    return p_node;
}

NODE* insert(NODE* root, int value){
    if (root->val==value){
        printf("Duplicates not allowed.\n");
        exit(0);
    }
    else{
        if (root==NULL) return new_node(value);
        else if (value>root->val) root->right = insert(root->right,value);
        else root->left = insert(root->left,value);
    }
    return root;
}

NODE* search(NODE* root, int data){
    NODE *res=NULL;
    if (data == root->val){
        res = root;
    }
    else if(data<root->val){
        res = search(root->left,data);
    }
    else if(data>root->val){
        res = search(root->right,data);
    }
    return res;
}

NODE* find_minimum(NODE* root){
    NODE *p_node = root;
    while (p_node->left->left!=NULL)p_node=p_node->left;
    return p_node;
}

NODE* delete(NODE* root, int value){
    NODE *temp, *p;
    if (root==NULL)return root;
    if (value > root->val) root->right = delete(root->right,value);
    else if (value < root->val) root->left = delete(root->left,value);
    else{
        if (root->left==NULL){
            temp = root->right;
            free(root);
            return temp;
        }
        else if (root->right==NULL){
            temp = root->left;
            free(root);
            return temp;
        }
        else{
            p = root->right;
            while (p->left!=NULL)p=p->left;
            root->val = p->val;
            root->right = delnode(root->right, p->val);
        }
    }
    return root;
}

void inorder(NODE *root){
    if (root==NULL)return;
    inorder(root->left);
    printf("%d ",root->val);
    inorder(root->right);
}