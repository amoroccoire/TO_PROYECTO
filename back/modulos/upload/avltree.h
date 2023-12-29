#ifndef AVLTREE_H
#define AVLTREE_H

#include "nodeavl.h"

class AVLTree {
public:
    AVLTree();

    void insert(PruebaCovid*);
    PruebaCovid* search(PruebaCovid*);

private:
    NodeAVL* root;
    NodeAVL* insert(NodeAVL*, PruebaCovid*);
    NodeAVL* rightRotate(NodeAVL*);
    NodeAVL* leftRotate(NodeAVL*);
    int height(NodeAVL*);
    int getBalance(NodeAVL*);
    NodeAVL* search(NodeAVL*, PruebaCovid*);
};

#endif // AVLTREE_H
