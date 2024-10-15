#include <stdbool.h>
#define namelen 100

typedef struct flight FLIGHT;
typedef struct luggage LUGGAGE;
typedef struct passenger PASSENGER;

typedef struct passenger{
    char name[namelen];
    int pnr;
    char email[namelen];
    int age;
    int gateno;
    int priority;
    FLIGHT* flight;
    LUGGAGE* luggage;
    PASSENGER *next;
} PASSENGER;

typedef struct flight{
    char flightno[namelen];
    char company[namelen];
    int status;
    int gateno;
    char to[namelen];
    char from[namelen];
    FLIGHT *next;
    FLIGHT *prev;
    PASSENGER *passenger;
} FLIGHT;

typedef struct luggage{
    float weight;
    PASSENGER *passenger;
    FLIGHT *flight;
    LUGGAGE *next;
} LUGGAGE;

void departure();
void arrival();
FLIGHT* FindFlight(int);
void DisplayPassengers();
void CreatePassengerQueue(int);
void AdminMode();
void DisplayFlights();
FLIGHT* CreateFlight();
PASSENGER *CreatePassenger();
LUGGAGE *CreateBag();
