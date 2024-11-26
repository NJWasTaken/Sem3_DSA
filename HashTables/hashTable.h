//			hashTable.h

#define CAPACITY 500 // Size of the HashTable.
#define MAX_LEN	100

// HashTable item.
typedef struct Ht_item
{
    char *key;
    char *value;
} HT_ITEM;

// The LinkedList.
typedef struct LinkedList
{
    HT_ITEM *item;
    struct LinkedList *next;
} LINKEDLIST;

// The HashTable.
typedef struct HashTable
{
    // Contains an array of pointers to items.
    HT_ITEM **items;
    //LINKEDLIST **overflow_buckets;
    int size;
    int count;
} HASHTABLE;

HASHTABLE *create_table(int);
void ht_insert(HASHTABLE *, char *, char *);
char *ht_search(HASHTABLE *, char *);
void ht_delete(HASHTABLE *, char *);
void print_table(HASHTABLE *);
void free_table(HASHTABLE *);


