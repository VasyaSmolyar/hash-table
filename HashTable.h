#ifndef HASH_TABLE
#define HASH_TABLE

#include <stddef.h>

typedef struct hashCell {
    size_t size;
    void* data;
    struct hashCell* next;
} HashCell;

typedef struct hashTable {
    int len;
    HashCell** array;
} HashTable;

void hash_cell_create(HashCell* self, void* data, size_t size);
int hash_cell_compare(HashCell* one, HashCell* two);

void hash_table_create(HashTable* self, int len);
int hash_table_get_key(HashTable* self, HashCell* cell);
void hash_table_append(HashTable* self, HashCell* cell);
void hash_table_delete(HashTable* self, HashCell* cell);
int hash_table_find(HashTable* self, HashCell* cell);
HashCell* hash_table_get_item(HashTable* self, int hash);

#endif