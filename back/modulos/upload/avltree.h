#ifndef AVLTREE_H
#define AVLTREE_H

#include "nodeavl.h"
#include <QString>
#include "../../../shared/DoubleLinkedList/doublelinkedlist.cpp";
#pragma once

class AVLTree {
public:
    AVLTree();

    void insert(PruebaCovid*);
    PruebaCovid* search(PruebaCovid*);

    DoubleLinkedList<QString, PruebaCovid*>* inorder();

private:
    NodeAVL* root;
    NodeAVL* insert(NodeAVL*, PruebaCovid*);
    NodeAVL* rightRotate(NodeAVL*);
    NodeAVL* leftRotate(NodeAVL*);
    int height(NodeAVL*);
    int getBalance(NodeAVL*);
    NodeAVL* search(NodeAVL*, PruebaCovid*);

    void inorderHelper(NodeAVL*, DoubleLinkedList<QString, PruebaCovid*>*);
};

#endif // AVLTREE_H
