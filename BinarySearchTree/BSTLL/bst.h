//			BST_Implement.h

typedef struct node 
{
  	int val; 		  //node will store some data
  	struct node *right; // right child
  	struct node *left;  // left child
} NODE;

//function to create a node
NODE* new_node(int);
// searching operation
NODE* search(NODE*, int) ;
// insertion
NODE* insert(NODE*, int);
//function to find the minimum value in a node
NODE* find_minimum(NODE*) ;
// deletion
NODE* delete(NODE*, int);
// Traverse and print inorder
void inorder (NODE *);
 