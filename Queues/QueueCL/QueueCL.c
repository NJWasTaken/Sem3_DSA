#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>
#include "CircularQ.h"

void displayQ (int myqueue [], int front, int rear, int max_size)
{
	if (isEmpty (front, rear))
		printf ("Queue is empty: nothing to display\n");
	else
	{
		for (int i = front; (i % max_size) != rear; i ++)
			printf ("Data is %d\n", myqueue [i]);
	}
}

void Enqueue (int myQueue [], int *p_rear, int *p_front, int max_size, int data)
{
	int rear = *p_rear;
	int front = *p_front;

	if (isFull (rear, front, max_size))
		printf ("Queue is full\n");
	else
	{
		myQueue [rear] = data;
		rear = (rear + 1) % max_size;
		*p_rear = rear;
	}
}
		
int Dequeue (int myQueue [], int *p_front, int *p_rear, int max_size, int *data)
{
	int front = *p_front;
	int rear = *p_rear;

	if (isEmpty (front, rear))
	{
		printf ("There is nothing to read\n");
		return -1;
	}

	*data = myQueue [front];
	front = (front + 1) % max_size;
	*p_front = front;
	return 0;
}

bool isEmpty (int front, int rear)
{
	bool ret_val = false;
	if (rear == front)
		ret_val = true;
	return ret_val;
}
	
bool isFull (int rear, int front, int maxSize)
{
	bool ret_val = false;
	if (((rear + 1) % maxSize) == front)
		ret_val = true;
	return ret_val;
}

int Peek (int myQueue [], int front, int rear, int *data)
{
	if (isEmpty (front, rear))
	{
		printf ("Queue is empty\n");
		return 	-1;
	}
	*data = myQueue [front];
	return 0;
}