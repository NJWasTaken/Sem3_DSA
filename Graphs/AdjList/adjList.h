// A structure to represent an adjacency list node
typedef struct AdjListNode 
{
    int dest;
    struct AdjListNode* next;
} ADJLISTNODE;
 
// A structure to represent an adjacency list
typedef struct AdjList 
{
    ADJLISTNODE *head; // pointer to head node of list
} ADJLIST;
 
// A structure to represent a graph. A graph is an array of adjacency lists.
// Size of array will be V (number of vertices in graph)
typedef struct Graph 
{
    int V;
    ADJLIST* array;
} GRAPH;

// A utility function to create a new adjacency list node
ADJLISTNODE* newAdjListNode(int);
// A utility function that creates a graph of V vertices
GRAPH* createGraph(int);
// Adds an edge to an undirected graph
void addEdge(GRAPH *, int, int, int);
// A utility function to print the adjacency list representation of graph
void printGraph(GRAPH *);

void free_mem (GRAPH *);