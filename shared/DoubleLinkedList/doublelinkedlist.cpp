#include "doublelinkedlist.h"
#include "cmath"

template <class T, class V>
DoubleLinkedList<T, V>::DoubleLinkedList() {
    head = nullptr;
    last = nullptr;
    contador = 0;
}

template <class T, class V>
void DoubleLinkedList<T, V>::insertForward(T key, V value) {
    NodoDoubleList<T, V>* newNodo = new NodoDoubleList<T, V>(key, value);

    if(head == nullptr){
        head = newNodo;
        last = newNodo;
    }
    else {
        head->setPrev(newNodo);
        newNodo->setNext(head);
        head = newNodo;
    }
    contador++;

}

template <class T, class V>
void DoubleLinkedList<T, V>::insertLast(T key, V value) {
    NodoDoubleList<T, V>* newNodo = new NodoDoubleList<T, V>(key, value);

    if(last == nullptr){
        head = newNodo;
        last = newNodo;
    }
    else {
        last->setNext(newNodo);
        newNodo->setPrev(last);
        last = newNodo;
    }
    contador++;
}

template <class T, class V>
void DoubleLinkedList<T, V>::insertAfterTo(T exist, T key, V value) {
    NodoDoubleList<T, V>* newNodo = new NodoDoubleList<T, V>(key, value);

    NodoDoubleList<T, V>* nodo = search(exist);
    if (nodo == last)
        insertLast(key, value);
    else if (nodo){
        nodo->getNext()->setPrev(newNodo);
        newNodo->setNext(nodo->getNext());
        newNodo->setPrev(nodo);
        nodo->setNext(newNodo);
        contador++;
    }

}

template <class T, class V>
NodoDoubleList<T, V>* DoubleLinkedList<T, V>::deleteForward() {
    NodoDoubleList<T, V>* aux;
    if (head != nullptr){
        aux = head;
        head = head->getNext();
        head->setPrev(nullptr);
        aux->setNext(nullptr);
        contador--;
    }
    return aux;
}

template <class T, class V>
NodoDoubleList<T, V>* DoubleLinkedList<T, V>::deleteLast() {
    NodoDoubleList<T, V>* aux;
    if (last != nullptr){
        aux = last;
        last = last->getPrev();
        last->setNext(nullptr);
        aux->setPrev(nullptr);
        contador--;
    }
    return aux;
}

template <class T, class V>
NodoDoubleList<T, V>* DoubleLinkedList<T, V>::deleteTo(T key) {
    NodoDoubleList<T, V>* nodoDeleted = search(key);

    if (nodoDeleted == last)
        deleteLast();
    else if (nodoDeleted == head)
        deleteForward();
    else if (nodoDeleted) {
        nodoDeleted->getPrev()->setNext(nodoDeleted->getNext());
        nodoDeleted->getNext()->setPrev(nodoDeleted->getPrev());
        nodoDeleted->setNext(nullptr);
        nodoDeleted->setPrev(nullptr);
        contador--;
    }
    return nodoDeleted;
}

template <class T, class V>
NodoDoubleList<T, V>* DoubleLinkedList<T, V>::search(T key) {
    NodoDoubleList<T, V>* aux = head;
    NodoDoubleList<T, V>* aux2 = last;

    float limite = (float)ceil(contador / 2.0);
    int result1 , result2;
    for (int i = 0; i < limite; i++) {
        result1 = aux->compareTo(key);
        result2 = aux2->compareTo(key);
        if (result1 == 0)
            return aux;
        else if (result2 == 0)
            return aux2;
        aux = aux->getNext();
        aux2 = aux2->getPrev();
    }
    return nullptr;
}

template <class T, class V>
int DoubleLinkedList<T, V>::getSize() {
    return contador;
}
