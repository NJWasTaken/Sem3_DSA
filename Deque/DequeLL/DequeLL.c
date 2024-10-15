#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <conio.h>
#include "DequeList.h"

NODE *NewNode (){
    NODE *p_node = (NODE *)malloc(sizeof(NODE));
    if (p_node == NULL) {
        printf("Memory not available to create node.");
        exit(0);
    }
    p_node->next = NULL;
    return p_node;
}
int Dequeue (NODE **front, NODE **rear){
    NODE *p_front=front;
    NODE *p_rear=rear;
    int data = INT_MAX;
    if (p_front==NULL&&p_rear==NULL){
        printf("Deque is already empty.\n");
    }
    else{
        data = p_front->info;
        NODE *p_temp = p_front;
        p_front=p_front->next;
        free(p_temp);
    }
    *front=p_front;
    return(data);
}

void Enqueue(int val, NODE **front, NODE **rear){
    NODE *p_rear =rear;
    NODE *p_front=front;
    NODE *new = NewNode();
    new->info=val;
    if (p_front==NULL&&p_rear==NULL){
        *rear=new;
        *front=new;
    }
    else{
        p_rear->next=new;
        p_rear=new;
    }
    *rear = p_rear;
    *front = p_front;
}

int DeleteLast(NODE **front, NODE **rear){
    NODE *p_temp=front;
    NODE *p_rear=rear;
    int data = INT_MAX;
    if (p_temp==NULL&&p_rear==NULL){
        printf("Deque is already empty.\n");
    }
    else{
        while(p_temp->next!=p_rear)p_temp=p_temp->next;
        data = p_rear->info;
        NODE *temp = p_rear;
        p_rear = p_temp;
        free(temp);
    }
    *rear = p_rear;
    return(data);
}      

void InsertFirst(int item, NODE **front, NODE **rear){
    NODE *p_rear =rear;
    NODE *p_front=front;
    NODE *new = NewNode();
    new->info=item;
    if (p_front==NULL&&p_rear==NULL){
        *rear=new;
        *front=new;
    }
    else{
        new->next=p_front;
        p_front=new;
    }
    *rear = p_rear;
    *front = p_front;
}

void PrintList(NODE **front){
    NODE *temp=front;
    while(temp!=NULL){
        printf("%d ",temp->info);
        temp=temp->next;
    }
}
