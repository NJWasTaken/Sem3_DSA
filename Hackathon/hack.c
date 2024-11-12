#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "hack.h"

ZONE* newZone(int resources){
    ZONE* head = (ZONE*)malloc(sizeof(ZONE));
    if(!head) return NULL;
    
    head->priority = 0;
    head->resources = resources;
    head->name = 0;
    head->population = 0;
    head->next = NULL;
    head->people = NULL;
    return head;
}

bool dupeName(int n, ZONE* zone){
    bool flag = false;
    ZONE* node=zone;
    while(node!=NULL){
        if (n==node->name){
            flag = true;
        }
        node=node->next;
    }
    return flag;
}

ZONE* enqueueZone(ZONE *head){
    ZONE* new_zone = (ZONE*)malloc(sizeof(ZONE));
    if(!new_zone) return NULL;
    
    while(1){
        printf("Enter zone number: ");
        scanf("%d", &new_zone->name);
        if (dupeName(new_zone->name,head))printf("Zone already exists.\n");
        else break;
    }
    printf("Enter zone priority (1-5): ");
    scanf("%d", &new_zone->priority);
    while(new_zone->priority<1 || new_zone->priority> 5){
        printf("Invalid priority. Enter priority (1-5): ");
        scanf("%d", &new_zone->priority);
    }
    
    printf("Enter number of people in zone: ");
    scanf("%d", &new_zone->population);
    
    new_zone->people = NULL;
    new_zone->resources = 0;
    
    // Add people to the zone
    for(int i = 0; i < new_zone->population; i++){
        PERSON* new_person = (PERSON*)malloc(sizeof(PERSON));
        printf("Enter name of person %d: ", i + 1);
        scanf("%s", new_person->name);
        new_person->rescued = false;
        new_person->next = new_zone->people;
        new_zone->people = new_person;
    }
    
    // Add zone to the list
    if(!head || head->priority > new_zone->priority){
        new_zone->next = head;
        return new_zone;
    }
    
    ZONE* current = head;
    while(current->next && current->next->priority <= new_zone->priority){
        current = current->next;
    }
    new_zone->next = current->next;
    current->next = new_zone;
    return head;
}

void allocate(ZONE* zone){
    if(!zone){
        printf("No zones available.\n");
        return;
    }
    
    int total_resources = zone->resources;
    ZONE* current = zone->next;  
    int total_priority_sum = 0;
    
    while(current){
        total_priority_sum += (6 - current->priority);  
        current = current->next;
    }
    
    current = zone->next;
    while(current){
        current->resources = (total_resources*(6 - current->priority))/total_priority_sum;
        printf("Zone %d allocated %d resources\n", current->name, current->resources);
        current = current->next;
    }
}

//Rescuing <limit> number of ppl from each zone based on priority
RESCUED* rescue(ZONE* zone, RESCUED* resq, int limit){ 
    int count = 1;
    if(!zone || !zone->next){
        printf("No zones available.\n");
        return resq;
    }

    ZONE* current = zone->next; // start from the first thing
    int rescued_count;
    bool rescue_available = true;

    while(rescue_available){
        rescue_available = false; // reset the flag
        current = zone->next; // start from the first zone again
        while(current){
            if(current->resources > 0 && current->population > 0){
                rescue_available = true; 

                // rescue up to the "limit"
                rescued_count = 0;
                PERSON* person = current->people;
                while(person && rescued_count < limit && current->resources > 0){
                    if(!person->rescued){
                        person->rescued = true; // mark person as rescued
                        current->resources--;   
                        current->population--;  // update other stuff
                        rescued_count++;

                        // add the person to the rescue list
                        RESCUED* new_rescued = (RESCUED*)malloc(sizeof(RESCUED));
                        new_rescued->person = person;
                        new_rescued->rank = count;
                        count++;
                        new_rescued->next = resq;
                        resq = new_rescued;

                        printf("Rescued %s from Zone %d\n", person->name, current->name);
                    }
                    person = person->next;
                }
            }
            current = current->next; // move to the next zone
        }
    }
    return resq;
}


void printZones(ZONE* zone){
    if(!zone || !zone->next){
        printf("No zones available.\n");
        return;
    }
    
    ZONE* current = zone->next; 
    printf("\nZone Status:\n");
    printf("Zone\tPriority\tResources\tPopulation\n");
    while(current){
        printf("%d\t%d\t\t%d\t\t%d\n", 
               current->name, 
               current->priority, 
               current->resources, 
               current->population);
        current = current->next;
    }
}

void printRescued(RESCUED* resq){
    if(!resq) {
        printf("No people have been rescued yet.\n");
        return;
    }
    
    printf("\nRescued People:\n");
    printf("Name\tOrder of Rescue\n");
    RESCUED* current = resq;
    while (current){
        printf("%s\t\t%d\n", current->person->name, current->rank);
        current = current->next;
    }
}

void freeAll(ZONE* zone, RESCUED* resq){
    while(zone){
        ZONE* next_zone = zone->next;
        PERSON* person = zone->people;
        while(person){
            PERSON* next_person = person->next;
            free(person);
            person = next_person;
        }
        free(zone);
        zone = next_zone;
    }
    
    while(resq){
        RESCUED* next = resq->next;
        free(resq);
        resq = next;
    }
}