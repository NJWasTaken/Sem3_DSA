//			DequeMain.c

// Deque implementation in C

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <limits.h>
#include "DequeFunctions.h"

int main (int argc, char *argv[]) 
{
	int maxSize, data;
	char choice;

	if (argc < 2)
	{
		printf ("Usage: %s <Max Size>\n", argv[0]);
		exit (0);
	}
	maxSize = atoi (argv[1]);
	int arr [maxSize];
  	int front, rear, n;

	if (maxSize%2==0){
		rear=maxSize/2;
		front=(maxSize/2) - 1;
	}
	else{
		front = rear = (maxSize-1)/2;
	}
	
  	for (int i = 0; i < maxSize; i++)
    		arr[i] = INT_MAX;
	do
	{
		printf ("Key in your option: \nF - Insert at beginning\n B - Add at the end\n D - Delete from front\n K - Delete at rear end\n S - Display\n Q - Quit:");
		scanf (" %c", &choice);
		choice = toupper (choice);
		if (choice == 'Q')
			break;
		switch (choice)
		{
			case 'F':	// Add at the front
				printf ("Key in the data to be added:");	
				scanf ("%d", &data);
				addFront (arr, data, &front, &rear, maxSize);
			break;

			case 'B':	// Add at the rear end
				printf ("Key in the data to be added:");	
				scanf ("%d", &data);
				addRear (arr, data, &front, &rear, maxSize);
			break;

			case 'D':	// Delete from the front
				printf("Value deleted: %d\n",delFront (arr, &front, &rear));
			break;

			case 'K':	// Delete from the back
				printf("Value deleted: %d\n",delRear (arr, &front, &rear));
			break;

			case 'S':	// Display the Q contents
				display (arr, maxSize);
			break; 

			default:
				printf ("Invalid choice\n");
		}
	} while (1);
}