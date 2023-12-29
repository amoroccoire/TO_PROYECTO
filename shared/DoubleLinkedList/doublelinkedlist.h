#ifndef DOUBLELINKEDLIST_H
#define DOUBLELINKEDLIST_H

#include "nododoublelist.h"

template <class T, class V>
class DoubleLinkedList {
public:
    DoubleLinkedList();

    void insertForward(T, V);
    void insertLast(T, V);
    void insertAfterTo(T, T, V);

    NodoDoubleList<T, V>* deleteForward();
    NodoDoubleList<T, V>* deleteLast();
    NodoDoubleList<T, V>* deleteTo(T);

    NodoDoubleList<T, V>* search(T dato);

    int getSize();
    NodoDoubleList<T, V>* getHead();
    NodoDoubleList<T, V>* getLast();

private:
    NodoDoubleList<T, V>* head;
    NodoDoubleList<T, V>* last;
    int contador;
};

#endif // DOUBLELINKEDLIST_H
