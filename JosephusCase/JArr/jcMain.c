#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int JosephusArray(int size, int skip){
    if (size==1) return 1;
    else{
        return (JosephusArray(size-1, skip)+skip-1)%size +1;
    }
}


int main(int argc, char **argv){
    int total, skipPos;
    if (argc<3){
        printf("Usage: %s <Total Size> <Skip Position>\n",argv[0]);
        exit(0);
    }
    total = atoi(argv[1]);
    skipPos = atoi(argv[2]);
    printf("Survivor is at position %d\n",JosephusArray(total,skipPos));
    return 0;
}