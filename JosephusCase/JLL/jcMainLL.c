#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>

typedef struct node{
    int val;
    int pos;
    struct node *next;
} NODE;

NODE *CreateNode(int val){
    NODE *p_node;
    if ((p_node = (NODE *) malloc (sizeof (NODE))) == NULL)
	{
		printf ("Unable to create node: memory not available\n");
		exit (0);		
	}
    p_node->val=val;
    return p_node;
}

void CreateList(NODE **head, NODE **tail){
    NODE *p_head=*head;
    NODE *p_tail=*tail;
    int n,val;
    printf("Enter number of elements to be added to the list: ");
    scanf("%d",&n);

    for (int i = 0; i < n; i ++)
	{
		printf("Enter value to be added: ");
        scanf("%d",&val);
        NODE *p_node = CreateNode(val);
		p_node->pos=i+1;

		if (p_head == NULL)
            p_head = p_tail = p_node;

		else
		{
			p_tail -> next = p_node;
			p_tail = p_node;
		}
        p_tail -> next = p_head;
	}
    *head = p_head;
    *tail = p_tail; 
}

void *SkipThis(NODE **cur,int skipval){
    NODE *p=*cur;
    for (int i = 0; i < skipval-1; i++)
    {
        p=p->next;
    }
    NODE *temp=p;
    p=p->next;
    temp->next=p->next;
    printf("Killed value: %d at position: %d\n",p->val,p->pos);
    free(p);
    temp=temp->next;
    *cur=temp;
}

int Count(NODE **head){
    NODE *temp = *head;
    int n=0;
    if (temp != NULL) {
        NODE *start = temp;
        do {
            n++;
            temp = temp->next;
        } while (temp != start);  
    }
    return n;
}

void PrintList(NODE **head){
    NODE *temp = *head;
    if (temp == NULL) {
        printf("List is empty.\n");
        return;
    }
    if (temp->next=temp){
        printf("Survivor is %d at position %d\n",temp->val,temp->pos);
        return;
    }
    NODE *start = temp;
    do {
        printf("Value :%d at Position: %d\n", temp->val, temp->pos);
        temp = temp->next;
    } while (temp != start);  
}

int main(int argc, char **argv){
    if (argc<2){
        printf("Usage: %s <SkipVal>\n",argv[0]);
        exit(0);
    }
    NODE *head=NULL,*tail=NULL;
    int skip=atoi(argv[1]);
    CreateList(&head,&tail);
    int size = Count(&head);
    PrintList(&head);
    while (size>1)
    {
        SkipThis(&head,skip);
        size--;
    }   
    PrintList(&head);
}