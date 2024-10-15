#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>
#include "QueueArray.h"

int main(int argc, char *argv[]){
    if (argc<2){
        printf("No arguement for queue size given.");
        exit(0);
    }
    int max = atoi(argv[1]);
    int queue[max];
    char option;
    int front,rear,data;
    int *data_store;
    data_store=&data;
    front=rear=-1;


    while(1){
        printf ("Select: E - Enqueue D - Dequeue F - Full N - Empty P - Peek Q - Quit:");
		scanf (" %c",&option);
		option = toupper (option);
		if (option == 'Q')
			break;
		switch (option){
            case 'E':
                int val;
                printf("Enter value to enqueue: ");
                scanf("%d",&val);
                Enqueue(queue,&rear,max,val);
            break;

            case 'D':
                if (Dequeue(queue,&front,&rear,max,data_store)==0) printf("%d successfully dequeued.\n",*data_store);
            break;

            case 'F':
                if (isFull(rear,max))printf("Queue is full.\n");
                else{
                    printf("Queue is not full.\n");
                }
            break;

            case 'N':
                if (isEmpty(front,rear))printf("Queue is empty.\n");
                else{
                    printf("Queue is not empty.\n");
                }
            break;

            case 'P':
                if (Peek(queue,front,rear,data_store)==0)printf("%d is at the end of the queue.\n");
            break;

            default:
                printf("Invalid arguement.\n");
            break;
        }
    }
}