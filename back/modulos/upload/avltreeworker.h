#ifndef AVLTREEWORKER_H
#define AVLTREEWORKER_H

#include <QObject>
#include <QString>
#include "../../../shared/DoubleLinkedList/doublelinkedlist.cpp"
#pragma once
#include "avltree.h"

class AVLTreeWorker : public QObject {
    Q_OBJECT
public:
    AVLTreeWorker(const QString& filename, long startLine, long numLines);
    void process();
    DoubleLinkedList<QString, PruebaCovid*>* getLista();
    AVLTree* getTree();

signals:
    void finished(AVLTreeWorker* worker);

private:
    AVLTree* avlTree;
    DoubleLinkedList<QString, PruebaCovid*>* lista;
    QString filename;
    long startLine;
    long numLines;
    PruebaCovid* extractKeyFromLine(QStringList& line);

};

#endif // AVLTREEWORKER_H
