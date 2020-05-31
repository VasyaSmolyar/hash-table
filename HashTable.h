#ifndef HASH_TABLE
#define HASH_TABLE
#include "HashCell.h"
#include "HashTable.h"
#include <cstddef>
#include <cstdlib>

namespace Hash{
    template<class T>
        class HashTable {
            HashCell<T>* array;
            int len;
        public:
            HashTable(int);
            int getHash(T);
            void addItem(T);
            void deleteItem(T);
            T getItem(int);
            bool findItem(int);
        };


    template <class T>
    HashTable<T>::HashTable(int len) {
        this->len = len;
        this->array = (HashCell<T>*)malloc(sizeof(HashTable<T>)*len);
        /*
        for(int i = 0; i < len; i++) {
            this.array[i] = nullptr;
        }
        */
    }

    template <class T>
    int HashTable<T>::getHash(T item) {
        int hash = 0;
        unsigned char const *p = reinterpret_cast<unsigned char const*>(&item);
        for(size_t i = 0; i < sizeof(p); i++) {
            hash += (int)p[i];
        }
        return hash % this->len;
    }

    template <class T>
    void HashTable<T>::addItem(T item) {
        int hash = this->getHash(item);
        if(true) {
            array[hash] = HashCell<T>(hash, item);
        } else {
            //TODO: реализовать сохранение в цепочке
        }
    }

    template <class T>
    T HashTable<T>::getItem(int hash) {
        return array[hash].getValue();
    }

}
#endif