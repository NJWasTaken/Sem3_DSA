#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAXSIZE 100


int right(int arr[], int n){
    int res;
    int size = sizeof(arr)/sizeof(arr[1]);
    if (arr[0]=='\0') res = 2*n+1;
    else {res=2*n+2;}
    if (res>=size) {
        printf("Child doesn't exist.");
        res=-1;
    }
    return res;
}

int left(int arr[], int n){
    int res;
    int size = sizeof(arr)/sizeof(arr[1]);
    if (arr[0]=='\0') res = 2*n;
    else {res=2*n+1;}
    if (res>=size) {
        printf("Child doesn't exist.");
        res=-1;
    }
    return res;
}

void postorder(){

}

void preorder(int tree[]){
    int i;
    if (tree[0]=='\0')i=1;
    else{i=0;}

    while(right(tree,i)!=-1 && left(tree,i)!=-1){
        printf("%d ",tree[i]);
        if (left(tree,i)==-1){
            i=(i-1)/2;
            i = right(tree, i);
        }

    }
}

