#ifndef DOUBLELINKEDLIST_H
#define DOUBLELINKEDLIST_H

#include "nododoublelist.h"
#include "../BST/bst.h"

template <typename T, typename V>
class DoubleLinkedList {
public:
    DoubleLinkedList();

    void insertForward(T);
    void insertLast(T);
    void insertAfterTo(T, T);

    NodoDoubleList<T>* deleteForward();
    NodoDoubleList<T>* deleteLast();
    NodoDoubleList<T>* deleteTo(T);

    NodoDoubleList<T>* search(T dato);

    BST<T>* toBST();

    int getSize();
private:
    NodoDoubleList<T>* head;
    NodoDoubleList<T>* last;
    int contador;
};

#endif // DOUBLELINKEDLIST_H
