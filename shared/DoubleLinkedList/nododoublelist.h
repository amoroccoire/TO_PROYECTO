#ifndef NODODOUBLELIST_H
#define NODODOUBLELIST_H

#pragma once

template <class T, class V>
class NodoDoubleList {
public:
    NodoDoubleList();
    NodoDoubleList(T, V);

    void setKey(T);
    void setValue(V);
    void setNext(NodoDoubleList<T, V>*);
    void setPrev(NodoDoubleList<T, V>*);

    T getKey();
    V getValue(T);
    NodoDoubleList<T, V>* getNext();
    NodoDoubleList<T, V>* getPrev();

    int compareTo(T);

private:
    NodoDoubleList<T, V>* next;
    NodoDoubleList<T, V>* prev;
    T key;
    V value;
};

#endif // NODODOUBLELIST_H
