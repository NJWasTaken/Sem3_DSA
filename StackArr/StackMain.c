//			StackMain.c - Implementation using array

#include <stdio.h>
#include <stdlib.h>  
#include <stdbool.h> 
#include <ctype.h>
#include "StackOps.h"

int main (int argc, char **argv)  
{  
	int myStack [STACK_SIZE];
	int maxSize = STACK_SIZE;
	char choice;
	int tVal;
	int top = -1;
	bool retVal;
	printf ("Stack implementation using array\n");  
    
	while (1)
	{
		printf ("Choose  P: Push O - Pop E - Peek M -Empty T - Print Q - quit: ");
		
		scanf (" %c", &choice);
		choice = toupper (choice);
		if (choice == 'Q')
			break;

		// Taking user input for the operation to be performed
		switch (choice)
		{
			case 'P':	// Push operation
				top = push (myStack, top, maxSize);
			break;

			case 'O':	// Pop operation
				top = pop (top);
			break;

			case 'E':	// Peek operation
				retVal = peek (myStack, top);
			break;

			case 'M':	// Is the stack empty:
				retVal = isEmpty (top);
				if (retVal == true)
					printf ("Stack is empty\n");
			break;

			case 'T':
				printStack (myStack, top);
			break;

			default:
				printf ("Invalid option\n");	
			break;

		}
	}
}
