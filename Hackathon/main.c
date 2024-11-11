#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h> 
#include <ctype.h>
#include "hack.h"

int main(){
    int resources;
    printf("Enter total number of resources: ");
    scanf("%d",&resources);
    ZONE *zone = newZone(resources);
    RESCUED *resq = NULL;
    char option;
    
    while(1){
        printf("----------------------------------------\nAdd new zone - Z\nAllocate resources to zones - A\nRescue people - P\nDisplay - D\nQuit - Q\n----------------------------------------\nEnter option: ");
        scanf(" %c", &option);
        option = toupper(option);
        if (option=='Q')break;
        switch(option){
            case 'Z':
                zone = enqueueZone(zone);
            break;

            case 'A':
                allocate(zone);
            break;

            case 'P':
                int limit;
                printf("Set rescue limit: ");
                scanf("%d",&limit);
                resq = rescue(zone, resq, limit);
            break;

            case 'D':
                printf("Display: Zones - Z | Rescued people - R: ");
                char op;
                scanf(" %c",&op);
                op = toupper(op);
                if (op=='Z')printZones(zone);
                else if (op=='R')printRescued(resq);
                else printf("Invalid option.\n");
            break;

            default:
                printf("Invalid option.\n");
            break;
        }
    }
    freeAll(zone, resq);
    return 0;
}