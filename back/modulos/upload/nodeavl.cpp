#include "nodeavl.h"

NodeAVL::NodeAVL() {
    this->key = nullptr;
    this->right = nullptr;
    this->left = nullptr;
}

NodeAVL::NodeAVL(PruebaCovid *prueba) {
    this->key = prueba;
    this->right = nullptr;
    this->left = nullptr;
}

void NodeAVL::setLeft(NodeAVL *nodo) {
    this->left = nodo;
}

void NodeAVL::setRight(NodeAVL *nodo) {
    this->right = nodo;
}

void NodeAVL::setKey(PruebaCovid *prueba) {
    this->key = prueba;
}

void NodeAVL::setHeight(int val) {
    this->height = val;
}

NodeAVL* NodeAVL::getLeft() {
    return this->left;
}

NodeAVL* NodeAVL::getRight() {
    return this->right;
}

PruebaCovid* NodeAVL::getKey() {
    return this->key;
}

int NodeAVL::getHeight() {
    return this->height;
}

int NodeAVL::compareTo(PruebaCovid* prueba2) {
    if (this->key->getUuid() == prueba2->getUuid())
        return 0;
    else if (this->key->getUuid() < prueba2->getUuid())
        return -1;

    return 1;
}
