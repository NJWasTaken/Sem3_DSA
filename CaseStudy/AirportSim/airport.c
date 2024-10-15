#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>
#include "airport.h"

static PASSENGER *passenger_head;
static FLIGHT *flight_head;
static FLIGHT *flight_tail;

PASSENGER *CreatePassenger(){
    PASSENGER *new=(PASSENGER*)malloc(sizeof(PASSENGER));
    if (new==NULL){
        printf("Memory not avalable to allocate.\n");
        exit(0);
    }
    
    printf("Enter your name: ");
    scanf(" %[^\n]s",new->name);

    printf("Enter your age: ");
    scanf("%d",&new->age);

    printf("Enter your PNR: ");
    scanf("%d",&new->pnr);

    printf("Enter your email ID: ");
    scanf(" %[^\n]s",new->email);

    printf("Enter your flight's gate number: ");
    scanf("%d",&new->gateno);
    
    while(1){
        printf("Which seat type are you in? F : First Class | B : Business | E : Economy ");
        char op;
        scanf(" %c",&op);
        op = toupper(op);
        if (op=='F'){new->priority=1;break;}
        else if(op=='B'){new->priority=2;break;}
        else if(op=='E'){new->priority=3;break;}
        else{printf("Invalid input.\n");}
    }

    int num;
    
    FLIGHT *plane;
    plane=FindFlight(new->gateno);
    new->flight=plane;
    plane->passenger=new;
    new->next=NULL;

    printf("How many luggages do you have?\n");
    scanf("%d",&num);
    LUGGAGE *prev = NULL;
    for (int i = 0; i < num; i++) {
        LUGGAGE *node = CreateBag();
        if (i == 0) {
            new->luggage = node;
        } else {
            prev->next = node;
        }
        prev = node;
        node->flight = plane;
        node->passenger = new;
    }
    printf("\n-------------------\n");
    return new;
}

LUGGAGE*CreateBag(){
    LUGGAGE *node=(LUGGAGE*)malloc(sizeof(LUGGAGE));
    if (node==NULL){
        printf("Could not allocate memory for LUGGAGE");
        exit(0);
    }
    printf("Enter weight of your luggage in kg: ");
    scanf("%f",&node->weight);
    node->flight=NULL;
    node->passenger=NULL;
    node->next=NULL;

    return node;
}

FLIGHT* CreateFlight(){
    FLIGHT *p_flight=(FLIGHT*)malloc(sizeof(FLIGHT));
    if(p_flight==NULL){
        printf("Could not allocate memory for FLIGHT\n");
        exit(0);
    }
    printf("Enter Flight Number: ");
    scanf(" %[^\n]s",p_flight->flightno);
    
    printf("Enter Airline: ");
    scanf(" %[^\n]s",p_flight->company);

    printf("Enter Status of Flight \n(0 - Early , 1 - On-Time , 2 - Delayed): ");
    scanf("%d",&p_flight->status);

    printf("Enter Gate Number: ");
    scanf("%d",&p_flight->gateno);

    printf("Enter Source of Flight: ");
    scanf(" %[^\n]s",p_flight->from);

    printf("Enter Destination of Flight:& ");
    scanf(" %[^\n]s",p_flight->to);

    p_flight->next=NULL;
    p_flight->prev=NULL;
    printf("\n-------------------\n");
    return p_flight;
}

void DisplayFlights(){
    FLIGHT * f_temp = flight_head;
    printf("Available flights:\n");
    while (f_temp!=flight_tail)
    {
        printf("%s\n",f_temp->flightno);
        f_temp=f_temp->next;
    }
    
}

void AdminMode(){
    FLIGHT* f_head = flight_head;
    int m,n;
    printf("Enter number of flights: ");
    scanf("%d",&n);
    for (int i = 0; i < n; i ++)
	{
		FLIGHT *node = CreateFlight();
		if (f_head == NULL)
			flight_head = flight_tail = node;
		else
		{
            FLIGHT *p_temp = flight_tail;
			flight_tail -> next = node;
			flight_tail = node;
            flight_tail -> prev = p_temp;
			flight_tail -> next = flight_head;
            flight_head -> prev = flight_tail;
		}
	}

    DisplayFlights();
    
    PASSENGER* p_head = passenger_head;
    printf("Enter number of passengers: ");
    scanf("%d",&m);
    CreatePassengerQueue(m);
    DisplayPassengers();

    printf("Exiting admin mode...\n");
}

void CreatePassengerQueue(int m){
    PASSENGER* node = passenger_head;
    for (int i = 0; i < m; i++)
    {
        PASSENGER* new = CreatePassenger();
        if (node==NULL){
            node=passenger_head=new;
        }
        node->next=new;
        node=new;
    }
}

void DisplayPassengers(){
    printf("First Class:");
    for (PASSENGER* node = passenger_head; node!=NULL; node=node->next)
    {
        if (node->priority==1){
            printf("\n%s\n%s\n",node->name,node->email);
        }
    }
    
    printf("Business Class:");
    for (PASSENGER* node = passenger_head; node!=NULL; node=node->next)
    {
        if (node->priority==2){
            printf("\n%s\n%s\n",node->name,node->email);
        }
    }

    printf("Economy Class:");
    for (PASSENGER* node = passenger_head; node!=NULL; node=node->next)
    {
        if (node->priority==3){
            printf("\n%s\n%s\n",node->name,node->email);
        }
    }
    printf("----------------------------------------------\n");
}

FLIGHT* FindFlight(int gateno){
    FLIGHT *p_temp=flight_head;
    while (p_temp != flight_tail) {
        if (p_temp->gateno == gateno) {
            return p_temp;
        }
        p_temp = p_temp->next;
    }
}

void departure()
{   
    printf("departure fn\n");
}

void arrival(){
    printf("arrival fn\n");
}