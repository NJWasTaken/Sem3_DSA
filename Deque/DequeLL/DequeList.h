//			DequeList.h

typedef struct node
{
	int info;
	struct node *next;
} NODE;

NODE *NewNode ();
int Dequeue (NODE **, NODE **);
void Enqueue(int, NODE **, NODE **);
int DeleteLast(NODE **, NODE **);       
void InsertFirst(int item, NODE **, NODE **);
void PrintList(NODE **);

