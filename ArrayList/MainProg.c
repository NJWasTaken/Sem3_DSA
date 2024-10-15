#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <ctype.h>
#include "ArrayList.h"
#define MAX_SIZE	100


extern void CreateList ();
extern bool Insert ();
extern void Delete ();
extern void Search ();
extern void Display ();
extern void Modify ();
extern bool IsListEmpty ();

int main ()
{
	int *cur_max;	// Indicates the number of elements in the list
	int list [MAX_SIZE];
	char option;
	bool ret_val;
	CreateList (cur_max, list);	// Create the list

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
				if ((ret_val = Insert(cur_max,list)) == false)
					printf ("Insert failed\n");
			break;

			case 'M':
				Modify (cur_max, list);
			break;

			case 'D':
				Delete (cur_max, list);
			break;

			case 'S':
				Search (cur_max, list);
			break;

			case 'P':
				Display (cur_max, list);
			break;

			case 'E':
				if (IsListEmpty (*cur_max))
					printf ("List is empty\n");
				else
					printf ("List is not empty\n");
			break;

			default:
				printf ("Invalid option\n");
		}
	}
	return 0;
}