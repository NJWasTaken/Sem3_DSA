// A C Program to demonstrate adjacency list representation of graphs
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct AdjListNode 
{
    int dest;
    struct AdjListNode* next;
} ADJLISTNODE;
 
typedef struct AdjList 
{
    ADJLISTNODE *head; // pointer to head node of list
} ADJLIST;
 
typedef struct Graph 
{
    int V;
    ADJLIST* array;
} GRAPH;

ADJLISTNODE* newAdjListNode(int val){
    ADJLISTNODE* node;
    if ((node = (ADJLISTNODE*)malloc(sizeof(ADJLISTNODE)))==NULL){
        printf("Memory allocation unavailable.\n");
        exit(0);
    }
    node->dest=val;
    node->next=NULL;

    return node;
}

GRAPH* createGraph(int v){
    GRAPH *graph;
    if ((graph = (GRAPH*)malloc(sizeof(GRAPH)))==NULL){
        printf("Memory allocation unavailable.\n");
        exit(0);
    }
    graph->V = v;
    
    if ((graph->array = (ADJLIST*)malloc(v * sizeof(ADJLIST))) == NULL) {
        printf("Memory allocation unavailable.\n");
        exit(0);
    }
    
    for (int i = 0; i < v; i++) {
        graph->array[i].head = NULL; 
    }

    return graph;
}

void addEdge(GRAPH *graph, int src, int dst, int v){

    if (src>0&&src<=v && dst>0&&dst<=v){
        ADJLISTNODE *node1 = newAdjListNode(dst-1);
        node1->next = graph->array[src-1].head;
        graph->array[src-1].head = node1;

        ADJLISTNODE *node2 = newAdjListNode(src-1);
        node2->next = graph->array[dst-1].head;
        graph->array[dst-1].head = node2;
    }
    else{
        printf("Invalid source and destination values.\n");
    }
}

void dfsUtil(GRAPH *graph, int node, int endnode, int visited[], int path[], int index) {
    visited[node] = 1;
    path[index] = node;
    index++;

    if (node == endnode) {
        for (int i = 0; i < index; i++) {
            printf("%d ", path[i] + 1);
        }
        printf("\n");

    } 
    else {
        for (ADJLISTNODE *adj = graph->array[node].head; adj != NULL; adj = adj->next) {
            if (!visited[adj->dest]) {
                dfsUtil(graph, adj->dest, endnode, visited, path, index);
            }
        }
    }

    visited[node] = 0;
}

void dfs(GRAPH *graph, int start, int stop) {
    int size = graph->V;
    int visited[size];
    int path[size];
    for (int i = 0; i < size; i++) {
        visited[i] = 0;  
    }

    printf("DFS Paths from node %d to %d:\n",start,stop);
    dfsUtil(graph, start-1, stop-1, visited, path, 0);  
}

void printGraph(GRAPH *graph){
    int size = graph->V;
    for (int i = 0; i < size; i++)
    {
        printf("%d -> ",i+1);
        for (ADJLISTNODE *node = graph->array[i].head; node != NULL; node = node->next)
        {
            printf("%d ",node->dest+1);
        }
        printf("\n");
    }
}

void free_mem(GRAPH *graph) {
    for (int i = 0; i < graph->V; i++) {
        ADJLISTNODE *node = graph->array[i].head;
        while (node != NULL) {
            ADJLISTNODE *temp = node;
            node = node->next;
            free(temp);
        }
    }
    free(graph->array);
    free(graph);
}

int main(int argc, char **argv) 
{
    int num_nodes, srceNode, destNode;
    char choice;
    bool goOn = true;
                
    if (argc < 2)
    {
        printf ("Usage: %s <Num of nodes>\n", argv[0]);
        exit (1);
    }
    
    num_nodes = atoi (argv [1]);
    GRAPH* graph = createGraph(num_nodes);
    while (goOn)
    {
        printf ("Enter: \n c - create edge\n d - display\n q - quit: ");
        scanf (" %c", &choice);
        switch (choice)
        {
            case 'c':		// Create an edge
                printf ("Source vertex: ");
                scanf ("%d", &srceNode);
                printf ("Destination vertex: ");
                scanf ("%d", &destNode);
                addEdge (graph, srceNode, destNode, num_nodes);
            break;

            case 'd':		// Display the adj list
                char op;
                printf("BFS - b | DFS - d: ");
                scanf(" %c",&op);
                if(op=='b')
                printGraph (graph);
                else if(op=='d'){
                    int start,stop;
                    printf("Enter start node: ");
                    scanf("%d",&start);
                    printf("Enter stop node: ");
                    scanf("%d",&stop);
                    if (start>0&&start<=graph->V && stop>0&&stop<=graph->V)
                        dfs(graph,start,stop);
                    else
                        printf("Invalid node options.\n");
                }
                else
                printf("Invalid option.\n");
            break;

            case 'q':
                goOn = false;
            break;
            default:
                printf ("Unknown command.\n");
        }
    }
    free_mem (graph);
    return 0;
}
