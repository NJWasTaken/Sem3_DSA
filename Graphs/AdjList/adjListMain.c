// A C Program to demonstrate adjacency list representation of graphs
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "adjList.h"
 
int main(int argc, char **argv) 
{
    // create the graph given in above figure
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
                printGraph (graph);
            break;

            case 'q':
                goOn = false;
            break;
            default:
                printf ("Unknown command\n");
        }
    }
    free_mem (graph);
    return 0;
}