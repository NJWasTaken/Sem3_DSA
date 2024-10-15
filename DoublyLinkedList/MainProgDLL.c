//			MainProgDLL.c	
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <ctype.h>
#include "DLList.h"

int main ()
{
	char option, sub_opt;
	bool ret_val;
	
	CreateList ();	// Create the list

	while (1)
	{
		printf ("Select: I - Insert D - Delete S - Search P - Print M - Modify E - Empty? N - Navigate Q - Quit:");
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
				NavigateList ();
			break;

			case 'P':
				printf ("Sub options: F - Forward R - Reverse:");
				scanf (" %c", &sub_opt);
				sub_opt = toupper (sub_opt);
				switch (sub_opt)
				{
					case 'F':
						PrintList ();
					break;

					case 'R':
						ReversePrint ();
					break;
					default:
						printf ("Invalid option\n");
				}
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