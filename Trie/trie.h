#include <stdbool.h>
// Alphabet size (# of symbols) 
#define ALPHABET_SIZE 26 
  
// Converts key current character into index use only 'a' through 'z' and lower case 
#define CHAR_TO_INDEX(c) ((int)c - (int)'a') 
  
// Trie node 
typedef struct TrieNode 
{ 
    struct TrieNode *children[ALPHABET_SIZE]; 
  
    // isEndOfWord is true if the node represents end of a word 
    bool isEndOfWord; 
} TrieNODE; 
  

TrieNODE *getNode(void) ;
// function to check if current node is leaf node or not 
bool isLeafNode(TrieNODE* ) ;
  
// function to display the content of Trie 
void display(TrieNODE* , char *, int ) ;
   
// If not present, inserts key into trie If the key is prefix of trie node, just marks leaf node 
void insert_node(TrieNODE *, const char *) ;
  
// Returns true if key present in trie, else false 
bool search(TrieNODE *, const char *) ;

// Returns true if root has no children, else false 
bool isEmpty(TrieNODE* ) ;
  
// Recursive function to delete a key from given Trie 
TrieNODE* delete_node(TrieNODE*, char *, int) ;

// Free the memory allocated to the trie data structure
void free_trie (TrieNODE *);