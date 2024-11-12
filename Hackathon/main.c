#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h> 
#include <ctype.h>
#include "hack.h"

int main(){
    printf("^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\nWelcome to ROS! (Rescue Operating System)\nby SegFault: Paranshu, Vivian, Prateek & Noel.\nThis program aims to efficiently manage resources and people amongst disaster zones.\n^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n");
    int resources;
    while(1){
        printf("Enter total number of resources available: ");
        int res = scanf("%d",&resources);
        if (res!=1 || resources<0){
            printf("Invalid entry.\n");
            int ch;
            while ((ch = getchar()) != '\n' && ch != EOF);
        }
        else break;
    }
    
    ZONE *zone = newZone(resources);
    RESCUED *resq = NULL;
    char option;
    
    while(1){
        printf("----------------------------------------\nAdd new zone - Z\nAllocate resources to zones - A\nRescue people - P\nDisplay - D\nQuit - Q\n----------------------------------------\nEnter option: ");
        scanf(" %c", &option);
        option = toupper(option);
        if (option=='Q'){
            remainingPpl(zone);
            freeAll(zone, resq);
            break;
        }
        switch(option){
            case 'Z':
                zone = enqueueZone(zone);
            break;

            case 'A':
                allocate(zone);
            break;

            case 'P':
                int limit;
                while(1){
                    printf("Set rescue limit: ");
                    int res = scanf("%d",&limit);
                    if (res!=1 || limit<0){
                        printf("Invalid entry.\n");
                        int ch;
                        while ((ch = getchar()) != '\n' && ch != EOF);
                    }
                    else break;
                }

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
    return 0;
}