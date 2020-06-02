#include "HashTable.h"
#include <stdlib.h>
#include <stddef.h>

void hash_cell_create(HashCell* self, void* data, size_t size) {
    self->data = data;
    self->size = size;
    self->next = NULL;
}

int hash_cell_compare(HashCell* one, HashCell* two) {
    int i;
    char* data1, *data2;
    if(one->size != two->size) {
        return 0;
    }
    data1 = one->data;
    data2 = two->data;
    for(i = 0;i < one->size; i++) {
        if (data1[i] != data2[i]) {
            return 0;
        } 
    }
    return 1;
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
    HashCell* next;
    hash = hash_table_get_key(self, cell);
    if(self->array[hash] == NULL) {
        self->array[hash] = cell;
    } else {
        next = self->array[hash];
        while(next->next != NULL) {
            next = next->next;
        }
        next->next = malloc(sizeof(HashCell));
        *(next->next) = *cell;
    }
}

int hash_table_find(HashTable* self, HashCell* cell) {
    int hash, res, found;
    HashCell* next;
    hash = hash_table_get_key(self, cell);
    if(self->array[hash] == NULL) {
        return 0;
    }
    for(res = 1, found = 0, next = self->array[hash]; next != NULL; res++, next = next->next) {
        if(hash_cell_compare(next, cell)) {
            found = 1;
            break;
        }
    }
    return found == 1 ? res : 0;
}

HashCell* hash_table_get_item(HashTable* self, int hash) {
    return self->array[hash];
}