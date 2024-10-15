#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <ctype.h>
#include "StackList.h"


NODE *CreateNode(int value){
    NODE *p_node = (NODE *)malloc(sizeof(NODE));
    if (p_node == NULL) {
        printf("Memory not available to create node.\n");
        exit(0);
    }
    p_node->data = value;
    p_node->next = NULL;
    return p_node;
}

void CreateStack(NODE **head) {
    NODE *p_head=*head;
    int size,n;
    printf("Enter size of the stack: ");
    scanf("%d",&size);
    for (int i = 0; i < size; i++)
    {
        printf("Enter value %d: ",i+1);
        scanf("%d",&n);
        NODE *new = CreateNode(n);
        if (i==0)p_head=new;
        else{
            new->next=p_head;
            p_head=new;
            *head=p_head;
        }
    }
}

void push (NODE **head){
    NODE *p_head=*head;
    int n;
    printf("Enter value to push to the stack: ");
    scanf("%d",&n);
    NODE *new = CreateNode(n);
    new->next=p_head;
    p_head=new;
    *head=p_head;
}

void pop (NODE **head){
    NODE *p_head=*head;
    if (p_head==NULL)printf("Stack is empty.\n");
    else{
        int n=p_head->data;
        printf("Deleted %d from the stack.\n",n);
        NODE *temp = p_head;
        p_head=p_head->next;
        free(temp);
    }
    *head=p_head;
}

void peek (NODE **head){
    NODE *p_head=*head;
    if (p_head==NULL)printf("Stack is empty.\n");
    else{printf("Value at the top of the stack: %d\n",p_head->data);}
}

void PrintStack (NODE *head){
    NODE *p_temp=head;
    if (head==NULL)printf("NULL\n");
    else{
        printf("%d->",p_temp->data);
        while(p_temp->next!=NULL)
        {
            p_temp=p_temp->next;
            printf("%d->",p_temp->data);
        }
        printf("NULL\n");
    }
}

bool IsStackEmpty (NODE *head){
    NODE *p_head=head;
    return p_head==NULL;
}

void FreeStack (NODE **head){
    NODE *p_head=*head;
    while(p_head!=NULL){
        NODE *temp=p_head;
        p_head=p_head->next;
        free(temp);
    }
    printf("Freed the stack.");
}