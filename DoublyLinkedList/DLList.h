//		DLList.h
#include <stdbool.h>
typedef struct node
{
	int data;
	struct node *next;
	struct node *prev;
} NODE;

//void DisplayNode (NODE *);
void CreateList ();
void InsertAtBeginning ();
void InsertAtEnd ();
void InsertAnywhere ();
void DeleteFirstNode ();
void DeleteLastNode ();
void DeleteAnyNode ();
void NavigateList ();
void ModifyList ();
bool SearchList ();
void PrintList ();
void ReversePrint ();
bool IsListEmpty ();
void FreeList ();