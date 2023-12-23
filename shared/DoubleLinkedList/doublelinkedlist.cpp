#include "doublelinkedlist.h"
#include "cmath"

template <class T>
DoubleLinkedList<T>::DoubleLinkedList() {
    head = nullptr;
    last = nullptr;
    contador = 0;
}

template <class T>
void DoubleLinkedList<T>::insertForward(T dato) {
    NodoDoubleList<T>* newNodo = new NodoDoubleList<T>(dato);

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

template <class T>
void DoubleLinkedList<T>::insertLast(T dato) {
    NodoDoubleList<T>* newNodo = new NodoDoubleList<T>(dato);

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

template <class T>
void DoubleLinkedList<T>::insertAfterTo(T exist, T dato) {
    NodoDoubleList<T>* newNodo = new NodoDoubleList<T>(dato);

    NodoDoubleList<T>* nodo = search(exist);
    if (nodo == last)
        insertLast(dato);

    else if (nodo){
        nodo->getNext()->setPrev(newNodo);
        newNodo->setNext(nodo->getNext());
        newNodo->setPrev(nodo);
        nodo->setNext(newNodo);
        contador++;
    }

}

template <class T>
NodoDoubleList<T>* DoubleLinkedList<T>::deleteForward() {
    NodoDoubleList<T>* aux;
    if (head != nullptr){
        aux = head;
        head = head->getNext();
        head->setPrev(nullptr);
        aux->setNext(nullptr);
        contador--;
    }
    return aux;
}

template <class T>
NodoDoubleList<T>* DoubleLinkedList<T>::deleteLast() {
    NodoDoubleList<T>* aux;
    if (last != nullptr){
        aux = last;
        last = last->getPrev();
        last->setNext(nullptr);
        aux->setPrev(nullptr);
        contador--;
    }
    return aux;
}

template <class T>
NodoDoubleList<T>* DoubleLinkedList<T>::deleteTo(T dato) {
    NodoDoubleList<T>* nodoDeleted = search(dato);

    if (nodoDeleted)
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

template <class T>
NodoDoubleList<T>* DoubleLinkedList<T>::search(T dato) {
    NodoDoubleList<T>* aux = head;
    NodoDoubleList<T>* aux2 = last;

    float limite = (float)ceil(contador / 2.0);
    int result1 , result2;
    for (int i = 0; i < limite; i++) {
        result1 = aux->compareTo(dato);
        result2 = aux2->compareTo(dato);
        if (result1 == 0)
            return aux;
        else if (result2 == 0)
            return aux2;
        aux = aux->getNext();
        aux2 = aux2->getPrev();
    }
    return nullptr;
}

template <class T>
int DoubleLinkedList<T>::getSize() {
    return contador;
}

template <class T>
BST<T>* DoubleLinkedList<T>::toBST() {
    BST<T>* bst = new BST<T>();

    NodoDoubleList<T>* aux = head;

    while (aux != nullptr){
        bst->insert(aux->getDato());
        aux = aux->getNext();
    }

    return bst;
}
