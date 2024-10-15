#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

typedef struct Node{
    int key;
    char value[101];
    struct Node *left, *right;
} Node;

// Function to create a new node
Node* newNode(int key, char* value){
    Node* node=(Node*)malloc(sizeof(Node));
    if(node==NULL){
        printf("Memory allocation failed\n");
        exit(1);
    }
    node->key=key;
    strcpy(node->value, value);
    node->left=node->right=NULL;
    return node;
}

// Search for a key in the BST
Node* search(Node* root, int key){
    if(root==NULL||root->key==key)
        return root;
    if(key<root->key)
        return search(root->left, key);

    return search(root->right, key);
}

// Insert a key-value pair into the BST
Node* insert(Node* root, int key, char* value){
    if(root==NULL) 
        return newNode(key, value);
    if(key<root->key)
        root->left=insert(root->left, key, value);
    else if(key>root->key)
        root->right=insert(root->right, key, value);
    else
        strcpy(root->value, value); //updating

    return root;
}

// Find the inorder successor
Node* minValueNode(Node* node){
    Node* curr=node;
    while(curr && curr->left!=NULL)
        curr=curr->left;
    return curr;
}

// Delete a key from the BST
Node* deleteNode(Node* root, int key){
    if(root==NULL)
        return root;

    if(key<root->key)
        root->left=deleteNode(root->left, key);
    else if(key>root->key)
        root->right=deleteNode(root->right, key);
    else{
        if(root->left==NULL){
            Node* temp=root->right;
            free(root);
            return temp;
        }
        else if(root->right==NULL){
            Node* temp=root->left;
            free(root);
            return temp;
        }

        Node* temp=minValueNode(root->right);
        root->key=temp->key;
        strcpy(root->value, temp->value);
        root->right=deleteNode(root->right, temp->key);
    }
    return root;
}

// Perform an inorder traversal of the BST
void inorder(Node* root){
    if(root!=NULL){
        inorder(root->left);
        printf("%d:%s\n", root->key, root->value);
        inorder(root->right);
    }
}
int main(){
    Node* root=NULL;
    int n;
    scanf("%d", &n);
    
    for(int i=0; i<n; i++){
        char command[10], value[101];
        int key;
        scanf("%s", command);
        
        if(strcmp(command, "Insert")==0){
            scanf("%d %s", &key, value);
            root=insert(root, key, value);
        } else if(strcmp(command, "Search")==0){
            scanf("%d", &key);
            Node* result=search(root, key);
            if(result) printf("%s\n", result->value);
            else printf("Key not found\n");
        } else if(strcmp(command, "Delete")==0){
            scanf("%d", &key);
            Node* result=search(root, key);
            if(result) root=deleteNode(root, key);
            else printf("Key not found\n");
        } else if(strcmp(command, "Inorder")==0){
            inorder(root);
        }
    }

    return 0;
}