// MAIN CHAT MESSENGER PROGRAM - casestudy1.c

#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <stdbool.h>
#include "cs1.h"

int main() {
    CHAT* head = NULL;
    char name[NAMELEN], msg[TEXTLEN];
    int out=0;
    while(out==0){
        int option;
        printf("***********************************\nYOUR CHAT MESSENGER\n***********************************\nPick your action:\nTo DISPLAY all chats enter - 0\nTo ADD a chat enter - 1\nTo PIN a chat print - 2\nTo UNPIN a chat enter - 3\nTo QUIT enter - 4\nEnter option: ");
        scanf("%d",&option);
        switch(option)
        {
        case 0:
            DisplayAll(head);
        break;
        
        case 1:
            printf("Enter name: ");
            scanf(" %[^\n]s",name);
            printf("Enter text: ");
            scanf(" %[^\n]s",msg);
            head = AddMsg(head,name,msg);
        break;

        case 2:
            pinchat(head);
        break;

        case 3:
            unpinchat(head);
        break;
        
        case 4:
            out=1;
        break;

        default:
            break;
        }
    }
    FreeChat(head);
    return 0;
}
