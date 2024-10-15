//		CircularList.h
#include <stdbool.h>
typedef struct node
{
	int data;
	struct node *next;
} NODE;

void CreateList ();
void InsertAtBeginning ();
void InsertAtEnd ();
void InsertAnywhere ();
void DeleteFirstNode ();
void DeleteLastNode ();
void DeleteAnyNode ();
void ModifyList ();
bool SearchList ();
void PrintList ();
bool IsListEmpty ();
void FreeList ();
void Navigate();