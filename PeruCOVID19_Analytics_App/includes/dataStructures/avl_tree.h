#ifndef AVL_TREE_H
#define AVL_TREE_H

#include <iostream>
#include <string>

template <typename T>
struct Node {
    T data;
    Node<T> *left;
    Node<T> *right;
    int height;
};

template <typename T>
class AVLTree {
public:
    AVLTree();
    ~AVLTree();

    void insert(const T &data);
    void remove(const T &data);
    void printInOrder() const;
    bool search(const T &data) const;

private:
    Node<T> *root;

    int height(Node<T> *node) const;
    int balanceFactor(Node<T> *node) const;
    Node<T> *rotateRight(Node<T> *y);
    Node<T> *rotateLeft(Node<T> *x);
    Node<T> *insert(Node<T> *node, const T &data);
    Node<T> *remove(Node<T> *node, const T &data);
    Node<T> *minValueNode(Node<T> *node);
    void printInOrder(Node<T> *node) const;
    void clear(Node<T> *node);

    // Función privada utilizada para realizar la búsqueda
    bool search(Node<T> *node, const T &data) const;
};

// Implementación de la función search
template <typename T>
bool AVLTree<T>::search(const T &data) const {
    return search(root, data);
}

#endif // AVL_TREE_H
