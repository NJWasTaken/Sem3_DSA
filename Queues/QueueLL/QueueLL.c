#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>
#include "QueueList.h"

static QUEUE q;


void InitData(){
    q.front=q.rear=NULL;
}

NODE *CreateNode(int value){
    NODE *p_node = (NODE *)malloc(sizeof(NODE));
    if (p_node == NULL) {
        printf("Memory not available to create node.");
        exit(0);
    }
    p_node->data = value;
    p_node->next = NULL;
    return p_node;
}

void Enqueue(int data){
    NODE *p_node = CreateNode(data);
    if (q.front==NULL&&q.rear==NULL){
        q.front=p_node;
        q.rear=p_node;
    }
    else{
        q.rear->next=p_node;
        q.rear=q.rear->next;
    }
}

int Dequeue(){
    if (q.front==NULL&&q.rear==NULL) printf("Error: Queue underflow.");
    else{
        int data = q.front->data;
        NODE *p_temp=q.front;
        q.front=q.front->next;
        free(p_temp);
        return data;
    }
}

int Peek(){
    return q.front->data;
}

bool isEmpty(){
    return q.front==NULL&&q.rear==NULL;
}

void DisplayQ(){
    NODE *p_temp=q.front;
    while(p_temp!=NULL){
        printf("%d <-",p_temp->data);
        p_temp=p_temp->next;
    }
}

void freeList(){
    
}