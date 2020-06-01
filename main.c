#include <stdio.h>
#include "HashTable.h"

int main() {
    HashTable table;
    int a, b;
    a = 100;
    b = 51;
    HashCell cell1, cell2, *pcell1, *pcell2;
    cell1.data = &a;
    cell1.size = sizeof(a);
    cell2.data = &b;
    cell2.size = sizeof(b);
    hash_table_create(&table, 10);
    hash_table_append(&table, &cell1);
    hash_table_append(&table, &cell2);
    pcell1 = hash_table_get_item(&table, hash_table_get_key(&table, &cell1));
    pcell2 = hash_table_get_item(&table, hash_table_get_key(&table, &cell2));
    if(pcell1 != NULL) {
        printf("Cell 1 %d\n", *(int*)pcell1->data);
    }
    if(pcell2 != NULL) {
        printf("Cell 2 %d\n", *(int*)(pcell2->data));
    }
    return 0;
}