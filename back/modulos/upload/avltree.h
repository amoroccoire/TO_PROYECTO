#ifndef AVLTREE_H
#define AVLTREE_H

#include "nodeavl.h"
#include <QString>
#include "../../../shared/DoubleLinkedList/doublelinkedlist.cpp";
#include <vector>
#pragma once

class AVLTree {
public:
    AVLTree();

    void insert(PruebaCovid*);
    PruebaCovid* search(PruebaCovid*);

    std::vector<PruebaCovid*> inorder();

private:
    NodeAVL* root;
    NodeAVL* insert(NodeAVL*, PruebaCovid*);
    NodeAVL* rightRotate(NodeAVL*);
    NodeAVL* leftRotate(NodeAVL*);
    int height(NodeAVL*);
    int getBalance(NodeAVL*);
    NodeAVL* search(NodeAVL*, PruebaCovid*);

    void inorderHelper(NodeAVL*, std::vector<PruebaCovid*>&);
};

#endif // AVLTREE_H
