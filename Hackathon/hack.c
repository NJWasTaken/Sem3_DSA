#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "hack.h"

ZONE* newZone(int resources) {
    ZONE* head = (ZONE*)malloc(sizeof(ZONE));
    if (!head) return NULL;
    
    head->priority = 0;
    head->resources = resources;
    head->name = 0;
    head->population = 0;
    head->next = NULL;
    head->people = NULL;
    return head;
}

ZONE* enqueueZone(ZONE *head) {
    ZONE* new_zone = (ZONE*)malloc(sizeof(ZONE));
    if (!new_zone) return NULL;
    
    printf("Enter zone number: ");
    scanf("%d", &new_zone->name);
    printf("Enter zone priority (1-5): ");
    scanf("%d", &new_zone->priority);
    while (new_zone->priority < 1 || new_zone->priority > 5) {
        printf("Invalid priority. Enter priority (1-5): ");
        scanf("%d", &new_zone->priority);
    }
    
    printf("Enter number of people in zone: ");
    scanf("%d", &new_zone->population);
    
    new_zone->people = NULL;
    new_zone->resources = 0;
    
    // Add people to the zone
    for (int i = 0; i < new_zone->population; i++) {
        PERSON* new_person = (PERSON*)malloc(sizeof(PERSON));
        printf("Enter name of person %d: ", i + 1);
        scanf("%s", new_person->name);
        new_person->rescued = false;
        new_person->next = new_zone->people;
        new_zone->people = new_person;
    }
    
    // Add zone to the list (sorted by priority)
    if (!head || head->priority > new_zone->priority) {
        new_zone->next = head;
        return new_zone;
    }
    
    ZONE* current = head;
    while (current->next && current->next->priority <= new_zone->priority) {
        current = current->next;
    }
    new_zone->next = current->next;
    current->next = new_zone;
    return head;
}

void allocate(ZONE* zone) {
    if (!zone) {
        printf("No zones available.\n");
        return;
    }
    
    int total_resources = zone->resources;
    ZONE* current = zone->next;  // Skip head node which stores total resources
    int total_priority_sum = 0;
    
    // Calculate sum of priorities
    while (current) {
        total_priority_sum += (6 - current->priority);  // Invert priority so lower numbers get more resources
        current = current->next;
    }
    
    // Allocate resources based on priority
    current = zone->next;
    while (current) {
        current->resources = (total_resources * (6 - current->priority)) / total_priority_sum;
        printf("Zone %d allocated %d resources\n", current->name, current->resources);
        current = current->next;
    }
}

RESCUED* rescue(ZONE* zone, RESCUED* resq) {
    if (!zone || !zone->next) {
        printf("No zones available.\n");
        return resq;
    }
    
    // Find highest priority zone with resources
    ZONE* current = zone->next;
    ZONE* best_zone = NULL;
    
    while (current) {
        if (current->resources > 0 && current->population > 0) {
            if (!best_zone || current->priority < best_zone->priority) {
                best_zone = current;
            }
        }
        current = current->next;
    }
    
    if (!best_zone) {
        printf("No zones available for rescue operations.\n");
        return resq;
    }
    
    // Rescue people from the chosen zone
    PERSON* person = best_zone->people;
    while (person && best_zone->resources > 0) {
        if (!person->rescued) {
            person->rescued = true;
            best_zone->population--;
            
            // Add to rescued queue
            RESCUED* new_rescued = (RESCUED*)malloc(sizeof(RESCUED));
            new_rescued->person = person;
            new_rescued->rank = best_zone->priority;
            new_rescued->next = NULL;
            
            // Add to end of rescued queue
            if (!resq) {
                resq = new_rescued;
            } else {
                RESCUED* curr = resq;
                while (curr->next) {
                    curr = curr->next;
                }
                curr->next = new_rescued;
            }
            
            printf("Rescued %s from Zone %d\n", person->name, best_zone->name);
        }
        person = person->next;
    }
    return resq;
}

void printZones(ZONE* zone) {
    if (!zone || !zone->next) {
        printf("No zones available.\n");
        return;
    }
    
    ZONE* current = zone->next;  // Skip head node
    printf("\nZone Status:\n");
    printf("Zone\tPriority\tResources\tPopulation\n");
    while (current) {
        printf("%d\t%d\t\t%d\t\t%d\n", 
               current->name, 
               current->priority, 
               current->resources, 
               current->population);
        current = current->next;
    }
}

void printRescued(RESCUED* resq) {
    if (!resq) {
        printf("No people have been rescued yet.\n");
        return;
    }
    
    printf("\nRescued People:\n");
    printf("Name\t\tPriority\n");
    RESCUED* current = resq;
    while (current) {
        printf("%s\t\t%d\n", current->person->name, current->rank);
        current = current->next;
    }
}

void freeAll(ZONE* zone, RESCUED* resq) {
    // Free zones and people
    while (zone) {
        ZONE* next_zone = zone->next;
        PERSON* person = zone->people;
        while (person) {
            PERSON* next_person = person->next;
            free(person);
            person = next_person;
        }
        free(zone);
        zone = next_zone;
    }
    
    // Free rescued queue
    while (resq) {
        RESCUED* next = resq->next;
        free(resq);
        resq = next;
    }
}