//		SLList.h
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
void DeleteAnywhere ();
void ModifyList ();
bool SearchList ();
void PrintList ();
void Quit ();
bool IsListEmpty ();
void Reverse ();