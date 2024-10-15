#include <stdio.h>
#include <stdbool.h>
#include <ctype.h>
#include "SLList.h"
#include <stdlib.h>

static NODE *head = NULL;
static int size = 0;

int ListSize(){
    int count = 0;
    NODE *p_node = head;
    while (p_node != NULL) {
        count++;
        p_node = p_node->next;
    }
    return count;
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

void CreateList() {
    NODE *p_node, *p_temp;
    
    printf("Enter the number of elements to be added in the list:\t");
    scanf("%d", &size);

    for (int i = 0; i < size; i++) {
        int value;
        printf("Enter value for element %d: ", i + 1);
        scanf("%d", &value);
        p_node = CreateNode(value);

        if (head == NULL) {
            head = p_node;
        } else {
            p_temp = head;
            while (p_temp->next != NULL) {
                p_temp = p_temp->next;
            }
            p_temp->next = p_node; 
        }
    }
}

void PrintList() {
    NODE* p_temp = head;
    while (p_temp != NULL) {
        printf("%d -> ", p_temp->data);
        p_temp = p_temp->next;
    }
    printf("NULL\n");
}

void InsertAtBeginning (){
    NODE *p_node;
    int value;
    printf("Enter value to insert at the beginning: ");
    scanf("%d", &value);
    p_node = CreateNode(value);
    p_node->next = head;
    head = p_node;
}

void InsertAtEnd (){
    NODE *p_node, *p_temp;
    int value;
    printf("Enter value to insert at the end: ");
    scanf("%d", &value);
    p_node = CreateNode(value);
    if (head == NULL) {
        head = p_node;
    } else {
        p_temp = head;
        while (p_temp->next != NULL) {
            p_temp = p_temp->next;
        }
        p_temp->next = p_node;
    }
}

void InsertAnywhere (){
    NODE *p_node, *p_temp;
    int pos, value;
    printf("Enter position to insert elements into (0 to %d): ", size);
    scanf("%d", &pos);
    printf("Enter value to insert: ");
    scanf("%d", &value);
    
    if (pos == 0) {
        InsertAtBeginning();
    } else {
        p_node = CreateNode(value);
        p_temp = head;
        for (int i = 0; i < pos - 1 && p_temp != NULL; i++) {
            p_temp = p_temp->next;
        }
        if (p_temp != NULL) {
            p_node->next = p_temp->next;
            p_temp->next = p_node;
        } else {
            printf("Invalid position.\n");
        }
    }
    size++;
}

void DeleteFirstNode (){
    if (head != NULL) {
        NODE *p_temp = head;
        head = head->next;
        free(p_temp);
    }
    else{
        printf("Already empty.");
    }
}
void DeleteLastNode() {
    if (head == NULL) {
        printf("Already empty.");  
    }
    if (head->next == NULL) {
        free(head);
        head = NULL;
        return;
    }
    else{
        NODE *p_temp = head;
        while (p_temp->next->next != NULL) {
                p_temp = p_temp->next;
        }
        free(p_temp->next);  
        p_temp->next = NULL;  
    }
}

void DeleteAnywhere (){
    int pos;
    printf("Enter position of element to delete (0 to %d): ", size-1);
    scanf("%d",&pos);
    if (pos>=size-1){
        DeleteLastNode();
    }
    else if (pos==0) {
        DeleteFirstNode();  
    }
    else{
        if (head==NULL) printf("Already empty.");
        else{
            NODE *p_node = head;
            for (int i = 0; i < pos - 1 && p_node != NULL; i++) {
                p_node = p_node->next;
            }
            NODE *p_temp = p_node->next; 
            p_node->next = p_node->next->next;
            free(p_temp);
        }  
    }
}

void ModifyList (){ 
    int pos, value;
    printf("Enter position to modify into (0 to %d): ", size-1);
    scanf("%d", &pos);
    printf("Enter new value: ");
    scanf("%d", &value);
    if (pos<0 || pos>(size-1)){
        printf("Invalid position.\n");
    }
    else{
        NODE *p_temp = head;
        for (int i = 0; i < pos && p_temp != NULL; i++){
            p_temp=p_temp->next;
        }
        p_temp->data = value;
    }
}

bool SearchList (){
    NODE *p_temp = head;
    int s, found=0;
    printf("Enter element to search for: ");
    scanf("%d", &s);
    while (p_temp->next != NULL) {
        if (p_temp->data==s){
            found=1;
        }
        p_temp = p_temp->next;
    }
    return (found==1);
}

bool IsListEmpty (){
    return (size==0);
}

void Quit(){
    NODE *p_node = head;
    while(head!=NULL){
        printf("Deleting node with element: %d\n", head->data);
        head=head->next;
        free(p_node);
        p_node=head;
    }
    printf("All nodes freed. Exiting...");
}

void Reverse(){
    NODE *curr = head, *prev=NULL, *next;
    printf("Starting...");
    while (curr!=NULL){
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    head=prev;
    printf("Done");
}