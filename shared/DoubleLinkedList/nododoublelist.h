#ifndef NODODOUBLELIST_H
#define NODODOUBLELIST_H

template <typename T>
class NodoDoubleList {
public:
    NodoDoubleList();
    NodoDoubleList(T dato);

    void setDato(T dato);
    void setNext(NodoDoubleList<T>*);
    void setPrev(NodoDoubleList<T>*);

    T getDato();
    NodoDoubleList<T>* getNext();
    NodoDoubleList<T>* getPrev();

    int compareTo(T);

private:
    NodoDoubleList<T>* next;
    NodoDoubleList<T>* prev;
    T dato;
};

#endif // NODODOUBLELIST_H
