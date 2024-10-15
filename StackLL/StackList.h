//		StackList.h
#include <stdbool.h>

typedef struct node
{
	int data;
	struct node *next;
} NODE;

NODE *CreateNode(int);
void CreateStack (NODE **);
void push (NODE **);
void pop (NODE **);
void peek (NODE **);
void PrintStack (NODE *);
bool IsStackEmpty (NODE *);
void FreeStack (NODE **);
