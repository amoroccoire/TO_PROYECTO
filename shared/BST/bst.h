#ifndef BST_H
#define BST_H

#include "nodobst.h"

template <class T>
class BST {
public:
    BST();
    BST(T);
    NodoBST<T>* insert(T);
    NodoBST<T>* search(T);

private:
    NodoBST<T>* raiz;
};

#endif // BST_H
