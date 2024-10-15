//			MainProgStack.c

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <ctype.h>
#include "StackList.h"

int main ()
{
	char option, sub_opt;
	bool ret_val;
	NODE *head = NULL;
	
	CreateStack (&head);	// Create the stack

	while (1)
	{
		printf ("Select: P - Push O - Pop E - Peek T - Print M - Empty? Q - Quit:");
		scanf (" %c",&option);
		option = toupper (option);
		if (option == 'Q')
			break;
		switch (option)
		{
			case 'P':		// Push
				push (&head);
			break;

			case 'O':		// Pop
				pop (&head);
			break;

			case 'E':		// Peek
				peek (&head);
			break;

			case 'M':		// Empty ?
				if (IsStackEmpty (head))
					printf ("Stack is empty\n");
				else
					printf ("Stack is not empty\n");
			break;

			case 'T':		// Print
				 PrintStack (head);
			break;

			default:
				printf ("Invalid option\n");
		}
	}
	FreeStack (&head);
	return 0;
}