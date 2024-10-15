//				MainCircularSLL2.c

// A circularly linked list (using singly linked list and passing arguments)

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <ctype.h>
#include "CircularList2.h"

int main ()
{
	NODE *head = NULL, *tail = NULL;
	char option, sub_opt;
	bool ret_val;
	
	CreateList (&head, &tail);	// Create the list

	while (1)
	{
		printf ("Select: I - Insert D - Delete S - Search P - Print M - Modify E - Empty? Q - Quit:");
		scanf (" %c",&option);
		option = toupper (option);
		if (option == 'Q')
			break;
		switch (option)
		{
			case 'I':
				printf ("Sub options: F - First Node L - Last Node O - Others:");
				scanf (" %c", &sub_opt);
				sub_opt = toupper (sub_opt);
				switch (sub_opt)
				{
					case 'F':
						InsertAtBeginning (&head, &tail);
					break;

					case 'L':
						InsertAtEnd (&head, &tail);
					break;

					case 'O':
						InsertAnywhere (&head, &tail);
					break;

					default:
						printf ("invalid option\n");
				}
			break;

			case 'M':
				ModifyList (head);
			break;

			case 'D':
				printf ("Sub options: F - First Node L - Last Node O - Any Node:");
				scanf (" %c", &sub_opt);
				sub_opt = toupper (sub_opt);
				switch (sub_opt)
				{
					case 'F':
						DeleteFirstNode (&head, &tail);
					break;

					case 'L':
						DeleteLastNode (&head, &tail);
					break;

					case 'O':
						DeleteAnyNode (&head, &tail);
					break;

					default:
						printf ("invalid option\n");
				}

			break;

			case 'N':
				Navigate(head,tail);
			break;

			case 'S':
				if (SearchList (head) == true)
					printf ("Element found\n");
				else
					printf ("Element not found\n");
			break;

			case 'P':
				while(1){
					printf("Select: F - Forward print R - Reverse print Q - Quit: ");
					char option;
					scanf(" %c",&option);
					option= toupper(option);
					if (option=='Q')break;
					else{
						switch (option)
						{
						case 'F':
							PrintList(&head);
							break;
						
						case 'R':
							ReversePrint(&tail);
							break;

						default:
							printf("Invalid option.\n");
							break;
						}
					}
				}
			break;

			case 'E':
				if (IsListEmpty (head))
					printf ("List is empty\n");
				else
					printf ("List is not empty\n");
			break;

			default:
				printf ("Invalid option\n");
		}
	}
	FreeList (&head);
	return 0;
}