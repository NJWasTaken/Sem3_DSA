#include <stdio.h>
#include "StackOps.h"
#include <stdbool.h>

int push(int stack[], int top, int size){
    int val;
    printf("Enter value to be added to the stack: ");
    scanf("%d",&val);
    if (top+1>size) printf("Stack Overflow Error.\n");
    else{
        stack[top+1]=val;
        top++;
    }
    return top;    
}

int pop(int top){
    if(top==-1)printf("Stack Underflow Error.\n");
    else{top--;}
    return top;
}

int peek(int stack[], int top){
    if (top==-1){
        printf("Stack Underflow Error.\n");
        return 0;
    }
    else{
        printf("Value at the top: %d\n",stack[top]);
        return stack[top];
    }
}

bool isEmpty(int top){
    if(top==-1)return true;
    else{
        return false;
    }
}

void printStack(int stack[], int top){
    if (top==-1)printf("Stack is empty.\n");
    else{
        for (int i = 0; i <= top; i++)
        {
            printf("%d ",stack[i]);
        }
        printf("\n");
    }
}