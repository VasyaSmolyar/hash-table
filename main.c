#include <stdio.h>
#include "HashTable.h"

int main() {
    HashTable table;
    HashCell cell1, cell2, *pcell1, *pcell2;
    HashCell cell3, cell4, *pcell3, *pcell4;
    int a = 100, b = 51;

    hash_cell_create(&cell1, "Hello, world!", sizeof("Hello, world!"));
    hash_cell_create(&cell2, "Goodby, world!", sizeof("Goodby, world!"));
    hash_cell_create(&cell3, &a, sizeof(a));
    hash_cell_create(&cell4, &b, sizeof(b));
    hash_table_create(&table, 3);

    hash_table_append(&table, &cell1);
    hash_table_append(&table, &cell2);
    hash_table_append(&table, &cell3);
    hash_table_append(&table, &cell4);

    pcell1 = hash_table_find(&table, &cell1);
    pcell2 = hash_table_find(&table, &cell2);
    pcell3 = hash_table_find(&table, &cell3);
    pcell4 = hash_table_find(&table, &cell4);

    if(pcell1 != NULL) {
        printf("Cell 1 %s\n", (char*)pcell1->data);
    }
    if(pcell2 != NULL) {
        printf("Cell 2 %s\n", (char*)(pcell2->data));
    }
    if(pcell3 != NULL) {
        printf("Cell 3 %d\n", *(int*)pcell3->data);
    }
    if(pcell4 != NULL) {
        printf("Cell 4 %d\n", *(int*)(pcell4->data));
    }

    hash_table_delete(&table, &cell2);
    hash_table_delete(&table, &cell4);

    return 0;
}