//		QueueList.h
#include <stdbool.h>
typedef struct node
{
	int data;
	struct node *next;
} NODE;

typedef struct queue
{
	NODE *front;
	NODE *rear;
} QUEUE;

void InitData ();
void Enqueue (int);
int Dequeue ();		// Return the first value and remove it
int Peek ();		// Return the first value, keep it in the q
bool isEmpty ();	// Check whether queue is empty
void DisplayQ ();
void freeList ();