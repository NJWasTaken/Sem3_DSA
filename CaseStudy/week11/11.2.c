#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

// Define the structure of a BST node
typedef struct Node {
    int key;
    struct Node *left, *right;
} Node;

// Create a new node with the given key
Node* newNode(int key) {
    Node* node=(Node*)malloc(sizeof(Node));
    if(node==NULL){
        printf("Could not allocate memory\n");
        exit(EXIT_SUCCESS);
    }
    node->key=key;
    node->left=NULL;
    node->right=NULL;

    return node;
}

// Insert a key into the BST
Node* insert(Node* root, int key) {
    if(root==NULL){
        return newNode(key);
    }
    if(key<root->key){
        root->left=insert(root->left,key);
    }
    else if(key>root->key){
        root->right=insert(root->right,key);
    }
    

    return root;
}

// Perform a range sum query in the BST
int rangeSum(Node* root, int L, int R) {
    if (root == NULL)
        return 0;

    if (root->key < L)
        return rangeSum(root->right, L, R);

    if (root->key > R)
        return rangeSum(root->left, L, R);

    return root->key + rangeSum(root->left, L, R) + rangeSum(root->right, L, R);
}

int main() {
    Node* root = NULL;
    int n;
    scanf("%d", &n);
    
    for (int i = 0; i < n; i++) {
        char command[10];
        int x, L, R;
        scanf("%s", command);
        
        if (strcmp(command, "Insert") == 0) {
            scanf("%d", &x);
            root = insert(root, x);
        } else if (strcmp(command, "RangeSum") == 0) {
            scanf("%d %d", &L, &R);
            printf("%d\n", rangeSum(root, L, R));
        }
    }

    return 0;
}