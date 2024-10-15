//		CircularList2.h
#include <stdbool.h>

typedef struct node
{
	int data;
	struct node *next;
	struct node *prev;
} NODE;

void CreateList (NODE **, NODE **);
void InsertAtBeginning (NODE **, NODE **);
void InsertAtEnd (NODE **, NODE **);
void InsertAnywhere (NODE **, NODE **);
void DeleteFirstNode (NODE **, NODE **);
void DeleteLastNode (NODE **, NODE **);
void DeleteAnyNode (NODE **, NODE **);
void ModifyList (NODE *);
bool SearchList (NODE *);
void PrintList (NODE **);
bool IsListEmpty (NODE *);
void FreeList (NODE **);
void Navigate (NODE *, NODE *);
void ReversePrint (NODE **);