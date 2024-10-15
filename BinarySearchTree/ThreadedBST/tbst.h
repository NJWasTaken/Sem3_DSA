#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

typedef struct node{
    int data;
    struct node *right;
    struct node *left;
    bool left_t;
    bool right_t;
}NODE;

NODE* CreateNode(int);
bool SearchTree(NODE*, int, NODE**);
NODE *insert(int, NODE*);
NODE* CreateTree(NODE *);
void PrintTree(NODE *);
NODE* Manipulate(NODE *);