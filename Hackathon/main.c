#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h> 
#include "hack.h"

int main(){
    int resources;
    printf("Enter total number of resources: ");
    scanf("%d",&resources);
    ZONE *zone = newZone(resources);
    RESCUED *resq = NULL;
    char option;
    
    while(1){
        printf("----------------------------------------\nAdd new zone - Z\nAllocate resources to zones - A\nRescue people - P\nDisplay - D\n----------------------------------------\nEnter option: ");
        scanf(" %c", &option);
        option = toupper(option);
        switch(option){
            case 'Z':
                zone = enqueueZone();
            break;

            case 'A':
                allocate(zone);
            break;

            case 'P':
                rescue(zone, resq);
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