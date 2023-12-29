#include "nododoublelist.h"

template <class T, class V>
NodoDoubleList<T, V>::NodoDoubleList(T key, V value) {
    this->key = key;
    this->value = value;
}

template <class T, class V>
NodoDoubleList<T, V>::NodoDoubleList() {
    key = nullptr;
    value = nullptr;
}

template <class T, class V>
void NodoDoubleList<T, V>::setKey(T key) {
    this->key = key;
}

template <class T, class V>
void NodoDoubleList<T, V>::setValue(V value) {
    this->value = value;
}

template <class T, class V>
void NodoDoubleList<T, V>::setNext(NodoDoubleList<T, V>* next) {
    this->next = next;
}

template <class T, class V>
void NodoDoubleList<T, V>::setPrev(NodoDoubleList<T, V>* prev) {
    this->prev = prev;
}

template <class T, class V>
V NodoDoubleList<T, V>::getValue(T key){
    if (this->key == key)
        return this->value;
    return nullptr;
}

template <class T, class V>
T NodoDoubleList<T, V>::getKey(){
    return this->key;
}

template <class T, class V>
NodoDoubleList<T, V>* NodoDoubleList<T, V>::getNext(){
    return this->next;
}

template <class T, class V>
NodoDoubleList<T, V>* NodoDoubleList<T, V>::getPrev() {
    return this->prev;
}

template <class T, class V>
int NodoDoubleList<T, V>::compareTo(T key) {
    if (this->key == key)
        return 0;
    else if(this->key < key)
        return -1;
    return 1;
}
