// cs2.c

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "cs2.h"

static CMDVAL s_cmds [] = {{"cd",CD_CMD},{"mkdir",MKDIR_CMD},{"ls",LS_CMD},{"touch",TOUCH_CMD},{"exit",EXIT_CMD},{NULL,INVALID_CMD}};

int ValidateCmd(char *m_cmd){
    int i;
    for(i=0; s_cmds[i].cmd!=NULL;i++){
        if (strcmp(m_cmd,s_cmds[i].cmd)==0)break;
    }
    return (s_cmds[i].val);
}

bool CheckDupe(M_DIR *p_dir, char *dirname){
    bool retval = false;
    M_DIR *temp;
    for(temp=p_dir; temp!=NULL; temp=temp->next){
        if (strcmp(temp->dirName,dirname)==0){
            retval = true;
            break;
        }
    }
    return retval;
}

bool CheckDupeFile(MYFILE *p_dir, char *filename){
    bool retval = false;
    MYFILE *temp;
    for(temp=p_dir; temp!=NULL; temp=temp->next){
        if (strcmp(temp->filename,filename)==0){
            retval = true;
            break;
        }
    }
    return retval;
}

void InitDirName(M_DIR *p_mdir, char *dirname){
    if((p_mdir->dirName = (char*)malloc(strlen(dirname)+1))==NULL){
        perror("Memory allocation failed in InitDirName.\n");
        exit(0);
    }
    strcpy(p_mdir->dirName,dirname);
}

void AddSibling(M_DIR *cur, M_DIR *new){
    M_DIR *p_cur, *p_prev;
    for (p_cur = cur; p_cur!=NULL; p_prev = p_cur, p_cur = p_cur->next);
    p_prev->next = new;   
}

M_DIR *ChangeDir(M_FILESYSTEM* p_fs, char* dirname){
    M_DIR *p_dir;
    for (p_dir=p_fs->root->subdir; p_dir!=NULL;p_dir=p_dir->next){
        if (strcmp(dirname, p_dir->dirName)==0) break;
    }
    return p_dir;
}


M_DIR *Allocate_dir(char *dirname,M_DIR *parent){
    M_DIR *p_mdir;
    if ((p_mdir=(M_DIR*)malloc(sizeof(M_DIR)))==NULL){
        perror("Memory allocation failed.\n");
        exit(0);
    }
    p_mdir->subdir=NULL;
    p_mdir->next=NULL;
    p_mdir->files=NULL;
    p_mdir->parent=parent;
    InitDirName(p_mdir,dirname);
    return p_mdir;
}

M_FILESYSTEM *Allocate_fs(char *dirname){
    M_FILESYSTEM *p_mfs;
    if((p_mfs = (M_FILESYSTEM*)malloc(sizeof(M_FILESYSTEM)))==NULL){
        perror("Memory allocation failed in Allocate_fs.\n");
        exit(0);
    }
    p_mfs->root = Allocate_dir(dirname,NULL);
    return p_mfs;
}


int MakeDir(M_DIR *cur,char *dirname){
    M_DIR *p_mdir;
    int retval=0;
    if (cur->parent != NULL){
        retval=-1;
        printf("No subdirectory system implemented in this version.\n");
    }
    else{
        if (!CheckDupe(cur->subdir,dirname)){
            if ((p_mdir = (M_DIR*)malloc(sizeof(M_DIR)))==NULL){
                perror("Memory allocation failed in MakeDir.\n");
                exit(0);
            }
            p_mdir->parent = cur;
            InitDirName(p_mdir,dirname);
            if(cur->subdir==NULL)cur->subdir=p_mdir;
            else{
                AddSibling(cur->subdir,p_mdir);
                p_mdir->next=NULL;
                p_mdir->files=NULL;
            }
        }
        else{
            retval=-1;
            printf("No duplicate names allowed.\n");
        }
    }
    return retval;
}

void ShowFiles (M_FILESYSTEM *p_fs){
    M_DIR *p_mdir;
    M_DIR *p_temp;
    MYFILE *p_mfile; 
    if(p_fs!=NULL){
        p_mdir = p_fs->root;
        printf("%s\n", p_mdir->dirName);
        p_mdir = p_mdir->subdir;

        if(p_mdir!=NULL){
            printf("\t%s",p_mdir->dirName);
            for(p_temp = p_mdir->next; p_temp!=NULL;p_temp=p_temp->next)printf("\t%s",p_temp->dirName);

            printf("\n");
            p_mdir = p_fs->root;

            if(p_mdir!=NULL){
                for (p_mfile = p_mdir->files; p_mfile!=NULL; p_mfile = p_mfile->next) printf("%s\n",p_mfile->filename);
            }

            p_mdir = p_fs->root->subdir;

            for(p_temp=p_mdir; p_temp!=NULL; p_temp = p_temp->next){
                printf("Directory: %s\n", p_temp->dirName);
                for(p_mfile=p_temp->files; p_mfile!=NULL; p_mfile=p_mfile->next) printf("%s\t",p_mfile->filename);
                printf("\n");
            }
            printf("\n");
        }
    }
}

int CreateFile(M_DIR *cur, char *filename){
    MYFILE *p_myfile;
    MYFILE *p_temp, *p_prev;
    int len = strlen(filename)+1;
    int retval=0;

    if (!CheckDupeFile(cur->files,filename)){
        if ((p_myfile = (MYFILE*)malloc(sizeof(MYFILE)))==NULL){
            perror("Memory allocation failed in CreateFile.\n");
            exit(0);
        }
        p_myfile->next = NULL;

        if(cur->files==NULL){
            cur->files=p_myfile;
            if ((cur->files->filename = malloc(len))==NULL){
                printf("Memory allocation failed in CreateFile.\n");
                exit(0);
            }
            strcpy(cur->files->filename,filename);
        }
        else{
            for (p_temp = cur->files; p_temp!=NULL; p_prev = p_temp, p_temp = p_temp->next);
            p_prev->next = p_myfile;
            if ((p_prev->next->filename = (char *)malloc(len))==NULL){
                printf("Memory allocation failed in CreateFile.\n");
                exit(0);
            }
            strcpy(p_prev->next->filename,filename);
        }
    }
    else{
        retval=-1;
        printf("No duplicate names allowed.\n");
    }
    return retval;
}

void free_mem(M_FILESYSTEM *p_fs){
    M_DIR *cur_d, *temp_d;
    MYFILE *cur_f, *temp_f;
    cur_d = p_fs->root;
    temp_d = cur_d;
    cur_f = cur_d->files;

    while (cur_f!=NULL){
        temp_f = cur_f;
        cur_f=cur_f->next;
        //printf("Freed %s\n",temp_f->filename); //debug
        free(temp_f);
    }

    cur_d=cur_d->subdir;
    free(temp_d);
    //printf("Freed root\n"); //debug

    while(cur_d!=NULL){
        cur_f = cur_d->files;
        while (cur_f!=NULL){
            temp_f = cur_f;
            cur_f=cur_f->next;
            //printf("Freed %s\n",temp_f->filename); //debug
            free(temp_f);
        }
        temp_d = cur_d;
        cur_d = cur_d->next;
        //printf("Freed %s\n",temp_d->dirName); //debug
        free(temp_d);
    }
}