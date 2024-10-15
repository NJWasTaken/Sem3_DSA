#include <stdio.h>
#include <stdbool.h>
#include <ctype.h>
#include "DLList.h"
#include <stdlib.h>

static NODE *head=NULL; 
static NODE *tail=NULL;
static int size=0;

NODE *CreateNode(){
    NODE *p_node = (NODE *)malloc(sizeof(NODE));
    if (p_node == NULL) {
        printf("Memory not available to create node.");
        exit(0);
    }
    p_node->prev = NULL;
    p_node->next = NULL;
    printf("Enter value: ");
    scanf("%d", &p_node->data);
    return p_node;
}

void CreateList() {
    NODE *p_temp,*p_node;
    printf("Enter the number of elements to be added in the list:\t");
    scanf("%d", &size);
    printf("Size: %d\n", size);
    for (int i = 0; i < size; i++) {
        p_node = CreateNode();
        if (head == NULL && tail == NULL) {
            head = tail = p_node;
        } else {
            for(p_temp=head;p_temp->next!=NULL;p_temp=p_temp->next);
            p_temp->next = p_node;
            p_node->prev = p_temp;
            tail = p_node;
        }
    }
}

void PrintList(){
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

void ReversePrint(){
    NODE *p_temp=tail;
    if (tail==NULL)printf("NULL\n");
    else{
        while(p_temp!=NULL)
        {
            printf("%d->",p_temp->data);
            p_temp=p_temp->prev;
        }
        printf("NULL\n");
    }
}

void InsertAtBeginning (){
    NODE *p_temp=head;
    if (head==NULL) head=CreateNode();
    NODE *p_new=CreateNode();
    p_new->next=p_temp;
    p_temp->prev=p_new;
    head=p_new;
    size++;
}

void InsertAtEnd(){
    NODE *p_temp=tail;
    if (tail==NULL) tail=CreateNode();
    NODE *p_new=CreateNode();
    p_new->prev=p_temp;
    p_temp->next=p_new;
    tail=p_new;
    size++;
}

void InsertAnywhere(){
    NODE *p_temp=head;
    int pos;
    printf("Enter position to insert into (1-%d): ",size);
    scanf("%d",&pos);
    if (pos<=1) InsertAtBeginning();
    else if (pos>=size) InsertAtEnd();
    else{
        for(int i=1; i<pos-1 &&p_temp!=NULL;p_temp=p_temp->next){i++;}
        NODE *p_node=CreateNode(),*p_t2=p_temp->next;
        p_temp->next=p_node;
        p_node->prev=p_temp;
        p_node->next=p_t2;
    }
}

bool IsListEmpty(){
    return (size==0);
}

void DeleteFirstNode(){
    if (head==NULL) printf("List is already empty.\n");
    else if(head->next==NULL){
        NODE *temp=head;
        free(temp);
        head=NULL;
    }
    else{
        head=head->next;
        NODE *h_prev=head->prev;
        free(h_prev);
        head->prev=NULL;
    }
}

void DeleteLastNode(){
    if(tail==NULL) printf("List is already empty.\n");
    else if(size=1){
        NODE *temp=tail;
        free(temp);
        tail=NULL;
        size=0;
    }
    else{
        tail=tail->prev;
        NODE *t_next=tail->next;
        free(t_next);
        tail->next=NULL;
        size--;
    }
}

void DeleteAnyNode(){
    NODE *p_temp=head;
    int pos;
    printf("Enter position to delete (1-%d): ",size);
    scanf("%d",&pos);
    if (pos<=1) DeleteFirstNode();
    else if (pos>=size) DeleteLastNode();
    else{
        for(int i=1; i<pos &&p_temp!=NULL;p_temp=p_temp->next){i++;}
        NODE *ahead=p_temp->next;
        NODE *behind=p_temp->prev;
        free(p_temp);
        ahead->prev=behind;
        behind->next=ahead;
        size--;
    }
}

void NavigateList(){
    NODE *p_node=head;
    bool flag=true;
    char op;
    while(flag){
        printf ("Select: F - Move to First L - Move to Last P - Previous N - Next Q - Quit: ");
        scanf (" %c",&op);
        op = toupper (op);
        if (op == 'Q') flag=false;
        else{
            switch (op)
            {
            case 'F':
                p_node=head;
                printf("Value: %d\n",p_node->data);
                break;
            
            case 'L':
                p_node=tail;
                printf("Value: %d\n",p_node->data);
                break;


            case 'N':
                if (p_node->next==NULL){
                    printf("Already at the last node.\n");
                    p_node=tail;
                    break;
                }
                else{
                    p_node=p_node->next;
                    printf("Value: %d\n",p_node->data);
                    break;
                }


            case 'P':
                if (p_node->prev==NULL){ 
                    printf("Already at the first node.\n");
                    p_node=head;
                    break;
                }
                else{
                    p_node=p_node->prev;
                    printf("Value: %d\n",p_node->data);
                    break;
                }

                    
            default:
                printf("Invalid option.\n");
                break;
            }
        }
    }
}

bool SearchList(){}
void ModifyList(){
}