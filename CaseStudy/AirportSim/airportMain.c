#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<string.h>
#include<ctype.h>
#include "airport.h"

int main(){
    int passw;
    printf("Enter Password for Admin Access or press 'Q' to exit:\n");
    scanf("%d",&passw);
    if(passw==121212){
        //Admin access to initialize data;
        AdminMode();
    }
    departure();
    arrival();        
    
    return 0;
}