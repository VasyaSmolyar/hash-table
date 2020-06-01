#ifndef HASH_TABLE
#define HASH_TABLE

#include <stddef.h>

typedef struct hashCell {
    size_t size;
    void* data;
} HashCell;

typedef struct hashTable {
    int len;
    HashCell** array;
} HashTable;

void hash_table_create(HashTable* self, int len);
int hash_table_get_key(HashTable* self, HashCell* cell);
void hash_table_append(HashTable* self, HashCell* cell);
void hash_table_delete(HashTable* self, HashCell* cell);
int hash_table_find(HashTable* self, HashCell* cell);
HashCell* hash_table_get_item(HashTable* self, int hash);

#endif