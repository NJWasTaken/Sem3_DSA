//			QueuewithArrays.c
// Implementation of queue using arrays

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>
#include "QueueArray.h"

void Enqueue (int myQueue [], int *p_rear, int max_size, int data)
{
	int rear = *p_rear;

	if (rear <= (max_size - 1))
	{
		myQueue [rear] = data;
		*p_rear = rear + 1;
	}
	else
		printf ("Queue is full\n");
}
		
int Dequeue (int myQueue [], int *p_front, int *p_rear, int max_size, int *data)
{
	int front = *p_front;
	int rear = *p_rear;

	if (front >= rear)
	{
		printf ("Queue is empty\n");
		return 	-1;
	}
	*data = myQueue [front];
	*p_front = front + 1;
	return 0;
}

bool isEmpty (int front, int rear)
{
	bool ret_val = ((front == 0) && (rear == 0)) ? true: false;
	return ret_val;
}
	
bool isFull (int rear, int maxSize)
{
	bool ret_val = (rear >= maxSize) ? true: false;
}

int Peek (int myQueue [], int front, int rear, int *data)
{
	if (front >= rear)
	{
		printf ("Queue is empty\n");
		return 	-1;
	}
	*data = myQueue [front];
	return 0;
}
