//			priorityqMain.c					

// C code to implement Priority Queue using Linked List 
#include <stdio.h> 
#include <stdlib.h> 
#include <ctype.h>
#include "priorityq.h"
  
int main ()
{
	NODE *head = NULL;
	int data, priority;
	char option;
	int ret_val;
	
	while (1)
	{
		printf ("\nSelect: I - Insert D - Delete S - Show P - Peek E - Empty? Q - Quit:");
		scanf (" %c",&option);
		option = toupper (option);
		if (option == 'Q')
			break;
		switch (option)
		{
			case 'I':
				printf ("Key in the data:");
				scanf ("%d", &data);
				printf ("Key in the priority:");
				scanf ("%d", &priority);
				InsertNode (&head, data, priority);
			break;

			case 'D':
				if (DeleteNode (&head) == -1)
					printf ("Queue is empty; nothing to delete\n");
			break;

			case 'P':
				ret_val = Peek (&head, &data, &priority);
				if (ret_val == -1)
					printf ("No data in the queue\n");
				else
					printf ("Data is %d priority is %d\n", 
							data, priority);
			break;


			case 'S':
				PrintQueue (head);
			break;


			break;

			case 'E':
				if (isEmpty (&head))
					printf ("List is empty\n");
				else
					printf ("List is not empty\n");
			break;

			default:
				printf ("Invalid option\n");
		}
	}
	freeList (&head);
	return 0;
}
