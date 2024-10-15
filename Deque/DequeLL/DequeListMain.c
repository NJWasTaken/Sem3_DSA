//				DequeListMain.c

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <conio.h>
#include "DequeList.h"


int main ()
{
	int data, choice;
	NODE *front = NULL;
	NODE *rear = NULL;
	while(1)
	{
		printf("1.Enqueue (InsertLast) 2.Dequeue (DeleteFirst) 3.Insert First 4.Delete Last 5.Display 6.Exit\n");
		printf("Enter your choice:");
		switch(getch())
		{
		case '1':
			printf("\nEnter a item you want to Insert :");
			scanf("%d",&data);
			Enqueue(data, &front, &rear);
		break;
		case '2':
			data = Dequeue (&front, &rear);
			printf ("\nData removed is %d\n", data);
		break;
        	case '3':
			printf("\nEnter a item you want to Insert :");
			scanf("%d",&data);
			InsertFirst (data, &front, &rear);
		break;
		case '4':
			data = DeleteLast (&front, &rear);
			printf ("\nData removed is %d\n", data);
		break;
		case '5':
			PrintList (&front);
		break;
		case '6':
			exit(0);
		default:
			printf("\nEnter a valid choice");
			break;
		}
	}
	return 0;
}
