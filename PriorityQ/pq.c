#include <stdio.h> 
#include <stdlib.h> 
#include <ctype.h>
#include "priorityq.h"

NODE* newNode(int d, int p){
    NODE *p_node = (NODE *)malloc(sizeof(NODE));
    if (p_node == NULL) {
        printf("Memory not available to create node.");
        exit(0);
    }
    p_node->data = d;
    p_node->priority=p;
    p_node->next = NULL;
    return p_node;
}
 
int Peek(NODE** head, int *d, int *p){
    int ret;
    NODE *p_node = *head;
    if (p_node == NULL) ret =-1;
    else{
        *d = p_node->data;
        *p = p_node->priority;
        ret=0;
    }
    return ret;
}
int DeleteNode (NODE** head){
    NODE *p_head=*head;
    int n;
    if (p_head==NULL)n=-1;
    else{
        NODE *temp=*head;
        p_head=p_head->next;
        printf("Deleted value: %d, with priority: %d", temp->data,temp->priority);
        free(temp);
        *head=p_head;
        n=0;
    }
    return n;
}
  
void InsertNode (NODE **head, int d, int p){
    NODE *new = newNode(d, p);
    if (*head == NULL || (*head)->priority > p) {
        new->next = *head;  
        *head = new;
    } else {
        NODE *current = *head;
        while (current->next != NULL && current->next->priority < p) current = current->next;
        
        new->next = current->next;
        current->next = new;
    }
}

int isEmpty(NODE** head){
    NODE *p_head=*head;
    int res;
    if (p_head==NULL)res=1;
    else{res=0;}
    return res;
}

void PrintQueue (NODE *head){
    NODE *p_head=head;
    if(p_head==NULL)printf("The queue is empty.");
    while(p_head!=NULL){
        printf("Data: %d\nPriority: %d\n\n",p_head->data,p_head->priority);
        p_head=p_head->next;
    }
}

void freeList (NODE **head){
    NODE *p_head=*head;
    while(p_head!=NULL){
        NODE *temp=p_head;
        p_head=p_head->next;
        free(temp);
    }
    printf("Freed the list. Exiting...");
}