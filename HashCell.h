#ifndef HASH_CELL
#define HASH_CELL
namespace Hash {
template <typename T>
    class HashCell {
        int key;
        T value;
        T* next;
    public:
        HashCell(int, T);
        T getValue();
        void setValue(T);
        int getKey();
        void setKey(int);
    };

    template <class T>
    HashCell<T>::HashCell(int key, T value) {
        this->key = key;
        this->value = value;
        this->next = nullptr;
    }

    template <typename T>
    int HashCell<T>::getKey() {
        return this->key;
    }

    template <typename T>
    void HashCell<T>::setKey(int key) {
        this->key = key;
    }

    template <typename T>
    T HashCell<T>::getValue() {
        return this->value;
    }

    template <typename T>
    void HashCell<T>::setValue(T value) {
        this->value = value;
    }
}
#endif