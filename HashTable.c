#include "HashTable.h"
#include <stdlib.h>
#include <stddef.h>

void hash_cell_create(HashCell* self, void* data, size_t size) {
    self->data = data;
    self->size = size;
    self->next = NULL;
}

void hash_table_create(HashTable* self, int len) {
    int i;
    self->len = len;
    self->array = malloc(sizeof(HashCell*) * len);
    for(i = 0; i < len; i++) {
        self->array[i] = NULL;
    }
}

int hash_table_get_key(HashTable* self, HashCell* cell) {
    int i, sum;
    char* p;
    for(i = 0, sum = 0, p = (char*)cell->data; i < cell->size; i++, p++) {
        sum += (int)*p;
    }
    return sum % self->len;
}

void hash_table_append(HashTable* self, HashCell* cell) {
    int hash;
    hash = hash_table_get_key(self, cell);
    if(self->array[hash] == NULL) {
        self->array[hash] = cell;
    } else {
        //TODO: реализовать сохранение в цепочке
    }
}

HashCell* hash_table_get_item(HashTable* self, int hash) {
    return self->array[hash];
}