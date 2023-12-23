#include "nododoublelist.h"

template <class T>
NodoDoubleList<T>::NodoDoubleList() {
    dato = nullptr;
}

template <class T>
NodoDoubleList<T>::NodoDoubleList(T dato) {
    this->dato = dato;
}

template <class T>
void NodoDoubleList<T>::setDato(T dato) {
    this->dato = dato;
}


template <class T>
void NodoDoubleList<T>::setNext(NodoDoubleList<T>* next) {
    this->next = next;
}

template <class T>
void NodoDoubleList<T>::setPrev(NodoDoubleList<T>* prev) {
    this->prev = prev;
}

template <class T>
T NodoDoubleList<T>::getDato(){
    return this->dato;
}

template <class T>
NodoDoubleList<T>* NodoDoubleList<T>::getNext(){
    return this->next;
}

template <class T>
NodoDoubleList<T>* NodoDoubleList<T>::getPrev() {
    return this->prev;
}

template <class T>
int NodoDoubleList<T>::compareTo(T dato) {
    if (this->dato == dato)
        return 0;
    else if(this->dato < dato)
        return -1;
    return 1;
}

