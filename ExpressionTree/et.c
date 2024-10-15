#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "et.h"

static STACK *head;

NODE *CreateNode(char c){
    NODE *node;
    node=(NODE*)malloc(sizeof(NODE));
    if (node==NULL){
        printf("Memory not available for allocation.");
        exit(0);
    }
    node->c=c;
    node->left=NULL;
    node->right=NULL;
    return node;
}

STACK *CreateStackNode(NODE* new){
    STACK *node;
    node=(STACK*)malloc(sizeof(STACK));
    if (node==NULL){
        printf("Memory not available for allocation.");
        exit(0);
    }
    node->node=new;
    node->next=NULL;
    return node;
}

void push(char c){
    NODE *node = CreateNode(c);
    STACK *temp = CreateStackNode(node);
    temp->next=head;
    head=temp;
}

void pushNode(NODE* node){
    STACK *temp = CreateStackNode(node);
    temp->next=head;
    head=temp;
}

NODE* pop(){
    if (head==NULL){
        printf("Stack underflow error.\n");
        return NULL;
    }
    else{
        NODE* popped = head->node;
        STACK* temp=head;
        head=head->next;
        free(temp);
        return popped;
    }
}

bool isOperator(char c){
    bool res;
    if (c=='+'||c=='-'||c=='*'||c=='/')res=true;
    else{res=false;}
    return res;
}

NODE *CreateTree(char *s){
    while(*s){
        char ch = *s;
        if (ch!=' '){
            if (!isOperator(ch)){
                push(ch);
            }
            else{
                NODE *a = pop();
                NODE *b = pop();
                NODE *node = CreateNode(ch);
                node->left=a;
                node->right=b;
                pushNode(node);
            }
        }
    }
    NODE* root;
    while (head!=NULL)
    {
        root=pop();
    }
    return root;
}


int main(){
    char s[100];
    printf("Enter postfix string: ");
    scanf(" %[^\n]s",s);
    NODE* root = CreateTree(s);
    printf("ROOT: %c, LEFT: %c, RIGHT: %c", root->c,root->left->c,root->right->c);
    return 0;
}
