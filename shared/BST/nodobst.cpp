#include "nodobst.h"

template <class T>
NodoBST<T>::NodoBST(){

}

template <class T>
NodoBST<T>::NodoBST(T dato) {
    this->dato = dato;
}

template <class T>
void NodoBST<T>::setDato(T dato) {
    this->dato = dato;
}

template <class T>
T NodoBST<T>::getDato() {
    return this->dato;
}

template <class T>
void NodoBST<T>::setIzq(NodoBST<T>* izq) {
    this->izq = izq;
}

template <class T>
NodoBST<T>* NodoBST<T>::getIzq() {
    return this->izq;
}

template <class T>
void NodoBST<T>::setDer(NodoBST<T>* der) {
    this->der = der;
}

template <class T>
NodoBST<T>* NodoBST<T>::getDer() {
    return this->der;
}

template <class T>
int NodoBST<T>::compareTo(T dat) {

    if (this->dato == dat)
        return 0;
    else if (this->dato < dat)
        return -1;
    return 1;
}
