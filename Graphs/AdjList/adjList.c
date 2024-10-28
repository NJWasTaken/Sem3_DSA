#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "adjList.h"

// A utility function to create a new adjacency list node
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

// A utility function that creates a graph of V vertices
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

// Adds an edge to an undirected graph
void addEdge(GRAPH *graph, int src, int dst, int v){
    if (src>0&&src<=v && dst>0&&src<=v){
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

// A utility function to print the adjacency list representation of graph
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

void free_mem (GRAPH *graph){
    for (int i = 0; i < graph->V; i++)
    {
        for (ADJLISTNODE *node = graph->array[i].head; node != NULL; node = node->next)
        {
            ADJLISTNODE *temp = node;
            free(temp);
        }
        free(graph->array);
        free(graph);
    }
}