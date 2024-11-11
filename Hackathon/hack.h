#include <stdbool.h>

typedef struct person{
    char name[20];
    bool rescued;
    struct person *next;
} PERSON;

typedef struct zone{
    int priority;
    int resources;
    int name;
    struct zone *next;
    PERSON *people;
} ZONE;

typedef struct rescued{
    PERSON *person;
    int rank;
    RESCUED *next;
} RESCUED;

ZONE *create_zone(int priority, int resources, int name);
void add_person_to_zone(ZONE *zone, char *name);
ZONE *get_high_priority_zone(ZONE *head);
void distribute_supplies(ZONE *zone);
bool rescue_person(ZONE *zone, char *name);
void add_to_rescued_tree(RESCUED **root, PERSON *person, int rank);
PERSON *search_rescued(RESCUED *root, char *name);
void free_rescue_mission(ZONE *zones, RESCUED *rescued);