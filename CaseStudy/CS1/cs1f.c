// CHAT MESSENGER FUNCTIONS - cs1f.c

#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <stdbool.h>
#include "cs1.h"

CHAT *AddMsg(CHAT *head, char name[], char msg[]){
    CHAT *new = (CHAT*)malloc(sizeof(CHAT));
    if (new==NULL){
        printf("Memory allocation failed.\n");
        exit(1);
    }
    strcpy(new->name,name);
    strcpy(new->text,msg);
    new->pinned=false;
    if (head==NULL){
        new->next=NULL;
    }
    else{
        new->next=head;
    }
    head=new;
    return head;
}

void DisplayChat(CHAT *head, bool pin){
    CHAT *temp;
    for (temp=head; temp!=NULL;temp=temp->next)
    {
        if(temp->pinned==pin){
            printf("----------\nName: %s\nMessage: %s\n",temp->name, temp->text);
        }
    }
}

void DisplayAll(CHAT *head){
    if (head!=NULL){
        printf("Pinned Messages:\n");
        DisplayChat(head,true);
        printf("Unpinned Messages:\n");
        DisplayChat(head,false);
    }
    else{
        printf("Chat is empty.\n");
    }
}

void pinchat(CHAT *head){
    char name[NAMELEN];
    CHAT *temp=head;
    int c=0;
    printf("Enter name of the text's sender to pin: ");
    scanf(" %[^\n]s",name);
    if (temp==NULL)printf("Chat is empty.\n");
    while(temp!=NULL){
        if(strcmp(temp->name,name)==0){
            if (temp->pinned==true){
                printf("Already pinned.\n");
            }
            else{
                temp->pinned=true;
            }
            c++;
        }
        temp=temp->next;
    }
    if (c==0)printf("Could not find name/Name does not exist.\n");
}

void unpinchat(CHAT *head){
    char name[NAMELEN];
    CHAT *temp=head;
    int c=0;
    printf("Enter name of the text's sender to unpin: ");
    scanf(" %[^\n]s",name);
    if (temp==NULL)printf("Chat is empty.\n");
    while(temp!=NULL){
        if(strcmp(temp->name,name)==0){
            if (temp->pinned==false){
                printf("Already unpinned.\n");
            }
            else{
                temp->pinned=false;
            }
            c++;
        }
        temp=temp->next;
    }
    if (c==0)printf("Could not find name/Name does not exist.\n");
}

void FreeChat(CHAT *head){
    while(head!=NULL){
        CHAT *temp=head;
        head=head->next;
        free(temp);
    }
    printf("Freed the list.");
}
