#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "hashTable.h"

HASHTABLE *create_table(int size){
    HASHTABLE *ht = (HASHTABLE*)malloc(sizeof(HASHTABLE));
    if(ht==NULL){
        printf("Memory allocation failed.\n");
        exit(0);
    }
 
    ht->size=size;
    ht->count=0;
    ht->items = (HT_ITEM**)calloc(size, sizeof(HT_ITEM*));
    if (ht->items == NULL){
        printf("Memory allocation failed.\n");
        exit(2);
    }
    for (int i = 0; i < size; i++){
        ht->items[i]=NULL;
    }

    return ht;
}

int hash(char* key, int size){
    int sum = 0;
    while(*key){
        int a = *key;
        sum += a;
        key++;
    }
    return sum%size;
}

void ht_insert(HASHTABLE *ht, char *key, char *value){
    HT_ITEM *new = (HT_ITEM*)malloc(sizeof(HT_ITEM));
    if (new==NULL){
        printf("Memory allocation failed.\n");
        exit(1);
    }
    strcpy(new->key,key);
    strcpy(new->value,value);
    ht->count++;
    ht->items[hash(key,ht->size)] = new;
}

char *ht_search(HASHTABLE *ht, char *key){
    if (ht->items[hash(key,ht->size)]==NULL){
        return NULL;
    }
    else return ht->items[hash(key,ht->size)]->value;
}

void ht_delete(HASHTABLE *ht, char *key){
    int i = hash(key,ht->size);
    HT_ITEM *temp = ht->items[i];
    printf("Deleted key %s with value %s",temp->key,temp->value);
    free(temp);
    ht->items[i] = NULL;
    ht->count--;
}

void print_table(HASHTABLE *ht){
    int c = 0;

    if (ht->count>1){
        printf("INDEX\t\tKEY\t\tVALUE\n");
        for (int i = 0; i < ht->size; i++){
            HT_ITEM *item = ht->items[i];
            if(item != NULL){
                printf("%d\t\t%s\t\t%s\n",i,item->key,item->value);
                c++;
            }

            if (c==ht->count)break;
        }   
    }
    else printf("Hashtable is empty.\n");
}

void free_table(HASHTABLE *ht){
    int c = 0;
    for (int i = 0; i < ht->size; i++){
        HT_ITEM *item = ht->items[i];
        if(item != NULL){
            free(item->key);
            free(item->value);
            free(item);
        }

        if (c==ht->count)break;
    }   
    free(ht);
}