#include<stdio.h>
#include<stdlib.h>
#include <stdbool.h>
#include "Adj_Matrix_Utils.h"

static int arr[MAX][MAX];

void create_graph(int n){
    if (n>MAX){
        printf("Graph size cannot be larger than %d\n",MAX);
        exit(0);
    }
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            arr[i][j]=0;
        }
    }
}

void display (int n){
    if (n==0)printf("No nodes in the graph.\n");
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            printf("%d ",arr[i][j]);
        }
      printf("\n");  
    }
}

void insert_node (int *num){
    int n = *num;
    for (int i = 0; i < n+1; i++){
        arr[n][i]=0;
        arr[i][n]=0;
    }
    n++;
    *num = n;
}

void delete_node(int del, int *num) {
    int n = *num;
    del--;
    for (int i = del; i < n - 1; i++) {
        for (int j = 0; j < n; j++) {
            arr[i][j] = arr[i + 1][j]; 
        }
    }

    for (int i = 0; i < n - 1; i++) {
        for (int j = del; j < n - 1; j++) {
            arr[i][j] = arr[i][j + 1];  
        }
    }

    *num = n - 1;
}


bool create_edge (int a, int b, int n){
    bool ret = true;
    int a1 = a-1;
    int b1 = b-1;
    if (arr[a1][b1] == 1){
        printf("Edge already exists between node %d and %d\n",a,b);
        ret = false;
    } 
    else if (a>n||b>n||a<=0||b<=0){
        printf("Invalid node(s) entered.\n");
        ret = false;
    }
    else{
        arr[a1][b1]=1;
        arr[b1][a1]=1;
    }
    return ret;
}