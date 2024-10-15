//				CircularSLList.c

// Implementation of a singly linked list (dynamic)
// All possible error conditions are not fully handled 

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "CircularList.h"
#include <ctype.h>

static NODE *head = NULL;
static NODE *tail = NULL;


int ListSize ()
{
	int count = 0;
	NODE *p_node = head;

	if (head != NULL)
	{
		while (1)
		{
			count ++;
			p_node = p_node -> next;
			if (p_node == head)
				break;
		}
	}
	else
		printf ("Empty list\n");
	return count;
}

// Creates a node; allocates memory, gets the data value, etc
NODE *CreateNode ()
{
 	NODE *p_node;
	if ((p_node = (NODE *) malloc (sizeof (NODE))) == NULL)
	{
		printf ("Unable to create node: memory not available\n");
		exit (0);		
	}
	p_node -> next = NULL;
	printf ("Key in the value:");
	scanf ("%d", &p_node->data);
	return p_node;
}

void ModifyList ()
{
	int pos, val;
	NODE *p_temp = head;
	int lSize = ListSize ();

	printf ("Number of the node you want to modify:");
	scanf ("%d", &pos);
	if (pos < 0 || pos >= lSize)
	{
		printf ("Invalid position\n");
		return;
	}
	printf ("The new value:");
	scanf ("%d", &val);

	for (int i = 0; i < (pos - 1); i ++)
		p_temp = p_temp -> next;
	p_temp->data = val;
}


void CreateList ()
{
	int num, val;
	NODE *p_node, *p_temp;

	printf ("How many nodes do you want to create?:");
	scanf ("%d", &num);

	for (int i = 0; i < num; i ++)
	{
		p_node = CreateNode ();
		
		if (head == NULL)
			head = tail = p_node;
		else
		{
			tail -> next = p_node;
			tail = p_node;
			tail -> next = head;
		}
	}	
}


void PrintList ()
{
	NODE *p_node;

	if (head != NULL)
	{
		p_node = head;
		while (1)
		{
			printf ("Val is %d\n", p_node->data);
			p_node = p_node -> next;
			if (p_node == head)
				break;
		}
	}
	else
		printf ("List is empty\n");
}


void InsertAtBeginning ()
{
	NODE *p_node;

	p_node = CreateNode ();
	p_node -> next = head;
	head = p_node;
	tail -> next = head;
}

void InsertAtEnd ()
{
	NODE *p_node;

	p_node = CreateNode ();
	
	tail -> next = p_node;
	tail = p_node;
	tail -> next = head;
}

void InsertAnywhere ()
{
	int pos;
	int listLen;
	NODE *p_temp = head, *p_prev, *p_node;

	listLen = ListSize ();
	printf ("Position at which to insert:");
	scanf ("%d", &pos);

	if (pos == 1)
		InsertAtBeginning ();
	else if (pos == listLen)
		InsertAtEnd ();
	else
	{
		for (int i = 0; p_temp != NULL; 
				p_prev = p_temp, p_temp = p_temp->next, i++)
		{
			if (i == (pos - 1))
			{
				p_node = CreateNode ();
				p_prev -> next = p_node;
				p_node -> next = p_temp;
				break;
			}
		}
	}	
}


bool SearchList ()
{
	NODE *p_temp;
	int value;
	bool found = false;
	bool go_on = true;

	printf ("What are you looking for?:");
	scanf ("%d", &value);
	if (head != NULL)
	{
		p_temp = head;
		while (go_on)
		{
			if (p_temp -> data != value)
			{
				p_temp = p_temp -> next;
				if (p_temp == head)
					go_on = false;
			}
			else
			{
				found = true;
				break;
			}
		}
	}
	return found; 
}

void DeleteFirstNode ()
{
	NODE *p_temp;

	if (head != NULL)
	{
		p_temp = head;
		head = head -> next;
		free (p_temp);
		tail -> next = head;
	}
	else
		printf ("There is nothing to delete\n");
}

void DeleteLastNode()
{
	NODE *curr, *prev = NULL;
	if (head != NULL)
	{
		// If the list has only one node, delete it.
		if (head->next == NULL)
		{ 
			free(head);
			head = tail = NULL;
		}
		else
		{
			for (curr = head; curr != tail; 
					prev = curr, curr = curr -> next)
				;
			tail = prev;
			tail -> next = head;
			free  (curr);
		}
	}							 
	else
		printf ("There is nothing to delete\n");
}

void DeleteAnyNode ()
{
	int nodeNum, i;
	int lsize = ListSize ();
	NODE *p_cur, *p_prev;

	printf ("Enter the number of the node you want to delete:");
	scanf ("%d", &nodeNum);

	if (nodeNum < 0 || nodeNum > lsize)
	{
		printf ("Invalid node number\n");
		exit (0);
	}

	if (nodeNum == 1)	// Delete first node
	{
		DeleteFirstNode ();
		return;
	}

	if (nodeNum == lsize)	// Last node to be deleted
	{
		DeleteLastNode ();
		return;
	}

	p_cur = head;
	for (i = 0; i < (nodeNum - 1); i ++, p_prev = p_cur, p_cur = p_cur -> next)
		;
	p_prev -> next = p_cur -> next;
	free (p_cur);
}



bool IsListEmpty ()
{
	bool ret_val;

	ret_val = head == NULL ? true: false;
	return ret_val;
}

void Navigate(){
	NODE *p_node=head;
	char option;
	while(1){
		printf ("Select: N - Next F - Go to First L - Go to Last Q - Quit:");
		scanf (" %c",&option);
		option = toupper (option);
		if (option == 'Q')
			break;
		switch (option){
			case 'N':
				p_node=p_node->next;
				printf("Value in the node: %d\n",p_node->data);
			break;

			case 'F':
				if (p_node==head)printf("Already at the first node.\n");
				p_node=head;
				printf("Value in the node: %d\n",p_node->data);
			break;

			case 'L':
				if (p_node==tail)printf("Already at the last node.\n");
				p_node=tail;
				printf("Value in the node: %d\n",p_node->data);
			break;

			default:
				printf("Invalid option.");
			break;
		}
	}
}


// Free the memory taken up by the whole list
void FreeList()
{
    	NODE *current = head;
    	NODE *nextNode;
    	while (1)
    	{
		nextNode = current->next;
        	free(current);
        	current = nextNode;
		if (current == head)
			break;
    	}
}