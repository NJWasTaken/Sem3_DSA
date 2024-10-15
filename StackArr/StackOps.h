//			StackOps.h			
#include <stdbool.h>
#define STACK_SIZE	50

// Function declarations
int push (int [], int, int); // Pass the array, top (index) of stack and the maximum
int pop (int);  		// Pass top (index) of stack
int peek (int [], int);	// Array and the top (index) of stack
bool isEmpty (int);		// Top of stack
void printStack (int [], int);	// Array and top of stack

