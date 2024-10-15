// HEADER FILE - cs1.h

#include <stdbool.h>
#define NAMELEN 50
#define TEXTLEN 100


typedef struct node{
    char name[NAMELEN];
    char text[TEXTLEN];
    bool pinned;
    struct node *next;
} CHAT;

CHAT *AddMsg(CHAT *, char *,char *);
void DisplayChat(CHAT *, bool);
void DisplayAll(CHAT *);
void pinchat(CHAT *);
void unpinchat(CHAT *);
void FreeChat(CHAT *);