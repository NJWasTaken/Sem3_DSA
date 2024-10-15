/*				priorityq.h				*/
// Node 
typedef struct node 
{ 
    int data; 
    // Lower values indicate higher priority 
    int priority; 
    struct node* next; 
} NODE; 
  
// Function to Create A New Node 
NODE* newNode(int, int);
// Return the value at head 
int Peek(NODE**, int *, int *);
// Removes the element with the highest priority from the list 
int DeleteNode (NODE**);
  
// Function to insert according to priority 
void InsertNode (NODE**, int, int);
  
// Function to check if list is empty 
int isEmpty(NODE**);

void PrintQueue (NODE *);

void freeList (NODE **);