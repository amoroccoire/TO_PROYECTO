#include "bst.h"

template <class T>
BST<T>::BST() {
    raiz = nullptr;
}

template <class T>
BST<T>::BST(T dato) {
    this->raiz = new NodoBST<T>(dato);
}

template <class T>
NodoBST<T>* BST<T>::insert(T dato) {
    NodoBST<T>* newNodo = new NodoBST<T>(dato);
    if (this->raiz == nullptr)
        this->raiz = newNodo;
    else {
        NodoBST<T>* aux = raiz;
        NodoBST<T>* padre = nullptr;
        int result;

        while (aux != nullptr) {
            result = aux->compareTo(dato);

            switch (result) {
            case 0:{
                return nullptr;
                break;
            }
            case 1: {
                padre = aux;
                aux = aux->getDer();
                break;
            }
            case -1: {
                padre = aux;
                aux = aux->getIzq();
            }
            default:
                break;
            }
        }
        if (result == 1)
            padre->setDer(newNodo);
        else
            padre->setIzq(newNodo);
    }
    return newNodo;
}

template <class T>
NodoBST<T>* BST<T>::search(T dato) {

    NodoBST<T>* aux = raiz;

    while (aux != nullptr) {
        int result = aux->compareTo(dato);

        switch (result) {
        case 0:{
            return aux;
            break;
        }
        case 1: {
            aux = aux->getDer();
            break;
        }
        case -1: {
            aux = aux->getIzq();
            break;
        }
        default:
            break;
        }
    }
    return nullptr;
}
