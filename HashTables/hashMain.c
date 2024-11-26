//			hashTableMain.c

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "hashTable.h"

int main(int argc, char **argv) 
{
    char key[MAX_LEN], value [MAX_LEN];
    char choice;
    char *sVal;
    bool go_on = true;
            
    HASHTABLE *ht = create_table(CAPACITY);
    while (go_on) 
    {
        printf("i - Insert an item\n");
        printf("d - Delete an item\n");
        printf("s - Search for an item\n");
        printf("p - Display all items\n");
        printf("q - Quit\n");
        printf("Enter your choice : ");
        scanf(" %c", &choice);
        switch (choice) 
        {
            case 'i':	// Insert an item
                // Accept key and value from the user
                printf ("Enter the key value:");
                scanf (" %s", key);
                printf ("Enter the value:");
                scanf (" %s", value);
                ht_insert(ht, key, value);
            break;
            case 'd':	// Delete an item
                printf("Enter a key to be deleted : ");
		        scanf ("%s", key);
                ht_delete (ht, key);
            break;
            case 's':	// Search for an item
                printf("Enter the search key : ");
                scanf ("%s", key);
                sVal = ht_search (ht, key);
                if (sVal != NULL)
                    printf ("The value corresponding to %s is %s\n", key, sVal);
                else
                    printf ("The key %s does not exist in the table\n", key);
            break;
            case 'p':	// Display all items
                print_table (ht);
            break;

            case 'q':
            	go_on = false;
	        break;
            default:
                printf("Wrong choice\n");
            break;
        }
    }
    return 0;
 }



/*
int main()
{
    HashTable *ht = create_table(CAPACITY);
    ht_insert(ht, (char *)"1", (char *)"First address");
    ht_insert(ht, (char *)"2", (char *)"Second address");
    ht_insert(ht, (char *)"Hel", (char *)"Third address");
    ht_insert(ht, (char *)"Cau", (char *)"Fourth address");
    print_search(ht, (char *)"1");
    print_search(ht, (char *)"2");
    print_search(ht, (char *)"3");
    print_search(ht, (char *)"Hel");
    print_search(ht, (char *)"Cau"); // Collision!
    print_table(ht);
    ht_delete(ht, (char *)"1");
    ht_delete(ht, (char *)"Cau");
    print_table(ht);
    free_table(ht);
    return 0;
}
*/
