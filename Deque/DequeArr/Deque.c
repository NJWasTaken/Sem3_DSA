#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include "DequeFunctions.h"

void addFront(int arr[], int data, int *front, int *rear, int size) {
    int f = *front;
    int r = *rear;
    if ((f == r && f == (size-1)/2) || (r == size/2 && f == (size/2) - 1)) { // Deque is empty
        arr[f] = data;
        f--;
        r++;
    } else if (f == -1 && r == size-1) {
        printf("Queue Overflow.\n");
    } else if (f == -1) {
        for (int i = size-1; i > 0; i--) {
            arr[i] = arr[i-1];
        }
        arr[0] = data;
        f = 0;
        r++;
    } else {
        arr[f] = data;
        f--;
    }
    *front = f;
    *rear = r;
}

void addRear(int arr[], int data, int *front, int *rear, int size) {
    int f = *front;
    int r = *rear;
    if ((f == r && f == (size-1)/2) || (r == size/2 && f == (size/2) - 1)) {
        addFront(arr, data, front, rear, size);
    } else if (f == -1 && r == size-1) {
        printf("Queue Overflow.\n");
    } else if (r == size-1) {
        for (int i = 0; i < size-1; i++) {
            arr[i] = arr[i+1];
        }
        arr[r] = data;
        f--;
    } else {
        arr[r] = data;
        r++;
    }
    *front = f;
    *rear = r;
}

int delFront(int arr[], int *front, int *rear) {
    int f = *front;
    if (f == *rear) {
        printf("Deque is empty.\n");
        return INT_MAX;
    }
    f++;
    int a = arr[f];
    arr[f] = INT_MAX;
    *front = f;
    return a;
}

int delRear(int arr[], int *front, int *rear) {
    int r = *rear;
    if (r == *front) {
        printf("Deque is empty.\n");
        return INT_MAX;
    }
    r--;
    int b = arr[r];
    arr[r] = INT_MAX;
    *rear = r;
    return b;
}

void display(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        if (arr[i] != INT_MAX) printf("%d ", arr[i]);
    }
    printf("\n");
}
