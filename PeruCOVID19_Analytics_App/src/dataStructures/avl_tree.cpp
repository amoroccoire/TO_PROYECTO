#include "../../includes/dataStructures/avl_tree.h"
#include <iostream>

// Constructor
template <typename T>
AVLTree<T>::AVLTree() : root(nullptr) {}

// Destructor
template <typename T>
AVLTree<T>::~AVLTree() {
    clear(root);
}

// Insertar un elemento en el árbol
template <typename T>
void AVLTree<T>::insert(const T &data) {
    root = insert(root, data);
}

// Eliminar un elemento del árbol
template <typename T>
void AVLTree<T>::remove(const T &data) {
    root = remove(root, data);
}

// Imprimir en orden
template <typename T>
void AVLTree<T>::printInOrder() const {
    printInOrder(root);
    std::cout << std::endl;
}

// Obtener la altura de un nodo
template <typename T>
int AVLTree<T>::height(Node<T> *node) const {
    return (node == nullptr) ? 0 : node->height;
}

// Obtener el factor de equilibrio de un nodo
template <typename T>
int AVLTree<T>::balanceFactor(Node<T> *node) const {
    return (node == nullptr) ? 0 : height(node->left) - height(node->right);
}

// Rotación a la derecha
template <typename T>
Node<T> *AVLTree<T>::rotateRight(Node<T> *y) {
    Node<T> *x = y->left;
    Node<T> *T2 = x->right;

    x->right = y;
    y->left = T2;

    y->height = std::max(height(y->left), height(y->right)) + 1;
    x->height = std::max(height(x->left), height(x->right)) + 1;

    return x;
}

// Rotación a la izquierda
template <typename T>
Node<T> *AVLTree<T>::rotateLeft(Node<T> *x) {
    Node<T> *y = x->right;
    Node<T> *T2 = y->left;

    y->left = x;
    x->right = T2;

    x->height = std::max(height(x->left), height(x->right)) + 1;
    y->height = std::max(height(y->left), height(y->right)) + 1;

    return y;
}

// Insertar un elemento en el árbol (método privado)
template <typename T>
Node<T> *AVLTree<T>::insert(Node<T> *node, const T &data) {
    if (node == nullptr)
        return new Node<T>{data, nullptr, nullptr, 1};

    if (data < node->data)
        node->left = insert(node->left, data);
    else if (data > node->data)
        node->right = insert(node->right, data);
    else
        return node; // Duplicates are not allowed

    node->height = 1 + std::max(height(node->left), height(node->right));

    int balance = balanceFactor(node);

    // Left Left Case
    if (balance > 1 && data < node->left->data)
        return rotateRight(node);

    // Right Right Case
    if (balance < -1 && data > node->right->data)
        return rotateLeft(node);

    // Left Right Case
    if (balance > 1 && data > node->left->data) {
        node->left = rotateLeft(node->left);
        return rotateRight(node);
    }

    // Right Left Case
    if (balance < -1 && data < node->right->data) {
        node->right = rotateRight(node->right);
        return rotateLeft(node);
    }

    return node;
}

// Eliminar un elemento del árbol (método privado)
template <typename T>
Node<T> *AVLTree<T>::remove(Node<T> *node, const T &data) {
    if (node == nullptr)
        return node;

    if (data < node->data)
        node->left = remove(node->left, data);
    else if (data > node->data)
        node->right = remove(node->right, data);
    else {
        if (node->left == nullptr || node->right == nullptr) {
            Node<T> *temp = (node->left != nullptr) ? node->left : node->right;

            if (temp == nullptr) {
                temp = node;
                node = nullptr;
            } else
                *node = *temp;

            delete temp;
        } else {
            Node<T> *temp = minValueNode(node->right);
            node->data = temp->data;
            node->right = remove(node->right, temp->data);
        }
    }

    if (node == nullptr)
        return node;

    node->height = 1 + std::max(height(node->left), height(node->right));

    int balance = balanceFactor(node);

    // Left Left Case
    if (balance > 1 && balanceFactor(node->left) >= 0)
        return rotateRight(node);

    // Left Right Case
    if (balance > 1 && balanceFactor(node->left) < 0) {
        node->left = rotateLeft(node->left);
        return rotateRight(node);
    }

    // Right Right Case
    if (balance < -1 && balanceFactor(node->right) <= 0)
        return rotateLeft(node);

    // Right Left Case
    if (balance < -1 && balanceFactor(node->right) > 0) {
        node->right = rotateRight(node->right);
        return rotateLeft(node);
    }

    return node;
}

// Encontrar el nodo con el valor mínimo (método privado)
template <typename T>
Node<T> *AVLTree<T>::minValueNode(Node<T> *node) {
    Node<T> *current = node;

    while (current->left != nullptr)
        current = current->left;

    return current;
}

// Imprimir en orden (método privado)
template <typename T>
void AVLTree<T>::printInOrder(Node<T> *node) const {
    if (node != nullptr) {
        printInOrder(node->left);
        std::cout << node->data << " ";
        printInOrder(node->right);
    }
}

// Limpiar el árbol (método privado)
template <typename T>
void AVLTree<T>::clear(Node<T> *node) {
    if (node != nullptr) {
        clear(node->left);
        clear(node->right);
        delete node;
    }
}

template <typename T>
bool AVLTree<T>::search(Node<T> *node, const T &data) const {
    if (node == nullptr)
        return false;

    if (data == node->data)
        return true;
    else if (data < node->data)
        return search(node->left, data);
    else
        return search(node->right, data);
}


// Expansión explícita de la plantilla para int y std::string
template class AVLTree<int>;

