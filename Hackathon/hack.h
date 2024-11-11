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
