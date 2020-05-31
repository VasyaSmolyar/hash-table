#include <iostream>
#include "HashTable.h"
#include "HashCell.h"

using namespace Hash;
using namespace std;

int main() {
    int a = 100;
    int b = 51;
    HashTable<int> table = HashTable<int>(10);
    table.addItem(100);
    table.addItem(51);  
    cout << table.getItem(table.getHash(a)) << endl;
    cout << table.getItem(table.getHash(b)) << endl;        
};
