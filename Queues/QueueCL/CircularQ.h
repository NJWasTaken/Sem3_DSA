//		CircularQ.h
#include <stdbool.h>
void Enqueue (int *, int *, int *, int, int);
int Dequeue (int *, int *, int *, int, int *);	// Return the first value and remove it
int Peek (int *, int, int, int *);	// Return the first value, keep it in the q
bool isFull (int, int, int);		// Check whether queue is full
bool isEmpty (int, int);		// Check whether queue is empty
void displayQ (int *, int, int, int);	// Display the contents of the queue