//				MainCircularSLL.c

// A circularly linked list (singly linked list)

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <ctype.h>
#include "CircularList.h"

int main ()
{
	char option, sub_opt;
	bool ret_val;
	
	CreateList ();	// Create the list

	while (1)
	{
		printf ("Select\n: I - Insert\n D - Delete\n S - Search\n P - Print\n M - Modify\n N - Navigate\n E - Empty?\n Q - Quit:");
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
						InsertAtBeginning ();
					break;

					case 'L':
						InsertAtEnd ();
					break;

					case 'O':
						InsertAnywhere ();
					break;

					default:
						printf ("invalid option\n");
				}
			break;

			case 'M':
				ModifyList ();
			break;

			case 'D':
				printf ("Sub options: F - First Node L - Last Node O - Any Node:");
				scanf (" %c", &sub_opt);
				sub_opt = toupper (sub_opt);
				switch (sub_opt)
				{
					case 'F':
						DeleteFirstNode ();
					break;

					case 'L':
						DeleteLastNode ();
					break;

					case 'O':
						DeleteAnyNode ();
					break;

					default:
						printf ("invalid option\n");
				}

			break;

			case 'S':
				if (SearchList () == true)
					printf ("Element found\n");
				else
					printf ("Element not found\n");
			break;
			
			case 'N':
				Navigate();
			break;

			case 'P':
				 PrintList ();
			break;

			case 'E':
				if (IsListEmpty ())
					printf ("List is empty\n");
				else
					printf ("List is not empty\n");
			break;

			default:
				printf ("Invalid option\n");
		}
	}
	FreeList ();
	return 0;
}