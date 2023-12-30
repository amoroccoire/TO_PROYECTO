#ifndef NODEAVL_H
#define NODEAVL_H

#include "../search/domain/pruebacovid.h"

class NodeAVL {
public:
    NodeAVL();
    NodeAVL(PruebaCovid*);

    void setLeft(NodeAVL*);
    void setRight(NodeAVL*);
    void setKey(PruebaCovid*);
    void setHeight(int);

    NodeAVL* getLeft();
    NodeAVL* getRight();
    PruebaCovid* getKey();
    int getHeight();

    int compareTo(PruebaCovid*);

private:
    PruebaCovid* key;
    NodeAVL* left;
    NodeAVL* right;
    int height;
};

#endif // NODEAVL_H
