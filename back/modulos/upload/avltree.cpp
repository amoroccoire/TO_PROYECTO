#include "avltree.h"

AVLTree::AVLTree() {
    root = nullptr;
}

void AVLTree::insert(PruebaCovid *prueba) {
    root = insert(root, prueba);
}


PruebaCovid* AVLTree::search(PruebaCovid *prueba) {
    return search(root, prueba);
}

NodeAVL* AVLTree::insert(NodeAVL *node, PruebaCovid *prueba) {
    if (node == nullptr) {
        return new NodeAVL(prueba);
    }

    if (prueba->getUuid() < node->getKey()->getUuid()) {
        node->setLeft(insert(node->getLeft(), prueba));
    } else if (prueba->getUuid() > node->getKey()->getUuid()) {
        node->setRight(insert(node->getRight(), prueba));
    } else {
        return node;
    }

    node->getHeight() = 1 + std::max(height(node->getLeft()), height(node->getRight()));

    int balance = getBalance(node);
    if (balance > 1 && prueba->getUuid() < node->getLeft()->getKey()->getUuid()) {
        return rightRotate(node);
    }
    if (balance < -1 && prueba->getUuid() > node->getRight()->getKey()->getUuid()) {
        return leftRotate(node);
    }
    if (balance > 1 && prueba->getUuid() > node->getLeft()->getKey()->getUuid()) {
        node->setLeft(leftRotate(node->getLeft()));
        return rightRotate(node);
    }
    if (balance < -1 && prueba->getUuid() < node->getRight()->getKey()->getUuid()) {
        node->setRight(rightRotate(node->getRight());
        return leftRotate(node);
    }

    return node;
}

NodeAVL* AVLTree::rightRotate(NodeAVL *y) {
    NodeAVL* x = y->getLeft();
    NodeAVL* T2 = x->getRight();

    x->setRight(y);
    y->setLeft(T2);

    y->setHeight(std::max(height(y->getLeft()), height(y->getRight()))+1);
    x->setHeight(std::max(height(x->getLeft()), height(x->getRight())) + 1);

    return x;
}

NodeAVL* AVLTree::leftRotate(NodeAVL *x) {
    NodeAVL* y = x->getRight();
    NodeAVL* T2 = y->getLeft();

    y->setLeft(x);
    x->setRight(T2);

    x->setHeight(std::max(height(x->getLeft()), height(x->getRight())) + 1);
    y->setHeight(std::max(height(y->getLeft()), height(y->getRight())) + 1);

    return y;
}

int AVLTree::height(NodeAVL *N) {
    if (N == nullptr) {
        return 0;
    }
    return N->getHeight();
}

int AVLTree::getBalance(NodeAVL *N) {
    if (N == nullptr) {
        return 0;
    }
    return height(N->getLeft()) - height(N->getRight());
}

NodeAVL* AVLTree::search(NodeAVL* root, PruebaCovid* key) {
    if (root == nullptr || root->getKey()->getUuid() == key->getUuid()) {
        return root;
    }

    if (root->getKey()->getUuid() < key->getUuid()) {
        return search(root->getRight(), key);
    }

    return search(root->getLeft(), key);
}
