#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct node{
    char c;
    struct node *left;
    struct node *right;
} NODE;

typedef struct stack{
    NODE *node;
    struct stack *next;
} STACK;

