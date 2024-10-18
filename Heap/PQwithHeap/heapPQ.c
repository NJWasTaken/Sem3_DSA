#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <stdbool.h>
#define MAXSIZE 100

struct Heap{
    int arr[MAXSIZE];
    int size;
};

void MaxHeapify(struct Heap *heap, int i) {
    int big = i;
    int l = 2*i;  
    int r = 2*i + 1; 

    if (l <= heap->size && heap->arr[l] > heap->arr[big])
        big = l;


    if (r <= heap->size && heap->arr[r] > heap->arr[big])
        big = r;

    if (big != i) {
        int temp = heap->arr[i];
        heap->arr[i] = heap->arr[big];
        heap->arr[big] = temp;
        MaxHeapify(heap, big);
    }
}

void Dequeue(struct Heap *heap){
    if (heap->size == 0) {
        printf("Priority Queue is empty!\n");
        return;
    }
    printf("Dequeued %d\n", heap->arr[1]);
    int num = heap->arr[heap->size]; 
    heap->arr[1] = num; 
    heap->size--; 
    MaxHeapify(heap, 1); 
}

void Enqueue(struct Heap *heap, int num) {
    if (heap->size == MAXSIZE) {
        printf("Priority Queue is full.\n");
        return;
    }

    heap->size++; 
    heap->arr[heap->size] = num;  
    int i = heap->size;


    while (i > 1 && heap->arr[i / 2] < heap->arr[i]) {
        int temp = heap->arr[i];
        heap->arr[i] = heap->arr[i / 2];
        heap->arr[i / 2] = temp;
        i = i / 2;
    }
}

void PrintHeap(struct Heap *heap) {
    if (heap->size == 0) {
        printf("Priority Queue is empty.\n");
        return;
    }
    for (int i = 1; i <= heap->size; i++) {
        printf("%d ", heap->arr[i]);
    }
    printf("\n");
}

int main() {
    struct Heap *heap = (struct Heap*) malloc(sizeof(struct Heap));
    heap->size = 0;

    int n;
    printf("Enter number of nodes: ");
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        int value;
        printf("Enter value: ");
        scanf("%d", &value);
        Enqueue(heap, value);
    }

    while (1) {
        char c;
        printf("Enter option: Print - P | Enqueue - I | Dequeue - D | Quit - Q: ");
        scanf(" %c", &c);
        c = toupper(c);
        if (c == 'Q') break;
        switch (c) {
            case 'P':
                PrintHeap(heap);
                break;
            
            case 'I': {
                int num;
                printf("Enter value to insert: ");
                scanf("%d", &num);
                Enqueue(heap, num);
                break;
            }
            
            case 'D':
                Dequeue(heap);
                break;

            default:
                printf("Invalid option.\n");
                break;
        }
    }
    free(heap->arr);
    free(heap);
    return 0;
}
