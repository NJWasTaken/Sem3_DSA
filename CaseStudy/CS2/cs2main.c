//cs2main.c

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "cs2.h"

int main (void){
    char choice[MAXSTRING];
    enum CmdVal ValCmd;
    int retval;
    bool go_on = true;
    char m_cmd[10];
    char m_arg[10];
    M_FILESYSTEM *fs_head;
    M_DIR *cur;

    fs_head = Allocate_fs("root");
    cur = fs_head->root;
    
    printf("---------------------------\nWelcome to the File System\n---------------------------\n");
    while(go_on){
        m_arg[0]=0;
        printf("\n---------------------------\ncd <dirname>\ntouch <filename>\nmkdir <dirname>\nls\nexit\n---------------------------\n>>> ");
        scanf(" %[^\n]s",choice);
        sscanf(choice,"%s%s",m_cmd,m_arg);
        ValCmd = ValidateCmd(m_cmd);

        switch(ValCmd){
            case CD_CMD:
                if (m_arg[0]!=0){
                    if (strcmp(m_arg,"..")==0){
                        if (cur==fs_head->root)printf("Already at root.\n");
                        else{
                            cur = cur->parent;
                        }
                    }
                    else{
                        M_DIR *temp = cur;
                        if (cur==fs_head->root){
                            cur = ChangeDir(fs_head,m_arg);
                            if (cur==NULL){
                                printf("Directory does not exist.\n");
                                cur = temp;
                            }
                        }
                        else{
                            printf("Directory does not exist.\n");
                        }
                    }
                    printf("Current working directory: %s\n",cur->dirName);
                }
                else{
                    printf("Syntax: cd <dirname>\n");
                }
            break;

            case MKDIR_CMD:
                if (m_arg[0]!=0){
                    retval = MakeDir(cur, m_arg);
                    if (retval==0)printf("New directory %s created under %s.\n",m_arg,cur->dirName);
                }
                else{
                    printf("Syntax: mkdir <dirname>\n");
                }
            break;

            case LS_CMD:
                ShowFiles(fs_head);
            break;

            case TOUCH_CMD:
                if (m_arg[0]!=0){
                    retval = CreateFile(cur, m_arg);
                    if (retval==0)printf("New file %s created under %s.\n",m_arg,cur->dirName);
                }
                else{
                    printf("Syntax: touch <filename>\n");
                }
            break;

            case EXIT_CMD:
                printf("Exiting...\n");
                go_on=false;
            break;

            default:
                printf("Unsupported command.\n");
            break;
        }
    }
    free_mem(fs_head);
    return 0;
}