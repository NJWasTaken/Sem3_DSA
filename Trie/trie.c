#include <stdio.h> 
#include <stdlib.h> 
#include <string.h> 
#include <stdbool.h> 
#include "trie.h"
 
// Returns new trie node (initialized to NULLs) 
TrieNODE *getNode(void) 
{ 
    TrieNODE *pNode = NULL; 
  
    pNode = (TrieNODE *)malloc(sizeof(TrieNODE)); 
  
    if (pNode) 
    { 
        int i; 
        pNode->isEndOfWord = false; 
        for (i = 0; i < ALPHABET_SIZE; i++) 
            pNode->children[i] = NULL; 
    } 
  
    return pNode; 
} 

// function to check if current node is leaf node or not 
bool isLeafNode(TrieNODE* root) 
{ 
    return root->isEndOfWord != false; 
} 
  
// function to display the content of Trie 
void display(TrieNODE* root, char str[], int level) 
{ 
    printf ("level is %d str is %s\n", level, str);

    // If node is leaf node, it indicates end of string, so a null character 
    // is added and string is displayed 
    if (isLeafNode(root))  
    { 
        str[level] = '\0'; 
        printf ("%s\n", str);
    } 
  
    int i; 
    for (i = 0; i < ALPHABET_SIZE; i++)  
    { 
        // if NON NULL child is found;  add parent key to str and 
        // call the display function recursively for child node 
        if (root->children[i])  
        { 
            str[level] = i + 'a'; 
            display(root->children[i], str, level + 1); 
        } 
    } 
} 
   
// If not present, inserts key into trie If the key is prefix of 
// trie node, just marks leaf node 
void insert_node(TrieNODE *root, const char *key) 
{ 
    int level; 
    int length = strlen(key); 
    int index; 
  
    struct TrieNode *pCrawl = root; 
  
    for (level = 0; level < length; level++) 
    { 
        index = CHAR_TO_INDEX(key[level]); 
        if (!pCrawl->children[index]) 
            pCrawl->children[index] = getNode(); 
  
        pCrawl = pCrawl->children[index]; 
    } 
  
    // mark last node as leaf 
    pCrawl->isEndOfWord = true; 
} 
  
// Returns true if key presents in trie, else false 
bool search(TrieNODE *root, const char *key) 
{ 
    int level; 
    int length = strlen(key); 
    int index; 
    TrieNODE *pNavigate = root; 
  
    for (level = 0; level < length; level++) 
    { 
        index = CHAR_TO_INDEX(key[level]); 
  
        if (!pNavigate->children[index]) 
            return false; 
  
        pNavigate = pNavigate->children[index]; 
    } 
  
    return (pNavigate != NULL && pNavigate->isEndOfWord); 
} 

// Returns true if root has no children, else false 
bool isEmpty(TrieNODE* root) 
{ 
    for (int i = 0; i < ALPHABET_SIZE; i++) 
        if (root->children[i]) 
            return false; 
    return true; 
} 
  
// Recursive function to delete a key from given Trie 
TrieNODE* delete_node(TrieNODE* root, char *key, int depth){ 
    // If tree is empty 
    if (!root) 
        return NULL; 
    // If last character of key is being processed 
    if (depth == strlen (key)) 
    { 
        // This node is no more end of word after removal of given key 
        if (root->isEndOfWord) 
            root->isEndOfWord = false; 
  
        // If given word is not prefix of any other word 
        if (isEmpty(root)) 
        { 
            free (root); 
        } 
        return root; 
    } 
    // If not last character, recur for the child obtained using ASCII value 
    int index = key[depth] - 'a'; 
    root->children[index] = delete_node(root->children[index], key, depth + 1); 
    // If root does not have any child (its only child got deleted), and it 
    // is not end of another word. 
    if (isEmpty(root) && root->isEndOfWord == false) 
    { 
        free (root); 
        root = NULL; 
    } 
    return root; 
} 

// Free all the memory allocated to Trie
void free_trie (TrieNODE *root)
{
    int i;
    if(!root) 
        return;   // safe guard including root node. 

    // recursive case (go to end of trie)
    for (i = 0; i < ALPHABET_SIZE; i++)
       free_trie(root->children[i]);

    // base case
    free(root);
}