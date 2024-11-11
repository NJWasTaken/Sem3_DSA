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
    int population;
    struct zone *next;
    PERSON *people;
} ZONE;

typedef struct rescued{
    PERSON *person;
    int rank;
    struct rescued *next;
} RESCUED;

ZONE* newZone(int);
ZONE* enqueueZone(ZONE *);
void allocate(ZONE* );
RESCUED* rescue(ZONE*,RESCUED*);
void printZones(ZONE*);
void printRescued(RESCUED*);
void freeAll(ZONE*, RESCUED*);