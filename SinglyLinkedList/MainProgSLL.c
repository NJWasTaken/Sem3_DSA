#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <ctype.h>
#include "SLList.h"

int main ()
{
	char option, sub_opt;
	bool ret_val;
	
	CreateList ();	// Create the list

	while (1)
	{
		printf ("Select: I - Insert D - Delete S - Search R - Reverse P - Print M - Modify E - Empty? Q - Quit:");
		scanf (" %c",&option);
		option = toupper (option);
		if (option == 'Q')
			Quit();
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
				printf ("Sub options: F - First Node L - Last Node O - Other:");
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
						DeleteAnywhere();
					break;
					
					default:
						printf ("invalid option\n");
				}

			break;

			case 'S':
				if (SearchList())
					printf ("Element found\n");
				else
					printf ("Element not found\n");
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

			case 'R':
				Reverse ();	
			break;

			default:
				printf ("Invalid option\n");
		}
	}
	return 0;
}