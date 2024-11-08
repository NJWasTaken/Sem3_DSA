#include <stdio.h> 
#include <stdlib.h> 
#include <string.h> 
#include <stdbool.h> 
#include "trie.h"

int main(int argc, char **argv) 
{ 
    char inp_str [80];
    int choice;
    int level = 0;
    TrieNODE* root = getNode(); 
  
    while (1)
    {
        printf ("\n 1 to add a key");
        printf ("\n 2 to delete a key");
        printf ("\n 3 to display all the keys");
        printf ("\n 4 to search for a key");
        printf ("\n 5 to quit the program: ");
        scanf ("%d", &choice);

        if (choice == 5)
            break;

        switch (choice)
        {
            case 1:   // Add a key
                printf ("Key in the string to be inserted:");
                scanf (" %s", inp_str);
                insert_node(root, inp_str);
            break;

            case 2:  // Delete a key
                printf ("Key in the string to remove:");
                scanf (" %s", inp_str);
                root = delete_node (root, inp_str, 0);
            break;

            case 3:  // Display all the keys
                printf ("Content of Trie:\n"); 
                display(root, inp_str, 0); 
            break;

            case 4: // Search for a key
                printf ("Key in the string to search for:");
                scanf (" %s", inp_str);
                printf ("%s......%s\n", inp_str, search(root, inp_str)? "found": "notfound");
            break;

            default:
                printf ("Incorrect choice.\n");
        }
    }
    // if (root != NULL)
    //     free_trie (root);
    return 0;
}